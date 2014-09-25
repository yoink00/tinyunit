/*
The MIT License (MIT)

Copyright (c) 2014 Stuart Wallace

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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
