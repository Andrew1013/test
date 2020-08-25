/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 10月 09日 星期三 08:20:26 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:06 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:21 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:06 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:52 CST. */
#include <stdio.h>

#include "define.h"

#define VCM_MYSQL_MACS_TABLE "macs"

#define VCM_CREATE_MAC_INFO_TABLE \
	    "CREATE TABLE " VCM_MYSQL_MACS_TABLE "(" \
    "snmp_index integer,"\
    "pid integer,"\
    "status integer,"\
    "cfg_pth char(256),"\
    "ether char(16),"\
    "enb_ipaddr char(16),"\
    "gtpu_recv_addr char(16),"\
    "vbs_eth char(256),"\
    "sockfd integer)"

int main()
{
	printf("%s\n\n\n", VCM_CREATE_MAC_INFO_TABLE);
	printa();
	printb();
	return 0;
}
