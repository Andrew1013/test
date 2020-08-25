/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:41 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:39 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:23 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:59 CST. */
/**
 *	互斥锁的属性
 */

#include <pthread.h>

/**
 *	互斥锁属性的初始化和摧毁函数
 */

int pthread_mutexattr_init(pthread_mutexattr_t *mptr);
int pthread_mutexattr_destory(pthread_mutexattr_t *mptr);
	//成功：返回0
	//错误：-1

int pthread_mutexattr_getpshared(const pthread_mutexattr_t *attr,int *valptr);
int pthread_mutexattr_setpshared(pthread_mutexattr_t *attr,int value);
	//成功：返回0
	//错误：Exxx

