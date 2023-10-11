#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ctest.h"

typedef struct {
    TestFunction function;
    const char  *name;
} Test;

#define TEST_CAPACITY 4096
static Test tests[TEST_CAPACITY];
static int  testCount = 0;
static int  failedTests = 0;

void ctest_add_test(TestFunction test, const char *name) {
    if (testCount >= TEST_CAPACITY) {
        printf("Too many tests!??\n");
        return;
    }

    tests[testCount] = (Test) {
        .function = test,
        .name = name,
    };
    testCount++;
}

void ctest_run() {
    for (int i = 0; i < testCount; i++) {
        Test test = tests[i];
        int previousTests = failedTests;

        printf("%s(): ", test.name);
        test.function();
        int didFail = failedTests > previousTests;
        if (!didFail) {
            printf("OK\n");
        }
    }

    printf("-----------------\n");
    printf("%d tests failed\n", failedTests);
    printf("%d tests OK\n", testCount - failedTests);
}

void ctest_fail() {
    failedTests++;
}

void ctest_assert(int value) {
    if (!value) {
        printf("Fail\n");
        ctest_fail();
    }
}

void ctest_assert_equal_int(int expected, int actual) {
    if (expected != actual) {
        printf("Expected %d, was %d\n", expected, actual);

        ctest_fail();
    }
}

void ctest_assert_equal_float(float expected, float actual, float delta) {
    if (expected - delta > actual || expected + delta < actual) {
        printf("Expected %f (+-%f), was %f\n", expected, delta, actual);

        ctest_fail();
    }
}

// TODO: Better output
void ctest_assert_equal_bytes(const char *expected, const char *actual, size_t byteCount) {
    int not_equal = -1;
    for (size_t i = 0; i < byteCount; i++) {
        if (expected[i] != actual[i]) {
            not_equal = i;
            break;
        }
    }

    if (not_equal >= 0) {
        printf("Expected '%d', was '%d' at byte %d\n",
                expected[not_equal], actual[not_equal], not_equal);
        ctest_fail();
    }
}
