#include "ctest.h"
#include "example.h"

void test_sum() {
    int a = 1;
    int b = 2;

    int expected = 3;
    int actual = sum(a, b);

    ctest_assert_equal_int(expected, actual);
}

void test_sum_large() {
    int a = -2147483648;
    int b = 2147483647;

    int expected = -1;
    int actual = sum(a, b);

    ctest_assert_equal_int(expected, actual);
}

void test_mul() {
    int a = 2;
    int b = 3;

    int expected = 6;
    int actual = mul(a, b);

    ctest_assert_equal_int(expected, actual);
}

void test_greet() {
    const char *greeting = greet("Nia");
    ctest_assert_equal_bytes("Hello, Nia", (void *)greeting, 10);
}

void test_arr_sum() {
    int a[] = {1, 2, 3};
    int b[] = {4, 6, 7};

    arr_add(a, b, 3);

    int expected[] = {5, 8, 10};

    ctest_assert_equal_bytes(expected, a, 3);
}

void test_float() {
    float expected = 0.14f;
    float actual = 0.1f;

    ctest_assert_equal_float(expected, actual, 0.05f);
}

void test_true() {
    ctest_assert(1);
}

int main() {
    CTEST_ADD_TEST(test_sum);
    CTEST_ADD_TEST(test_sum_large);
    CTEST_ADD_TEST(test_mul);
    CTEST_ADD_TEST(test_greet);
    CTEST_ADD_TEST(test_arr_sum);
    CTEST_ADD_TEST(test_float);

    ctest_run();
}