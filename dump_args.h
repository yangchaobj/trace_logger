#ifndef __DUMP_ARGS__
#define __DUMP_ARGS__

#define dump_args(head, argc, argv) \
    do { \
        trace_log("%s, argc = %d, argv = ", head, argc); \
        for (int i = 0; i < argc; i++) { \
            if (i > 0) { \
                printf(", "); \
            } \
            printf("%s", argv[i]); \
        } \
        printf("\n"); \
    } while(0)

#endif

