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
    char buf[2048];
    strcpy(buf, msg);
    strstr(buf, "\n errno is%d ,error message %s");

    va_list va;
    va_start(va, msg);
    printf(buf , va, errno, strerror(errno));
    va_end(va);
    exit(errno);
}