#ifndef CTEST_H
#define CTEST_H

#include <stddef.h>

#define CTEST_ADD_TEST(test) do { ctest_add_test(test, #test); } while(0)
#define CTEST_ASSERT_EQUAL(expected, actual, type, count) \
        ctest_assert_equal_bytes(                         \
                (const char *)(expected),                 \
                (const char *)(actual),                   \
                (count) * sizeof(type))

typedef void (*TestFunction)();

void ctest_add_test(TestFunction test, const char *testName);

void ctest_run();

void ctest_assert(int value);
void ctest_assert_equal_int(int expected, int actual);
void ctest_assert_equal_float(float expected, float actual, float delta);
void ctest_assert_equal_bytes(const char *expected, const char *actual, size_t byte_count);

#endif // CTEST_H
