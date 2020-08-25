/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 24日 星期一 08:52:25 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:19 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:28 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 09:02:19 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:59 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:12 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:50 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
/**
 *	pthread_join		P536
 *
 *	通过调用pthread_join等待一个给定线程终止，对比线程和UNIX进程，
 *	pthread_create类似于fork函数，
 *	pthread_join类似于waitpid函数
 *	
 *	以阻塞的形式等待一个线程的结束。
 */

#include <pthread.h>

int pthread_join(pthread_t *tid, void **status);
/**
 *  pthread_join 作为返回
 *
 *      荣涛 2018.10.16
 */
int pthread_join(pthread_t *tid, void **retval);
/**
 * 参数：
 * 		tid：线程ID
 * 		status：用户定义的指针，用来存储被等待线程的返回值。
 *
 *
 *	返回：
 *		成功：0
 *		错误：正的Exxx值
 */

int main ()
{
	pthread_t thread1_id;
	pthread_t thread2_id;
	struct char_print_parms thread1_args;
	struct char_print_parms thread2_args;
	/* Create a new thread to print 30,000 x's. */
	thread1_args.character = 'x';
	thread1_args.count = 30000;
	pthread_create (&thread1_id, NULL, &char_print, &thread1_args);
	/* Create a new thread to print 20,000 o's. */
	thread2_args.character = 'o';
	thread2_args.count = 20000;
	pthread_create (&thread2_id, NULL, &char_print, &thread2_args);
	/* Make sure the first thread has finished. */
	pthread_join (thread1_id, NULL);
	/* Make sure the second thread has finished. */
	pthread_join (thread2_id, NULL);
	/* Now we can safely return. */
	return 0;
}
