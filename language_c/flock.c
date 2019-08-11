#include <sys/file.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <argp.h>
#include <sys/syscall.h>
syscall(SYS_read, )
/**
 * this function just show how to use flock syscall.
 * detail info you should to see shell commond #man 2 flock
 * flow
 * 1 fork child process, then child process sleep for 500ms
 * 2 father process check if dir exist, or create dir
 * 2 father process check if file exist then open it ,or create file
 * 3 father process flock operation.
 * 4 father process wait child process died.
 * 5 child process  flock the same file descriptor see what happen!
 * 6 child finish and died.
 * 7 father process go on or return
 *
 * LOCK_SH
 * if one process set flock operation LOCK_SH success, other process
 * can only set LOCK_SH operation. if set LOCK_EX at the same time ,it will failed.
 *
 * @name flockTest
 * @param father_operationoperation father process flock operation
 * @param child_operation child process flock operation
 *
 */
void flockTest(int father_operation, int child_operation, int fatherSleepSecond) {
    // base idea
    // see man page flock(2)  #man 2 flock
    // step 1 create dir
    // step 2 create a file named "LOCK"
    // step 3 use flock  lock this file
    // step 4 start another new excutable file to flock the same file
    //        1) flock
    //        2)
    pid_t pid;
    static char fileName[] = "./log/LOCKFILE";
    char dirPath[] = "./log";
    struct stat dirStat, flockStat;
    memset(&dirStat, 0x00, sizeof(struct stat));


    pid = fork();
    if (pid < 0) {
        printf("fokr failed errno : %d\n", errno);
        exit(errno);
    } else if (pid == 0) {
        //child process
        usleep(500000);
        // open the file, it must exist
        int fd = open(fileName, O_RDWR, 0755);
        if (fd == -1) {
            printf("child process open  %s file failed\n errno :%d\n", fileName, errno);
            close(fd);
            exit(-1);
        }
        if ((child_operation & LOCK_NB) == LOCK_NB) {
            printf("child flock operation is unblock\n");
        } else {
            printf("child flock operation is block\n");
        }
        struct timeval start, end;
        gettimeofday(&start, NULL);


        if (flock(fd, child_operation) < 0) {
            gettimeofday(&end, NULL);
            close(fd);
            printf("lock again, so errno should be EAGAIN according to man page\n errno is %d\n", errno);
            exit(errno);
        }
        gettimeofday(&end, NULL);
        float time_use = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
        printf("time use %fn us\n", time_use);
        close(fd);
        exit(0);
    }

    int fd = -1;

    //father process
    if (!stat(dirPath, &dirStat)) {
        // path exist
        //
        if ((dirStat.st_mode & S_IFMT) != S_IFDIR) {
            printf("err, path name should be a dir\n");
            exit(errno);
        }

    } else {
        //dir is not exist
        printf("dir is not exists\n");
        //create dir
        if (mkdir(dirPath, 0755)) {
            printf("create dir failed errno%d\n", errno);
            exit(errno);
        }
    }

    memset(&flockStat, 0x00, sizeof(struct stat));

    //printf("check file if not exist, then create file: %s under dir:%s \n", fileName, dirPath);
    if (!stat(fileName, &flockStat)) {
        if ((flockStat.st_mode & S_IFMT) != S_IFREG) {
            printf("err, %s file already exists, but it is not regular file\n", fileName);
            exit(-1);
        }
        fd = open(fileName, O_RDWR, 0755);
        if (fd < 0) {
            printf("open file failed, errno: %d\n", errno);
            exit(errno);
        }
    } else {
        fd = creat(fileName, 0755);
        if (fd == -1) {
            printf("create %s file failed, errno is :%d\n", fileName, errno);
            exit(errno);
        }
    }

    // set file lock exclusive and nonblock
    if (flock(fd, father_operation) < 0) {
        printf("errno :%d\n if set LOCK_NB and errno is ", errno);
        close(fd);
        exit(errno);
    };

    printf("fahter porcess sleep %d seconds!\n", fatherSleepSecond);
    if(fatherSleepSecond>0) {
        sleep(5);
    }

    flock(fd, LOCK_UN);
    close(fd);
    wait(NULL);
    syscall(__NR)

}

void flockTestAllCase() {
    printf("testing---------------flockTest(LOCK_EX, LOCK_EX| LOCK_NB, 5)-----------------------------------\n\n");
    flockTest(LOCK_EX, LOCK_EX | LOCK_NB, 5);
    printf("you should see child return errno 11 ,because LOCK_EX  and LOCK_NB set, child can not get the lock \n\n\n");
    printf("testing---------------flockTest(LOCK_EX, LOCK_EX, 5)-----------------------------------\n\n");
    flockTest(LOCK_EX, LOCK_EX, 5);
    printf("you should see child wait several seconds, because father process hold the file lock LOCK_EX\n\n\n");
    printf("testing---------------flockTest(LOCK_SH, LOCK_SH, 5)-----------------------------------\n\n");
    flockTest(LOCK_SH, LOCK_SH, 5);
    printf("you should see child lock success and return imediately\n\n\n");
    printf("testing---------------flockTest(LOCK_SH, LOCK_SH|LOCK_NB, 5)-----------------------------------\n\n");
    flockTest(LOCK_SH, LOCK_SH | LOCK_NB, 5);
    printf("you should see child lock success and return imediately\n\n\n");

}


int main(int argc, char **argv) {
    flockTestAllCase();
}