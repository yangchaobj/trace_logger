#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

const char* now() {
    static __thread char date[64];
    struct timeval tv;
    struct tm *info;

    gettimeofday(&tv, NULL);
    info = localtime(&tv.tv_sec);
    strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", info);

    char usec[16];
    snprintf(usec, sizeof(usec), ".%ld", tv.tv_usec);
    strcat(date, usec);

    return date;
}

const char* prefix_pid() {
    static __thread char __prefix[128];
    snprintf(__prefix, sizeof(__prefix), "pid:%5ld", (long)getpid());
    return __prefix;
}

