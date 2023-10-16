Steps to add trace\_logger to your nginx
1. put trace\_logger/* to nginx/src/
2. add trace logger dir to include:
    edit auto/make, after `mkdir -p $NGX\_OBJS/...`, append this command:
    `mkdir -p $NGX_OBJS/src/trace_logger $NGX_OBJS/src/trace_logger/ngx`
3. append trace logger dir to core's include path:
    `CORE_INCS="src/core src/trace_logger`
4. append trace logger file names to compile list:
    edit auto/sources, append trace logger file names to CORE\_DEPS and CORE\_SRCS:.
    ```
    CORE\_DEPS="....
    src/trace_logger/logger.h src/trace_logger/ngx/dumper.h"

    CORE\_SRCS="....
    src/trace_logger/logger.c src/trace_logger/ngx/dumper.c"
    ```
