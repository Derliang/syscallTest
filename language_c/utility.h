//
// Created by sensetime on 2019/8/18.
//

#ifndef SYSCALLTEST_UTILITY_H
#define SYSCALLTEST_UTILITY_H
#include <time.h>

extern void Dlog(char *msg, ...);

extern void printTime(struct timespec *tm);

#endif //SYSCALLTEST_UTILITY_H
