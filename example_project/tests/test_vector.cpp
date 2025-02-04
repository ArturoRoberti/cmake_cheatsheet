#include <gtest/gtest.h>
#include "example.hpp"

TEST(VectorTests, TestSize) {
    example::ExampleClass ex;
    EXPECT_EQ(ex.getSize(), 3);
}