const lest::test tests[] = {
    CASE("price goes up then down") {
        const int actual = getMaxProfit({1, 5, 3, 2});
        const int expected = 4;
        EXPECT(actual == expected);
    },

    CASE("price goes down then up") {
        const int actual = getMaxProfit({7, 2, 8, 9});
        const int expected = 7;
        EXPECT(actual == expected);
    },

    CASE("price goes up all day") {
        const int actual = getMaxProfit({1, 6, 7, 9});
        const int expected = 8;
        EXPECT(actual == expected);
    },

    CASE("price goes down all day") {
        const int actual = getMaxProfit({9, 7, 4, 1});
        const int expected = -2;
        EXPECT(actual == expected);
    },

    CASE("price stays the same all day") {
        const int actual = getMaxProfit({1, 1, 1, 1});
        const int expected = 0;
        EXPECT(actual == expected);
    },

    CASE("exception with empty prices") {
        EXPECT_THROWS(getMaxProfit({}));
    },

    CASE("exception with one price") {
        EXPECT_THROWS(getMaxProfit({1}));
    },
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
