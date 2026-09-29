#include <gtest/gtest.h>
#include "../src/ip_utils.h"

TEST(IPFilterTESTS, SplitFunction)
{
    EXPECT_EQ(split("192.168.1.1", '.'), std::vector<std::string>({"192", "168", "1", "1"}));
}