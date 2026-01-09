#include <gtest/gtest.h>
// uncomment line below if you plan to use GMock
#include <gmock/gmock.h>

// TEST(...)
// TEST_F(...)



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // <- correct
}