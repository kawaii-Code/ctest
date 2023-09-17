# Ctest

A testing library for C. Minimal interface,
comparing raw bytes is enough for most cases.

## Showcase

For `example.c` and `example_test.c` this is the output:

```console
test_sum(): OK
test_sum_large(): OK
test_mul(): OK
test_greet(): OK
test_arr_sum(): OK
test_float(): OK
test_failing(): Expected '3', was '2' at byte 4
test_failing2(): Fail
test_failing3(): Expected 5, was 6
-----------------
3 tests failed
6 tests OK
```
