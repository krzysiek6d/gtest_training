#include <gmock/gmock.h>
#include <vector>

namespace
{
    struct Param
    {
        int value1;
        int value2;
        int ignoredValue;
    };

    struct AMock 
    {
        MOCK_METHOD1(callInt, void(std::vector<Param>));
    };

    MATCHER_P(IsParamEqual, elements, "")
    {
        using namespace testing;
        std::vector<::testing::Matcher<Param>> elementsAsMatchers;
        std::transform(elements.begin(), elements.end(), std::back_inserter(elementsAsMatchers),
            [](const auto& e)
            {
                return AllOf(
                    Field(&Param::value1, e.value1), 
                    Field(&Param::value2, e.value2));
            });
        Matcher<std::vector<Param>> matcher = UnorderedElementsAreArray(elementsAsMatchers);
        return matcher.MatchAndExplain(arg, result_listener);
    }

    TEST(matcher_objects, shouldMatchInUnderedOrderAndIgnoreSomeFields)
    {
        AMock amock;
        std::vector<Param> matchingParam{
            {.value1 = 10, .value2 = 20}, 
            {.value1 = 1, .value2 = 2}};
        testing::Matcher<std::vector<Param>> matcher = IsParamEqual(matchingParam);
        EXPECT_CALL(amock, callInt(matcher));
        
        std::vector<Param> p1{
            {.value1 = 1, .value2 = 2, .ignoredValue = 123}, 
            {.value1 = 10, .value2 = 20, .ignoredValue = 123}};
        amock.callInt(p1);
    }

}