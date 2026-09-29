#include <gtest/gtest.h>
#include "../src/ip_utils.h"

TEST(IPFilterTESTS, SplitFunction)
{
    EXPECT_EQ(split("192.168.1.1", '.'), std::vector<std::string>({"192", "168", "1", "1"}));
    EXPECT_EQ(split("255.255.1.1", '.'), std::vector<std::string>({"255", "255", "1", "1"}));
}

TEST(IPFiltersTESTS, ValidateOctetFunction)
{
    EXPECT_EQ(validate_octet(231), true);
    EXPECT_EQ(validate_octet(297), false);
}

TEST(IPFiltersTESTS, generateIPFunction)
{
    EXPECT_EQ(generate_ip(986751920), (ip_tuple{120, 227, 80, 83}));
}