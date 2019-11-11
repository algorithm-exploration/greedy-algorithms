#define countof(a) (sizeof(a)/sizeof((a)[0]))

void shortArrayTest(Test *tc)
{
    const int arrayOfInts[] = {1, 2, 3, 4};
    const int actual = highestProductOf3(arrayOfInts, countof(arrayOfInts));
    const int expected = 24;
    AssertIntEquals(tc, expected, actual);
}

void longerArrayTest(Test *tc)
{
    const int arrayOfInts[] = {6, 1, 3, 5, 7, 8, 2};
    const int actual = highestProductOf3(arrayOfInts, countof(arrayOfInts));
    const int expected = 336;
    AssertIntEquals(tc, expected, actual);
}

void arrayHasOneNegativeTest(Test *tc)
{
    const int arrayOfInts[] = {-5, 4, 8, 2, 3};
    const int actual = highestProductOf3(arrayOfInts, countof(arrayOfInts));
    const int expected = 96;
    AssertIntEquals(tc, expected, actual);
}

void arrayHasTwoNegativesTest(Test *tc)
{
    const int arrayOfInts[] = {-10, 1, 3, 2, -10};
    const int actual = highestProductOf3(arrayOfInts, countof(arrayOfInts));
    const int expected = 300;
    AssertIntEquals(tc, expected, actual);
}

void arrayIsAllNegativesTest(Test *tc)
{
    const int arrayOfInts[] = {-5, -1, -3, -2};
    const int actual = highestProductOf3(arrayOfInts, countof(arrayOfInts));
    const int expected = -6;
    AssertIntEquals(tc, expected, actual);
}

void callWithEmptyArray(void)
{
    highestProductOf3(NULL, 0);
}

void assertionFailsWithEmptyArrayTest(Test *tc)
{
    AssertRaises(tc, callWithEmptyArray);
}

void callWithOneNumber(void)
{
    const int arrayOfInts[] = {1};
    highestProductOf3(arrayOfInts, countof(arrayOfInts));
}

void assertionFailsWithOneNumberTest(Test *tc)
{
    AssertRaises(tc, callWithOneNumber);
}

void callWithTwoNumbers(void)
{
    const int arrayOfInts[] = {1, 1};
    highestProductOf3(arrayOfInts, countof(arrayOfInts));
}

void assertionFailsWithTwoNumbersTest(Test *tc)
{
    AssertRaises(tc, callWithTwoNumbers);
}

int main()
{
    TestSuite *tests = TestSuiteNew();

    SUITE_ADD_TEST(tests, shortArrayTest);
    SUITE_ADD_TEST(tests, longerArrayTest);
    SUITE_ADD_TEST(tests, arrayHasOneNegativeTest);
    SUITE_ADD_TEST(tests, arrayHasTwoNegativesTest);
    SUITE_ADD_TEST(tests, arrayIsAllNegativesTest);
    SUITE_ADD_TEST(tests, assertionFailsWithEmptyArrayTest);
    SUITE_ADD_TEST(tests, assertionFailsWithOneNumberTest);
    SUITE_ADD_TEST(tests, assertionFailsWithTwoNumbersTest);

    TestSuiteRun(tests);
    TestSuiteDelete(tests);

    return 0;
}
