#include <iostream>
#include "gtest/gtest.h"
#include "tangle/tangle.h"

TEST(TangleAnswer, WrongWrongWRONNNNG)
{
  EXPECT_FALSE(tangle::answer(8129));
  EXPECT_FALSE(tangle::answer(-4));
  EXPECT_FALSE(tangle::answer(47));
  EXPECT_FALSE(tangle::answer(41));
  EXPECT_FALSE(tangle::answer(2));
}

TEST(TangleAnswer, GoodAnswer)
{
  ASSERT_TRUE(tangle::answer(42));
}

TEST(TangleFoo, Positives)
{
  EXPECT_EQ(38, tangle::foo(-4));
  EXPECT_EQ(42, tangle::foo(0));
}

TEST(TangleFoo, Negatives)
{
  EXPECT_NE(-1, tangle::foo(99));
  EXPECT_NE(0, tangle::foo(-41));
  EXPECT_NE(42, tangle::foo(42));
}

TEST(TangleBar, GetStringSize)
{
  EXPECT_EQ(size_t{5}, tangle::bar(std::string{"Kyoto"}));
  EXPECT_EQ(size_t{9}, tangle::bar(std::string{"Stockholm"}));
  EXPECT_EQ(size_t{10}, tangle::bar(std::string{"Montreal  "}));
  EXPECT_EQ(size_t{3}, tangle::bar(std::string{"   "}));
}

TEST(TangleBar, EmptyStringHaveZeroSize)
{
  EXPECT_EQ(size_t{0}, tangle::bar(std::string{""}));
}
