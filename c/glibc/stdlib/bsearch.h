/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */


#include <stdlib.h>

void *bsearch(const void *key, const void *base,
                  size_t nmemb, size_t size,
                  int (*compar)(const void *, const void *));
