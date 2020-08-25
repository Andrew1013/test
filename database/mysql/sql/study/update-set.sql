/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:56 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:54 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 16:09:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 15:51:33 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 15:38:56 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 13:59:12 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 13:23:25 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 11:24:37 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 11:09:05 CST. */


use custome;

update customer set title = 'Mr' where fname = 'Bill';

update customer set addressline='Sylincom',lname='O\'Neill' where fname = 'Bill';
/*
|          14 | Mr    | Bill      | O'Neill | Sylincom         | Welltown  | WT3 8GM  | 435 1234 |
|          15 | Mr    | David     | Hudson  | 4 The Square     | Milltown  | MT2 6RT  | 961 4526 |
|          16 | Mr    | Bill      | O'Neill | Sylincom         | NULL      |          | NULL     |
|          17 | Mr    | Bill      | O'Neill | Sylincom         | NULL      |          | NULL     |
|          18 | Mr    | Bill      | O'Neill | Sylincom         | NULL      |          | NULL     |
+-------------+-------+-----------+---------+------------------+-----------+----------+----------
*/


