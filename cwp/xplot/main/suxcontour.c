/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:52 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:52 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:36 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:09 CST. */
/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */

/* SUXCONTOUR: $Revision: 1.10 $ ; $Date: 2011/11/12 00:45:18 $		*/

#include "su.h"
#include "segy.h"
#include <signal.h>

/*********************** self documentation *****************************/
char *sdoc[] = {
"									",
" SUXCONTOUR - X CONTOUR plot of Seismic UNIX tracefile via vector plot call",
"									",
" suxwigb <stdin [optional parameters] | ...				",
"									",
" Optional parameters:						 	",
" key=(keyword)		if set, the values of x2 are set from header field",
"			specified by keyword				",
" n2=tr.ntr or number of traces in the data set	(ntr is an alias for n2)",
" d1=tr.d1 or tr.dt/10^6	sampling interval in the fast dimension	",
"   =.004 for seismic 		(if not set)				",
"   =1.0 for nonseismic		(if not set)				",
" d2=tr.d2			sampling interval in the slow dimension	",
"   =1.0 			(if not set)				",
" f1=tr.f1 or tr.delrt/10^3 or 0.0  first sample in the fast dimension	",
" f2=tr.f2 or tr.tracr or tr.tracl  first sample in the slow dimension	",
"   =1.0 for seismic		    (if not set)			",
"   =d2 for nonseismic		    (if not set)			",
"									",
" verbose=0              =1 to print some useful information		",
"									",
" tmpdir=	 	if non-empty, use the value as a directory path	",
"		 	prefix for storing temporary files; else if the	",
"	         	the CWP_TMPDIR environment variable is set use	",
"	         	its value for the path; else use tmpfile()	",
" 									",
" Note that for seismic time domain data, the \"fast dimension\" is	",
" time and the \"slow dimension\" is usually trace number or range.	",
" Also note that \"foreign\" data tapes may have something unexpected	",
" in the d2,f2 fields, use segyclean to clear these if you can afford	",
" the processing time or use d2= f2= to override the header values if	",
" not.									",
"									",
" If key=keyword is set, then the values of x2 are taken from the header",
" field represented by the keyword (for example key=offset, will show   ",
" traces in true offset). This permit unequally spaced traces to be plotted.",
" Type   sukeyword -o   to see the complete list of SU keywords.	",
"								       ",
" This program is really just a wrapper for the plotting program: xcontour",
" See the xcontour selfdoc for the remaining parameters.		",
"									",
NULL};

/*
 * Credits:
 *
 *	CWP: Dave Hale and Zhiming Li (xwigb, etc.)
 *	   Jack Cohen and John Stockwell (suxwigb, etc.)
 *      Delphi: Alexander Koek, added support for irregularly spaced traces
 *      Aarhus University: Morten W. Pedersen copied everything from the xwigb
 *                         source and just replaced all occurencies of the word
 *                         xwigb with xcountour ;-)
 *
 * Notes:
 *	When the number of traces isn't known, we need to count
 *	the traces for xcontour.  You can make this value "known"
 *	either by getparring n2 or by having the ntr field set
 *	in the trace header.  A getparred value takes precedence
 *	over the value in the trace header.
 *
 *	When we must compute ntr, we don't allocate a 2-d array,
 *	but just content ourselves with copying trace by trace from
 *	the data "file" to the pipe into the plotting program.
 *	Although we could use tr.data, we allocate a trace buffer
 *	for code clarity.
 */
/**************** end self doc *******************************************/

static void closefiles(void);

/* Globals (so can trap signal) defining temporary disk files	*/
char tracefile[BUFSIZ];	/* filename for trace storage file	*/
FILE *tracefp;		/* fp for trace storage file		*/
char x2file[BUFSIZ];	/* filename for positions file		*/
FILE *x2fp;		/* fp for positions file		*/

segy tr;

int
main(int argc, char **argv)
{
	char *plotcmd;		/* build xcontour command for popen	*/
	float *trbuf;		/* trace buffer				*/
	FILE *plotfp;		/* fp for plot data			*/
	int nt;			/* number of samples on trace	  	*/
	int ntr;		/* number of traces			*/
	int verbose;		/* verbose flag				*/
	float d1;		/* time/depth sample rate		*/
	float d2;		/* trace/dx sample rate			*/
	float f1;		/* tmin/zmin			   	*/
	float f2;		/* tracemin/xmin			*/
	cwp_Bool seismic;	/* is this seismic data?		*/
	cwp_Bool have_ntr=cwp_false;/* is ntr known from header or user?	*/
	char *tmpdir;		/* directory path for tmp files		*/
	cwp_Bool istmpdir=cwp_false;/* true for user given path		*/

	char *cwproot;		/* value of CWPROOT environment variable*/
	char *bindir;		/* directory path for tmp files		*/

	/* Support for irregularly spaced data */
	cwp_String key;		/* header key word with x2 information  */
	cwp_String type=NULL;	/* ... its type			 	*/
	int index=0;		/* ... its index			*/
	cwp_Bool irregular=cwp_false;  /* if true, reading x2 from header   */
	cwp_String x2string;    /* string of x2 values			*/
	off_t x2len;		/* ... its length			*/
	Value val;		/* value of key				*/


	/* Initialize */
	initargs(argc, argv);
	requestdoc(1);

	/* Get info from first trace */
	if (!gettr(&tr)) err("can't get first trace");
	seismic = ISSEISMIC(tr.trid);
	nt = tr.ns;
	ntr = tr.ntr;
	if (ntr) have_ntr = cwp_true;

	if (!getparint("verbose", &verbose))    verbose=0;
	if (!getparfloat("d1", &d1)) {
		if      (tr.d1)  d1 = tr.d1;
		else if (tr.dt)  d1 = ((double) tr.dt)/1000000.0;
		else {
			if (seismic) {
				d1 = 0.004;
				warn("tr.dt not set, assuming dt=0.004");
			} else { /* non-seismic data */
				d1 = 1.0;
				warn("tr.d1 not set, assuming d1=1.0");
			}
		}
	}

	/* Get or set ntr */
	if (getparint("n2", &ntr) || getparint("ntr", &ntr)) have_ntr = cwp_true;
	if (!getparfloat("d2", &d2)) d2 = (tr.d2) ? tr.d2 : 1.0;

	if (!getparfloat("f1", &f1)) {
		if      (tr.f1)     f1 = tr.f1;
		else if (tr.delrt)  f1 = (float) tr.delrt/1000.0;
		else		f1 = 0.0;
	}

	if (!getparfloat("f2", &f2)) {
		if	(tr.f2)	f2 = tr.f2;
		else if (tr.tracr)  f2 = (float) tr.tracr;
		else if (tr.tracl)  f2 = (float) tr.tracl;
		else if (seismic)   f2 = 1.0;
		else		f2 = 0.0;
	}


	if (getparstring("key", &key)) {
		type = hdtype(key);
		index = getindex(key);
		if ( (index = getindex(key)) == -1 )
			err("%s: keyword not in segy.h: '%s'", __FILE__, key);

		irregular = cwp_true;
	}


	/* Look for user-supplied tmpdir */
	if (!getparstring("tmpdir",&tmpdir) &&
	    !(tmpdir = getenv("CWP_TMPDIR"))) tmpdir="";
	if (!STREQ(tmpdir, "") && access(tmpdir, WRITE_OK))
		err("you can't write in %s (or it doesn't exist)", tmpdir);

	/* See if CWPBIN environment variable is not set */
	if (!(bindir = getenv("CWPBIN"))) { /* construct bindir from CWPROOT */

		bindir = (char *) emalloc(BUFSIZ);

		/* Get value of CWPROOT environment variable */
		if (!(cwproot = getenv("CWPROOT"))) cwproot ="" ;
		if (STREQ(cwproot, "")) {
			warn("CWPROOT environment variable is not set! ");
			err("Set CWPROOT in shell environment as per instructions in CWP/SU Installation README files");
		}
		/* then bindir = $CWPROOT/bin */
		sprintf(bindir, "%s/bin", cwproot);
	}
	strcat(bindir,"/");   /* put / at the end of bindir */

	/* Allocate trace buffer */
	trbuf = ealloc1float(nt);


	if (!have_ntr || irregular) { /* count traces */

		if (verbose) {
	       		if (irregular) {
				warn("trace spacing from header field %s",key);
				warn("... getting positions");
			} else {
				warn("n2 not getparred and ntr header field"
				     " not set");
				warn("....  counting traces");
			}
		}

		/* Create temporary "file" to hold data */
		if (STREQ(tmpdir,"")) {
			tracefp = etmpfile();
			if (irregular) x2fp = etmpfile();
			if (verbose) warn("using tmpfile() call");
		} else { /* user-supplied tmpdir */
			char directory[BUFSIZ];
			strcpy(directory, tmpdir);
			strcpy(tracefile, temporary_filename(directory));
			strcpy(x2file, temporary_filename(directory));
			/* Handle user interrupts */
			signal(SIGINT, (void (*) (int)) closefiles);
			signal(SIGQUIT, (void (*) (int)) closefiles);
			signal(SIGHUP,  (void (*) (int)) closefiles);
			signal(SIGTERM, (void (*) (int)) closefiles);
			tracefp = efopen(tracefile, "w+");
			if (irregular) x2fp = efopen(x2file, "w+");
			istmpdir=cwp_true;
			if (verbose)
			      warn("putting temporary files in %s", directory);
		}


		/* Loop over input data and read to temporary file */
		ntr = 0;
		if(irregular ) {
			float xmin=FLT_MAX,xmax=-FLT_MAX;

			fprintf(x2fp,"x2=");
			do {
				if(ntr) fprintf(x2fp,",");
				++ntr;
				gethval(&tr,index,&val);
				fprintfval(x2fp,type,val);
				xmin = MIN(xmin,vtof(type,val));
				xmax = MAX(xmax,vtof(type,val));
				efwrite(tr.data, FSIZE, nt, tracefp);
			} while (gettr(&tr));

			if(xmin==xmax) {
				warn("values in header %s all equal,",key);
				warn("using f2=%f d2=%f",f2,d2);
				irregular=cwp_false;
				have_ntr=cwp_false;
				efclose(x2fp);
			}

		} else {

			do {
				++ntr;
				efwrite(tr.data, FSIZE, nt, tracefp);
			} while (gettr(&tr));

		}

	}

	/* Set up xcontour command line */
	if (irregular ) {
		x2len = (off_t) eftell( x2fp );
		x2string = (char *) emalloc( ++x2len );
		rewind(x2fp);
		fread(x2string,sizeof(char),x2len,x2fp);
		plotcmd = (char *) emalloc(x2len+BUFSIZ);
/* suxcontour.c:281: warning: unsigned int format, pointer arg (arg 1) */
		sprintf(plotcmd, "%sxcontour n1=%d d1=%f f1=%f %s", bindir,
			   nt, d1, f1, x2string);
		free(x2string);
	} else {
		plotcmd = (char *) emalloc(BUFSIZ);
		sprintf(plotcmd,
			"%sxcontour n1=%d n2=%d d1=%f d2=%f f1=%f f2=%f", bindir,
			   nt, ntr, d1, d2, f1, f2);
	}


	for (--argc, ++argv; argc; --argc, ++argv) {
		if (strncmp(*argv, "d1=", 3) && /* skip those already set */
		    strncmp(*argv, "d2=", 3) &&
		    strncmp(*argv, "f1=", 3) &&
		    strncmp(*argv, "f2=", 3)) {

			strcat(plotcmd, " ");   /* put a space between args */
			strcat(plotcmd, "\"");  /* user quotes are stripped */
			strcat(plotcmd, *argv); /* add the arg */
			strcat(plotcmd, "\"");  /* user quotes are stripped */
		}
	}


	/* Open pipe to xcontour and send the traces */
	plotfp = epopen(plotcmd, "w");
	free(plotcmd);


	if (!have_ntr || irregular) { /* send out stored traces one by one */
		rewind(tracefp);
		{ register int itr;
			for (itr = 0; itr < ntr; ++itr) {
				efread (trbuf, FSIZE, nt, tracefp);
				efwrite(trbuf, FSIZE, nt, plotfp);
			}
		}
	} else { /* just pump out traces and let xcontour do the work */
		do {
			efwrite(tr.data, FSIZE, nt, plotfp);
		} while (gettr(&tr));
	}


	/* Clean up */
	epclose(plotfp);
	if (!have_ntr) {
		efclose(tracefp);
		if (istmpdir) eremove(tracefile);
	}
	if (irregular) {
		efclose(x2fp);
		if (istmpdir) eremove(x2file);
	}

	return EXIT_SUCCESS;
}

/* for graceful interrupt termination */
static void closefiles(void)
{
	efclose(tracefp);
	eremove(tracefile);
	efclose(x2fp);
	eremove(x2file);
	exit(EXIT_FAILURE);
}
