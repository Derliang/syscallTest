#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include "utility.h"
/*
struct stat {
    dev_t st_dev;     // ID of device containing file //
    ino_t st_ino;     // inode number //
    mode_t st_mode;    // protection //
    nlink_t st_nlink;   // number of hard links //
    uid_t st_uid;     // user ID of owner //
    gid_t st_gid;     // group ID of owner //
    dev_t st_rdev;    // device ID (if special file) //
    off_t st_size;    // total size, in bytes //
    blksize_t st_blksize; // blocksize for filesystem I/O //
    blkcnt_t st_blocks;  // number of 512B blocks allocated //
    time_t st_atime;   // time of last access //
    time_t st_mtime;   // time of last modification //
    time_t st_ctime;   // time of last status change //
}*/

//what is inode
//
//
void testStatInfo() {
    struct stat buf;
    char pwd[256];
    if (!getcwd(pwd, sizeof(pwd))) {
        Dlog("get pwd failed");
    }
    printf("%s\n",pwd);

    char fileName[] = "../../data/stat/case1/stat_st_dev";
    if (stat(fileName, &buf)) {
        Dlog("stat failed");
    }

    printf("fileName %s: dev major ID = %d, minor ID = %d\n major ID is identifying the class of the device, minor ID is identifying a specific instance of a device in that class \n", fileName, major(buf.st_dev), minor(buf.st_dev));
    printf("file size %ld\n", buf.st_size);
    printf("file last access time%d %d ",buf.st_atim.tv_sec, buf.st_atim.tv_nsec );
    printTime(&buf.st_atim);
    printf("file last change time  like chmod blabla%d %d ",buf.st_atim.tv_sec, buf.st_atim.tv_nsec );
    printTime(&buf.st_ctim);
    printf("file last modification time%d %d ",buf.st_atim.tv_sec, buf.st_atim.tv_nsec );
    printTime(&buf.st_mtim);

    //uid git mode
    printf("Mode :%lo  first two number indicate file type, the last four number show file mode like write read execute and so on\n", (unsigned long) buf.st_mode);
    printf("Uid: %ld, GID %ld //you can use command #cat /etc/passwd |grep root see root uid gid\n", (long)buf.st_uid, (long)buf.st_gid);
    printf("IO block %ld  size, that means each block have \n", (long)buf.st_blksize);
    printf("how many blocks: %lld\n", (long long )buf.st_blocks);

    printf("file type:   ");
    switch (buf.st_mode & S_IFMT) {
        case S_IFBLK:
            printf("block device\n");
            break;
        case S_IFREG:
            printf("regular file\n");
            break;
        case S_IFDIR:
            printf("dir\n");
            break;
        case S_IFCHR:
            printf("character device\n");
            break;
        case S_IFIFO:
            printf("fifo pipe\n");
            break;
        case S_IFLNK:
            printf("sym link\n");
            break;
        case S_IFSOCK:
            printf("socket\n");
            break;
        default:
            printf("unknown file\n");;
            break;
    }

}





void testAllCase() {
//    testStDev();
    testStatInfo();
}


// please read this chinese article about inode
// https://blog.csdn.net/xuz0917/article/details/79473562
int main () {
    testAllCase();
}

