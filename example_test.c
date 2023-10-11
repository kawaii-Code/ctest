#include "ctest.h"
#include "example.h"

void test_sum() {
    int a = 1;
    int b = 2;

    int expected = 3;
    int actual = a + b;

    ctest_assert_equal_int(expected, actual);
}

void test_sum_large() {
    int a = -2147483648;
    int b = 2147483647;

    int expected = -1;
    int actual = a + b;

    ctest_assert_equal_int(expected, actual);
}

void test_mul() {
    int a = 2;
    int b = 3;

    int expected = 6;
    int actual = a * b;

    ctest_assert_equal_int(expected, actual);
}

void test_greet() {
    const char *greeting = string_concat("Hello, ", "World");
    CTEST_ASSERT_EQUAL("Hello, World", greeting, const char, 12);
}

void test_arr_sum() {
    int a[] = {1, 2, 3};
    int b[] = {4, 6, 7};

    array_add(a, b, 3);

    int expected[] = {5, 8, 10};

    CTEST_ASSERT_EQUAL(expected, a, int, 3);
}

void test_float() {
    float expected = 0.14f;
    float actual = 0.1f;

    ctest_assert_equal_float(expected, actual, 0.05f);
}

void test_should_fail_1() {
    int actual[] = { 1, 2, 3 };
    int expected[] = { 1, 3, 3 };

    CTEST_ASSERT_EQUAL(expected, actual, int, 3);
}

void test_should_fail_2() {
    ctest_assert(0);
}

void test_should_fail_3() {
    ctest_assert_equal_int(5, 6);
}

int main() {
    CTEST_ADD_TEST(test_sum);
    CTEST_ADD_TEST(test_sum_large);
    CTEST_ADD_TEST(test_mul);
    CTEST_ADD_TEST(test_greet);
    CTEST_ADD_TEST(test_arr_sum);
    CTEST_ADD_TEST(test_float);
    CTEST_ADD_TEST(test_should_fail_1);
    CTEST_ADD_TEST(test_should_fail_2);
    CTEST_ADD_TEST(test_should_fail_3);

    ctest_run_tests();
}
