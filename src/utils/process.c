#define _GNU_SOURCE
#include <sys/time.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/file.h>
#include <errno.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/wait.h>

#include <utils/error.h>

visible size_t get_epoch(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return 1000000 * tv.tv_sec + tv.tv_usec;
}
static bool locked = false;
visible void single_instance(){
    if(locked){
        return;
    }
    int pid_file = open("/tmp/ymp.pid", O_CREAT | O_RDWR, 0666);
    int rc = flock(pid_file, LOCK_EX | LOCK_NB);
    locked = true;
    if(rc) {
        if(EWOULDBLOCK == errno){
            error_add("Another ymp instance is already running");
            exit(31);
        }
    }
}

visible int run_args(char *args[]) {
    pid_t pid = fork();
    int status = 0;
    if (pid == 0) {
        execv(args[0], args);
        perror("execv failed");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);
    }
    return status;
}
