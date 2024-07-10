#include <print>
#include "Helpers.hpp"
#include "UnitTests.hpp"

int main() {
    UnitTests testSuite;

    testSuite.addTest("Dummy_test1",
    [](){
        double value = 0.0;
    
        auto result = dummyFunc(value);

        ASSERT_EQ(result, 0.0)
    });

    testSuite.addTest("Dummy_test2",
    [](){
        double value = 1.0;
    
        auto result = dummyFunc(value);

        ASSERT_EQ(result, 1.0)
    });

    testSuite.addTest("RepeatString_test1",
    [](){
        std::vector<int> vec = {0, 2, 1};
        std::string str = "home";
    
        auto result = repeatString(vec, str);

        ASSERT_EQ(result, "homehome")
    });

    testSuite.addTest("RepeatString_test2",
    [](){
        std::vector<int> vec = {3, 2, 5};
        std::string str = "test";
    
        auto result = repeatString(vec, str);

        ASSERT_EQ(result, "testtesttesttesttest")
    });

    testSuite.addTest("RepeatString_test3",
    [](){
        std::vector<int> vec = {1, 1, 1};
        std::string str = "abc";
    
        auto result = repeatString(vec, str);

        ASSERT_EQ(result, "abc")
    });

    testSuite.run();
}
