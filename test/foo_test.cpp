#include <iostream>
#include "gtest/gtest.h"

#include "tangle/foo.h"

TEST(TangleFoo, Positives) {
  EXPECT_EQ(38, tangle::foo(-4));
  EXPECT_EQ(42, tangle::foo(0));
}

TEST(TangleFoo, Negatives) {
  EXPECT_NE(-1, tangle::foo(99));
  EXPECT_NE(0, tangle::foo(-41));
  EXPECT_NE(42, tangle::foo(42));
}
