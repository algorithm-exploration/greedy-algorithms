#define countof(a) (sizeof(a)/sizeof((a)[0]))

void smallArrayTest(Test *tc)
{
    const int intArray[] = {1, 2, 3};
    const int expected[] = {6, 3, 2};
    int actual[countof(expected)] = {0};

    getProductsOfAllIntsExceptAtIndex(intArray, countof(intArray), actual, countof(actual));
    AssertIntArrayEquals(tc, expected, actual, countof(expected));
}

void longerArrayTest(Test *tc)
{
    const int intArray[] = {8, 2, 4, 3, 1, 5};
    const int expected[] = {120, 480, 240, 320, 960, 192};
    int actual[countof(expected)] = {0};

    getProductsOfAllIntsExceptAtIndex(intArray, countof(intArray), actual, countof(actual));
    AssertIntArrayEquals(tc, expected, actual, countof(expected));
}

void arrayHasOneZeroTest(Test *tc)
{
    const int intArray[] = {6, 2, 0, 3};
    const int expected[] = {0, 0, 36, 0};
    int actual[countof(expected)] = {0};

    getProductsOfAllIntsExceptAtIndex(intArray, countof(intArray), actual, countof(actual));
    AssertIntArrayEquals(tc, expected, actual, countof(expected));
}

void arrayHasTwoZerosTest(Test *tc)
{
    const int intArray[] = {4, 0, 9, 1, 0};
    const int expected[] = {0, 0, 0, 0, 0};
    int actual[countof(expected)] = {0};

    getProductsOfAllIntsExceptAtIndex(intArray, countof(intArray), actual, countof(actual));
    AssertIntArrayEquals(tc, expected, actual, countof(expected));
}

void oneNegativeNumberTest(Test *tc)
{
    const int intArray[] = {-3, 8, 4};
    const int expected[] = {32, -12, -24};
    int actual[countof(expected)] = {0};

    getProductsOfAllIntsExceptAtIndex(intArray, countof(intArray), actual, countof(actual));
    AssertIntArrayEquals(tc, expected, actual, countof(expected));
}

void allNegativeNumbersTest(Test *tc)
{
    const int intArray[] = {-7, -1, -4, -2};
    const int expected[] = {-8, -56, -14, -28};
    int actual[countof(expected)] = {0};

    getProductsOfAllIntsExceptAtIndex(intArray, countof(intArray), actual, countof(actual));
    AssertIntArrayEquals(tc, expected, actual, countof(expected));
}

void callWithEmptyArray(void)
{
    getProductsOfAllIntsExceptAtIndex(NULL, 0, NULL, 0);
}

void errorWithEmptyArrayTest(Test *tc)
{
    AssertRaises(tc, callWithEmptyArray);
}

void callWithOneElementArray(void)
{
    const int intArray[] = {1};
    int actual[countof(intArray)] = {0};

    getProductsOfAllIntsExceptAtIndex(intArray, countof(intArray), actual, countof(actual));
}

void errorWithOneNumberTest(Test *tc)
{
    AssertRaises(tc, callWithOneElementArray);
}

void callWithOutputArrayShorterThanInputArray(void)
{
    const int intArray[] = {1, 2, 3};
    int actual[countof(intArray) - 1] = {0};

    getProductsOfAllIntsExceptAtIndex(intArray, countof(intArray), actual, countof(actual));
}

void errorOutputArrayShorterThanInputArrayTest(Test *tc)
{
    AssertRaises(tc, callWithOutputArrayShorterThanInputArray);
}

int main()
{
    TestSuite *tests = TestSuiteNew();

    SUITE_ADD_TEST(tests, smallArrayTest);
    SUITE_ADD_TEST(tests, longerArrayTest);
    SUITE_ADD_TEST(tests, arrayHasOneZeroTest);
    SUITE_ADD_TEST(tests, arrayHasTwoZerosTest);
    SUITE_ADD_TEST(tests, oneNegativeNumberTest);
    SUITE_ADD_TEST(tests, allNegativeNumbersTest);
    SUITE_ADD_TEST(tests, errorWithEmptyArrayTest);
    SUITE_ADD_TEST(tests, errorWithOneNumberTest);
    SUITE_ADD_TEST(tests, errorOutputArrayShorterThanInputArrayTest);

    TestSuiteRun(tests);
    TestSuiteDelete(tests);

    return 0;
}
