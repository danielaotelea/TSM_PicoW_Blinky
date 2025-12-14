#include "platform.h"
#if PL_CONFIG_USE_UNIT_TESTS
#include "test_gcov_test.h"
#include "gcov_test.h"
#include "McuRTOS.h"
#include "McuLED.h"
#include "unity/unity.h"

void TestCalc(void)
{
    /* Case 1: i == 0, returns i + 1 (1) */
    TEST_ASSERT_EQUAL_INT(1, Calc(0, 0));
    TEST_ASSERT_EQUAL_INT(1, Calc(0, 99));

    /* Case 2: i > 0 && j < 10, returns i + j */
    TEST_ASSERT_EQUAL_INT(5, Calc(2, 3));
    TEST_ASSERT_EQUAL_INT(10, Calc(1, 9));

    /* Other cases (i < 0 or j >= 10 with i > 0) result in
       undefined behavior in Calc because 'res' is uninitialized.
       Not Tested. */
}

void TestValue(void)
{
    /* Case 1: input is 3, returns 5 */
    TEST_ASSERT_EQUAL_INT(5, Value(3));

    /* Case 2: input is not 3, returns 1 */
    TEST_ASSERT_EQUAL_INT(1, Value(0));
    TEST_ASSERT_EQUAL_INT(1, Value(10));
}

void TestTest2(void)
{
    int val;
    /* Case 1: *p is 0, nothing should happen */
    val = 0;
    Test2(&val);
    TEST_ASSERT_EQUAL_INT(0, val);

    /* Case 2: *p is 1, Value(1) is 1 (!=5), nothing should happen */
    val = 1;
    Test2(&val);
    TEST_ASSERT_EQUAL_INT(1, val);

    /* Case 3: *p is 3, Value(3) is 5, *p should be set to 0 */
    val = 3;
    Test2(&val);
    TEST_ASSERT_EQUAL_INT(0, val);
}


#endif /* PL_CONFIG_USE_UNIT_TESTS */
