/*
 * trace info logger with colored font supported
 */
#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "dump_args.h"
#include "ngx/dumper.h"

const char* now();
const char* prefix_pid();

#define trace_log(fmt, ...) \
    do { \
        printf("%s\t%s\t%s@%d, %s\t", \
                prefix_pid(), \
                now(), \
                __FILE__, __LINE__, __func__ \
        ); \
        printf(fmt, ##__VA_ARGS__); \
    } while(0)

#endif


#define __nocolor "\e[0m"
#define __red     "\e[1;31m"
#define __green   "\e[1;32m"
#define __yellow  "\e[1;33m"
#define __blue    "\e[1;34m"
#define __white   "\e[1;37m"


#define trace_log_red(fmt, ...) \
    trace_log(__red fmt __nocolor, ##__VA_ARGS__)

#define tracelog_green(fmt, ...) \
    trace_log(__green fmt __nocolor, ##__VA_ARGS__)

#define trace_log_yellow(fmt, ...) \
    trace_log(__yellow fmt __nocolor, ##__VA_ARGS__)

#define trace_log_blue(fmt, ...) \
    trace_log(__blue fmt __nocolor, ##__VA_ARGS__)

