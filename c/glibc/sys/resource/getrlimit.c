/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:28 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:32 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:03 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:16 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:59 CST. */
/*
int getrlimit (int resource, struct rlimit *rlp) [Function]
Read the current and maximum limits for the resource resource and store them in
*rlp.
The return value is 0 on success and -1 on failure. The only possible errno error
condition is EFAULT.
When the sources are compiled with _FILE_OFFSET_BITS == 64 on a 32-bit system
this function is in fact getrlimit64. Thus, the LFS interface transparently replaces
the old interface.


*/

#include <sys/resource.h>
#include <stdio.h>


// struct rlimit{
    // rlim_t  rlim_cur;
    // rlim_t  rlim_max;
// };

int main()
{
    struct rlimit rlimit;
    
    getrlimit(getpid(), &rlimit);

    printf("rlim_cur = %d\n", rlimit.rlim_cur);
    printf("rlim_max = %d\n", rlimit.rlim_max);
    
	return 0;
}