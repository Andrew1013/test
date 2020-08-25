/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:33 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:34 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:06 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:18 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:55 CST. */
/*

char * asctime (const struct tm *brokentime) [Function]
The asctime function converts the broken-down time value that brokentime points
to into a string in a standard format:
"Tue May 21 13:46:22 1991\n"
The abbreviations for the days of week are: ‘Sun’, ‘Mon’, ‘Tue’, ‘Wed’, ‘Thu’, ‘Fri’, and
‘Sat’.
The abbreviations for the months are: ‘Jan’, ‘Feb’, ‘Mar’, ‘Apr’, ‘May’, ‘Jun’, ‘Jul’,
‘Aug’, ‘Sep’, ‘Oct’, ‘Nov’, and ‘Dec’.
The return value points to a statically allocated string, which might be overwritten
by subsequent calls to asctime or ctime. (But no other library function overwrites
the contents of this string.)


*/

#include <stdio.h>
#include <time.h>
#include <malloc.h>

int main()
{
    time_t time = 0;
    struct tm *t = localtime(&time);
    
    struct tm *t2;
    t2 = localtime_r(&time, t2);
    
    printf("tm_sec = %d:%d\n", t->tm_sec, t2->tm_sec);
    printf("tm_min = %d:%d\n", t->tm_min, t2->tm_min);
    printf("tm_hour = %d:%d\n", t->tm_hour, t2->tm_hour);
    printf("tm_mday = %d:%d\n", t->tm_mday, t2->tm_mday);
    printf("tm_mon = %d:%d\n", t->tm_mon, t2->tm_mon);
    printf("tm_year = %d:%d\n", t->tm_year, t2->tm_year);
    printf("tm_wday = %d:%d\n", t->tm_wday, t2->tm_wday);
    printf("tm_yday = %d:%d\n", t->tm_yday, t2->tm_yday);
    printf("tm_isdst = %d:%d\n", t->tm_isdst, t2->tm_isdst);
    printf("tm_gmtoff = %d:%d\n", t->tm_gmtoff, t2->tm_gmtoff);
    printf("tm_zone = %s:%s\n", t->tm_zone, t2->tm_zone);
    
    
    char *strtime = asctime(t2);
    
    printf("%s\n", strtime);
    
    
    char *strtime2 = malloc(256);
    
    strtime2 = asctime_r(t2, strtime2);
    
    printf("%s\n", strtime2);
    
    
    return 0;
}