/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:17 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:26 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:57 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:43:21 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:11 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:56 CST. */
/*
 *	struct protoent * getprotobynumber (int protocol) [Function]
 *	The getprotobynumber function returns information about the network protocol with
 *	number protocol. If there is no such protocol, it returns a null pointer.
 */
#include <stdio.h>
#include <netdb.h>

int main()
{
	struct protoent *pro;

	pro = getprotobynumber(1);
	printf("name: 		%s\n", pro->p_name);
	printf("number:		%d\n", pro->p_proto);
	printf("alias:		%s\n", pro->p_aliases[0]);
	printf("alias:		%s\n", pro->p_aliases[1]);
	printf("alias:		%s\n", pro->p_aliases[2]);


	pro = getprotobynumber(17);
	printf("name: 		%s\n", pro->p_name);
	printf("number:		%d\n", pro->p_proto);
	printf("alias:		%s\n", pro->p_aliases[0]);
	printf("alias:		%s\n", pro->p_aliases[1]);
	printf("alias:		%s\n", pro->p_aliases[2]);
	

	pro = getprotobynumber(3);
	printf("name: 		%s\n", pro->p_name);
	printf("number:		%d\n", pro->p_proto);
	printf("alias:		%s\n", pro->p_aliases[0]);
	printf("alias:		%s\n", pro->p_aliases[1]);
	printf("alias:		%s\n", pro->p_aliases[2]);
	

	return 1;
}
