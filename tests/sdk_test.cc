#include <gtest/gtest.h>

TEST(SdkTest, BasicAssertions) {
  EXPECT_EQ(1, 1);
  EXPECT_NE(0, 1);
  EXPECT_LT(0, 1);
  EXPECT_LE(0, 1);
  EXPECT_GT(1, 0);
  EXPECT_GE(1, 0);
}