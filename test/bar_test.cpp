#include <iostream>
#include "gtest/gtest.h"

#include "tangle/foo.h"

TEST(TangleBar, GetStringSize) {
  EXPECT_EQ(size_t{5}, tangle::bar(std::string{"Kyoto"}));
  EXPECT_EQ(size_t{9}, tangle::bar(std::string{"Stockholm"}));
  EXPECT_EQ(size_t{10}, tangle::bar(std::string{"Montreal  "}));
  EXPECT_EQ(size_t{3}, tangle::bar(std::string{"   "}));
}

TEST(TangleBar, EmptyStringHaveZeroSize) {
  EXPECT_EQ(size_t{0}, tangle::bar(std::string{""}));
}
