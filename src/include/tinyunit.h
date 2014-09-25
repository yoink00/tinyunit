#ifndef __TINYUNIT_H__
#define __TINYUNIT_H__

#include <string.h>
#include <inttypes.h>

extern int tests_run;
extern int suites_run;

#define MU_SUCCESS 0
#define MU_FAIL 1

#define tu_assert(message, test) do { if (!(test)) return message; } while (0)

#define tu_assert_str_eq(ptr, str) do { if(strcmp(ptr, str) != 0) return #ptr" == "#str; } while (0)

#define tu_assert_str_ne(ptr, str) do { if(strcmp(ptr, str) == 0) return #ptr" != "#str; } while (0)

#define tu_assert_ptr_eq(ptr1, ptr2) do { if(ptr1 != ptr2) return #ptr1" == "#ptr2; } while (0)

#define tu_assert_ptr_ne(ptr1, ptr2) do { if(ptr1 == ptr2) return #ptr1" != "#ptr2; } while (0)

#define tu_assert_int_eq(int1, int2) do { if(int1 != int2) return #int1" == "#int2; } while (0)

#define tu_assert_int_ne(int1, int2) do { if(int1 == int2) return #int1" != "#int2; } while (0)

#define tu_fail(msg) do { return ""#msg""; } while (0)

#define tu_run_test(test) do {\
    fprintf(stderr, "Running test:\t"#test"");\
    fflush(stderr);\
    const char *msg = test();\
    tests_run++;\
    if (msg) {\
        fprintf(stderr, " [FAIL]\n");\
        return msg;\
    }\
    fprintf(stderr, " [PASS]\n");\
} while (0)

#define tu_run_suite(suite) do {\
    fprintf(stderr, "----------------------------------\n");\
    fprintf(stderr, "Running suite:\t"#suite"\n\n");\
    const char *msg = suite();\
    suites_run++;\
    if (msg) return msg;\
    fprintf(stderr, "\nPassed suite:\t"#suite"\n");\
} while (0)


#endif /*__TINYUNIT_H__*/
