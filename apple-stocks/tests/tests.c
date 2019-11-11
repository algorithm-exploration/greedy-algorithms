#define countof(a) (sizeof(a)/sizeof((a)[0]))

void priceGoesUpThenDownTest(Test *tc)
{
    const int stockPrices[] = {1, 5, 3, 2};
    const int actual = getMaxProfit(stockPrices, countof(stockPrices));
    const int expected = 4;
    AssertIntEquals(tc, expected, actual);
}

void priceGoesDownThenUpTest(Test *tc)
{
    const int stockPrices[] = {7, 2, 8, 9};
    const int actual = getMaxProfit(stockPrices, countof(stockPrices));
    const int expected = 7;
    AssertIntEquals(tc, expected, actual);
}

void priceGoesUpAllDayTest(Test *tc)
{
    const int stockPrices[] = {1, 6, 7, 9};
    const int actual = getMaxProfit(stockPrices, countof(stockPrices));
    const int expected = 8;
    AssertIntEquals(tc, expected, actual);
}

void priceGoesDownAllDayTest(Test *tc)
{
    const int stockPrices[] = {9, 7, 4, 1};
    const int actual = getMaxProfit(stockPrices, countof(stockPrices));
    const int expected = -2;
    AssertIntEquals(tc, expected, actual);
}

void priceStaysTheSameAllDayTest(Test *tc)
{
    const int stockPrices[] = {1, 1, 1, 1};
    const int actual = getMaxProfit(stockPrices, countof(stockPrices));
    const int expected = 0;
    AssertIntEquals(tc, expected, actual);
}

void callWithEmptyPrices(void)
{
    getMaxProfit(NULL, 0);
}

void assertionFailsWithEmptyPricesTest(Test *tc)
{
    AssertRaises(tc, callWithEmptyPrices);
}

void callWithOnePrice(void)
{
    const int stockPrices[] = {1};
    getMaxProfit(stockPrices, countof(stockPrices));
}

void assertionFailsWithOnePriceTest(Test *tc)
{
    AssertRaises(tc, callWithOnePrice);
}

int main()
{
    TestSuite *tests = TestSuiteNew();

    SUITE_ADD_TEST(tests, priceGoesUpThenDownTest);
    SUITE_ADD_TEST(tests, priceGoesDownThenUpTest);
    SUITE_ADD_TEST(tests, priceGoesUpAllDayTest);
    SUITE_ADD_TEST(tests, priceGoesDownAllDayTest);
    SUITE_ADD_TEST(tests, priceStaysTheSameAllDayTest);
    SUITE_ADD_TEST(tests, assertionFailsWithEmptyPricesTest);
    SUITE_ADD_TEST(tests, assertionFailsWithOnePriceTest);

    TestSuiteRun(tests);
    TestSuiteDelete(tests);

    return 0;
}
