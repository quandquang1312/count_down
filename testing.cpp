#include <gtest/gtest.h>

#include "count_down.cpp"

#include <vector>

/*
* UTILS TESTING
*/
TEST(utils, splitString)
{
    std::vector<int> test1 = splitString("12:20:30");
    std::vector<int> test2 = splitString("1:00:");
    std::vector<int> test3 = splitString("12:46");
    std::vector<int> test4 = splitString("1awf:aw0");
    std::vector<int> test5 = splitString("12:46:57:21");

    std::vector<int> sample1, sample2, sample3, sample5;

    sample1.push_back(12);
    sample1.push_back(20);
    sample1.push_back(30);

    sample2.push_back(1);
    sample2.push_back(0);
    sample2.push_back(11);

    sample3.push_back(12);
    sample3.push_back(46);
    sample3.push_back(57);

    sample5.push_back(12);
    sample5.push_back(46);
    sample5.push_back(57);
    sample5.push_back(21);

    int size0 = 0;

    EXPECT_EQ(test1, sample1);
    EXPECT_EQ(test2.size(), size0);
    EXPECT_EQ(test3.size(), size0);
    EXPECT_EQ(test4.size(), size0);
    EXPECT_EQ(test5.size(), size0);
}

TEST(utils, multiplyString)
{
    std::string str1 = "a";
    std::string sample1 = "aaa";

    std::string str2 = "1d1d1";
    std::string sample2 = "1d1d11d1d11d1d1";

    std::string str3 = "\bqrqwr\nawfaw";
    std::string sample3 = "\bqrqwr\nawfaw\bqrqwr\nawfaw\bqrqwr\nawfaw";

    std::string str4 = "";
    std::string sample4 = "";

    std::string str5 = "\'\"\'\'";
    std::string sample5 = "\'\"\'\'\'\"\'\'\'\"\'\'";

    EXPECT_EQ(str1*3, sample1);
    EXPECT_EQ(str2*3, sample2);
    EXPECT_EQ(str3*3, sample3);
    EXPECT_EQ(str4*3, sample4);
    EXPECT_EQ(str5*3, sample5);
}

/*
* COUNT DOWN TESTING
*/
TEST(countdown, seconds_left)
{
    
    std::vector<int> test1 = minusTime(10,20,20,9,20,20);
    std::vector<int> test2 = minusTime(10,11,11,10,10,55);
    std::vector<int> test3 = minusTime(10,01,01,9,59,59);
    std::vector<int> test4 = minusTime(11,11,11,11,11,11);
    std::vector<int> test5 = minusTime(10,10,10,11,11,11);
    
    std::vector<int> sample1 {1, 0, 0};
    std::vector<int> sample2 {0, 0, 16};
    std::vector<int> sample3 {0, 1, 2};
    std::vector<int> sample4 {0, 0, 0};
    std::vector<int> sample5;

    EXPECT_EQ(test1, sample1);
    EXPECT_EQ(test2, sample2);
    EXPECT_EQ(test3, sample3);
    EXPECT_EQ(test4, sample4);
    EXPECT_EQ(test5, sample5);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
