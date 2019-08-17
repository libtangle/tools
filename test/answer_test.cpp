#include <iostream>
#include "gtest/gtest.h"

#include "tangle/foo.h"

TEST(TangleAnswer, WrongWrongWRONNNNG) {
  EXPECT_FALSE(tangle::answer(8129));
  EXPECT_FALSE(tangle::answer(-4));
  EXPECT_FALSE(tangle::answer(47));
  EXPECT_FALSE(tangle::answer(41));
  EXPECT_FALSE(tangle::answer(2));
}

TEST(TangleAnswer, GoodAnswer) {
  ASSERT_TRUE(tangle::answer(42));
}
