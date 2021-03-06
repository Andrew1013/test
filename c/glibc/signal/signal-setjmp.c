/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:22 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:29 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:00 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:13 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:51 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
#include <signal.h>
#include <setjmp.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//伪代码伪代码伪代码伪代码伪代码伪代码伪代码伪代码伪代码伪代码伪代码

jmp_buf return_to_top_level;

volatile sig_atomic_t waiting_for_input;


void sigint_handler (int signum)
{
    printf("%s\n", __func__);
    exit(1);
}


void do_command (void)
{
    printf("%s\n", __func__);

    longjmp (return_to_top_level, 1);
}

int main (void)
{
    signal (SIGINT, sigint_handler);

    while (1) 
    {
        if (setjmp (return_to_top_level))
            puts ("Back at main loop....");
        else
            do_command ();
    }
    
    while(1);
}
