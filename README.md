# SyscallTest 
    
    I am curious about the api, the operating system provide for programmers.

    This repo is just for someone who want learn syscall, 

    I will provide enough test sample for learn.

## before start
    
    I just only print errno, rather than the err message, you can check with man page to know 
    
    what it is.
    
## APIs

| function name  |      NR  | C          |  golang      |
|----------------|----------|------------|--------------|
|stat            | 4        |[stat.c](https://github.com/Derliang/syscallTest/blob/master/language_c/stat.c)       |  todo            |
|flock           |  73|[flock.c](https://github.com/Derliang/syscallTest/blob/master/language_c/flock.c)  |  todo |
|lstat           |6     | |
|__NR_poll | 7
|__NR_lseek |8
|__NR_mmap |9
|__NR_mprotect |10
|__NR_munmap |11
|__NR_brk |12
|__NR_rt_sigaction |13
|__NR_rt_sigprocmask| 14
|__NR_rt_sigreturn |15
|__NR_ioctl |16
|__NR_pread64 |17
|__NR_pwrite64 |18
|__NR_readv |19
|__NR_writev |20
|__NR_access |21
|__NR_pipe |22
|__NR_select |23
|__NR_sched_yield |24
|__NR_mremap |25
|__NR_msync |26
|__NR_mincore |27
|__NR_madvise |28
|__NR_shmget |29
|__NR_shmat |30
|__NR_shmctl |31
|__NR_dup |32
|__NR_dup2 |33
|__NR_pause |34
|__NR_nanosleep |35
|__NR_getitimer |36
|__NR_alarm |37
|__NR_setitimer |38
|__NR_getpid |39
|__NR_sendfile |40
|__NR_socket |41
|__NR_connect |42
|__NR_accept |43
|__NR_sendto |44
|__NR_recvfrom |45
|__NR_sendmsg |46
|__NR_recvmsg |47
|__NR_shutdown |48
|__NR_bind |49
|__NR_listen |50
|__NR_getsockname| 51
|__NR_getpeername |52
|__NR_socketpair |53
|__NR_setsockopt |54
|__NR_getsockopt |55
|__NR_clone |56
|__NR_fork |57
|__NR_vfork |58
|__NR_execve |59
|__NR_exit |60
|__NR_wait4 |61
|__NR_kill |62
|__NR_uname |63
|__NR_semget |64
|__NR_semop |65
|__NR_semctl |66
|__NR_shmdt |67
|__NR_msgget |68
|__NR_msgsnd |69
|__NR_msgrcv |70
|__NR_msgctl |71
|__NR_fcntl |72
|__NR_flock |73
|__NR_fsync |74
|__NR_fdatasync |75
|__NR_truncate |76
|__NR_ftruncate |77
|__NR_getdents |78
|__NR_getcwd |79
|__NR_chdir |80
|__NR_fchdir |81
|__NR_rename |82
|__NR_mkdir |83
|__NR_rmdir |84
|__NR_creat| 85
|__NR_link |86
|__NR_unlink| 87
|__NR_symlink| 88
|__NR_readlink| 89
|__NR_chmod |90
|__NR_fchmod |91
|__NR_chown| 92
|__NR_fchown| 93
|__NR_lchown |94
|__NR_umask| 95
|__NR_gettimeofday| 96
|__NR_getrlimit |97
|__NR_getrusage |98
|__NR_sysinfo |99
|__NR_times |100
|__NR_ptrace |101
|__NR_getuid |102
|__NR_syslog |103
|__NR_getgid |104
|__NR_setuid |105
|__NR_setgid |106
|__NR_geteuid |107
|__NR_getegid |108
|__NR_setpgid |109
|__NR_getppid |110
|__NR_getpgrp |111
|__NR_setsid |112
|__NR_setreuid |113
|__NR_setregid |114
|__NR_getgroups |115
|__NR_setgroups |116
|__NR_setresuid |117
|__NR_getresuid |118
|__NR_setresgid |119
|__NR_getresgid |120
|__NR_getpgid |121
|__NR_setfsuid |122
|__NR_setfsgid| 123
|__NR_getsid |124
|__NR_capget |125
|__NR_capset| 126
|__NR_rt_sigpending |127
|__NR_rt_sigtimedwait| 1
|__NR_rt_sigqueueinfo |1
|__NR_rt_sigsuspend |130
|__NR_sigaltstack |131
|__NR_utime |132
|__NR_mknod |133
|__NR_uselib |134
|__NR_personality |135
|__NR_ustat |136
|__NR_statfs |137
|__NR_fstatfs |138
|__NR_sysfs |139
|__NR_getpriority |140
|__NR_setpriority| 141
|__NR_sched_setparam |14
|__NR_sched_getparam |14
|__NR_sched_setschedule|
|__NR_sched_getschedule|
|__NR_sched_get_priorit|
|__NR_sched_get_priorit|
|__NR_sched_rr_get_inte|
|__NR_mlock 149|
|__NR_munlock |150
|__NR_mlockall |151
|__NR_munlockall| 152
|__NR_vhangup| 153
|__NR_modify_ldt| 154
|__NR_pivot_root| 155
|__NR__sysctl |156
|__NR_prctl |157
|__NR_arch_prctl| 158
|__NR_adjtimex |159
|__NR_setrlimit| 160
|__NR_chroot |161
|__NR_sync |162
|__NR_acct |163
|__NR_settimeofday| 164
|__NR_mount |165
|__NR_umount2| 166
|__NR_swapon |167
|__NR_swapoff |168
|__NR_reboot |169
|__NR_sethostname |170
|__NR_setdomainname| 171
|__NR_iopl |172
|__NR_ioperm| 173
|__NR_create_module |174
|__NR_init_module |175
|__NR_delete_module |176
|__NR_get_kernel_syms| 1
|__NR_query_module| 178
|__NR_quotactl |179
|__NR_nfsservctl| 180
|__NR_getpmsg |181
|__NR_putpmsg |182
|__NR_afs_syscall |183
|__NR_tuxcall |184
|__NR_security |185
|__NR_gettid |186
|__NR_readahead |187
|__NR_setxattr |188
|__NR_lsetxattr |189
|__NR_fsetxattr |190
|__NR_getxattr |191
|__NR_lgetxattr |192
|__NR_fgetxattr |193
|__NR_listxattr |194
|__NR_llistxattr| 195
|__NR_flistxattr |196
|__NR_removexattr |197
|__NR_lremovexattr |198
|__NR_fremovexattr |199
|__NR_tkill |200
|__NR_time |201
|__NR_futex| 202
|__NR_sched_|
|__NR_set_thread_area |2
|__NR_io_setup |206
|__NR_io_destroy 207
|__NR_io_getevents 208
|__NR_io_submit 209
|__NR_io_cancel 210
|__NR_get_thread_area 2
|__NR_lookup_dcookie 21
|__NR_epoll_create 213
|__NR_epoll_ctl_old 214
|__NR_epoll_wait_old 21
|__NR_remap_file_pages 
|__NR_getdents64 217
|__NR_set_tid_address 2
|__NR_restart_syscall 2
|__NR_semtimedop 220
|__NR_fadvise64 221
|__NR_timer_create 222
|__NR_timer_settime 223
|__NR_timer_gettime 224
|__NR_timer_getoverrun 
|__NR_timer_delete 226
|__NR_clock_settime 227
|__NR_clock_gettime 228
|__NR_clock_getres 229
|__NR_clock_nanosleep 2
|__NR_exit_group 231
|__NR_epoll_wait 232
|__NR_epoll_ctl 233
|__NR_tgkill 234
|__NR_utimes 235
|__NR_vserver 236
|__NR_mbind 237
|__NR_set_mempolicy 238
|__NR_get_mempolicy 239
|__NR_mq_open 240
|__NR_mq_unlink 241
|__NR_mq_timedsend 242
|__NR_mq_timedreceive 2
|__NR_mq_notify 244
|__NR_mq_getsetattr 245
|__NR_kexec_load 246
|__NR_waitid 247
|__NR_add_key 248
|__NR_request_key 249
|__NR_keyctl 250
|__NR_ioprio_set 251
|__NR_ioprio_get 252
|__NR_inotify_init 253
|__NR_inotify_add_watch
|__NR_inotify_rm_watch 
|__NR_migrate_pages 256
|__NR_openat 257
|__NR_mkdirat 258
|__NR_mknodat 259
|__NR_fchownat 260
|__NR_futimesat 261
|__NR_newfstatat 262
|__NR_unlinkat 263
|__NR_renameat 264
|__NR_linkat 265
|__NR_symlinkat 266
|__NR_readlinkat 267
|__NR_fchmodat 268
|__NR_faccessat 269
|__NR_pselect6 270
|__NR_ppoll 271
|__NR_unshare 272
|__NR_set_robust_list 2
|__NR_get_robust_list 2
|__NR_splice 275
|__NR_tee 276
|__NR_sync_file_range 2
|__NR_vmsplice 278
|__NR_move_pages 279
|__NR_utimensat 280
|__NR_epoll_pwait 281
|__NR_signalfd 282
|__NR_timerfd_create 28
|__NR_eventfd 284
|__NR_fallocate 285
|__NR_timerfd_settime 2
|__NR_timerfd_gettime 2
|__NR_accept4 288
|__NR_signalfd4 289
|__NR_eventfd2 290
|__NR_epoll_create1 291
|__NR_dup3 292
|__NR_pipe2 293
|__NR_inotify_init1 294
|__NR_preadv 295
|__NR_pwritev 296
|__NR_rt_tgsigqueueinfo
|__NR_perf_event_open 2
|__NR_recvmmsg 299
|__NR_fanotify_init 300
|__NR_fanotify_mark 301
|__NR_prlimit64 302
|__NR_name_to_handle_at
|__NR_open_by_handle_at
|__NR_clock_adjtime 305
|__NR_syncfs 306
|__NR_sendmmsg 307
|__NR_setns 308
|__NR_getcpu 309
|__NR_process_vm_readv 
|__NR_process_vm_writev
|__NR_kcmp 312
|__NR_finit_module 313
|__NR_sched_setattr 314
|__NR_sched_getattr 315
|__NR_renameat2 316
|__NR_seccomp 317
|__NR_getrandom 318
|__NR_memfd_create 319
|__NR_kexec_file_load 3
|__NR_bpf 321
|__NR_execveat 322
|__NR_userfaultfd 323
|__NR_membarrier 324
|__NR_mlock2 325
|__NR_copy_file_range 3
|__NR_preadv2 327
|__NR_pwritev2 328
|__NR_pkey_mprotect 329
|__NR_pkey_alloc 330
|__NR_pkey_free 331
|__NR_statx 332