#include <gtest/gtest.h>
#include <template_project/common/common.hpp>
#include <template_project/gui/gui.hpp>

inline int add(int x, int y)
{
    return x + y;
}

inline int sub(int x, int y)
{
    return x - y;
}

TEST(common, test_add)
{
    EXPECT_EQ(2, add(1, 1));
}

TEST(common, test_sub)
{
    EXPECT_EQ(0, sub(1, 1));
}

TEST(common1, test1_sub)
{
    EXPECT_EQ(0, sub(1, 1));
}
