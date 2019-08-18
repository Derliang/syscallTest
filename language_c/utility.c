//
// Created by sensetime on 2019/8/18.
//

#include "utility.h"
#include <stdarg.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Dlog(char *msg, ...) {
    char buf[2048] ={0x00};
    strcpy(buf, msg);

    va_list va;
    va_start(va, msg);
    vsprintf(buf , msg, va);
    va_end(va);
    printf(buf);
    printf("\nerrno is %d ,error message: %s\n",errno, strerror(errno));
    exit(errno);
}