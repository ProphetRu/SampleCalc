#include <gtest/gtest.h>

#include "SampleCalc.hpp"

TEST(SampleCalc, Plus) 
{
    // Arrange
    auto a = 10;
	auto b = 5;

    // Act
	auto c = SampleCalc<int>::Plus(a, b);

    // Assert
    ASSERT_EQ(c, 15);
}

TEST(SampleCalc, Minus) 
{
    // Arrange
    auto a = 10;
	auto b = 5;

    // Act
	auto c = SampleCalc<int>::Minus(a, b);

    // Assert
    ASSERT_EQ(c, 5);
}

TEST(SampleCalc, Multiply) 
{
    // Arrange
    auto a = 10;
	auto b = 5;

    // Act
	auto c = SampleCalc<int>::Multiply(a, b);

    // Assert
    ASSERT_EQ(c, 50);
}

TEST(SampleCalc, Divide) 
{
    // Arrange
    auto a = 10;
	auto b = 5;

    // Act
	auto c = SampleCalc<int>::Divide(a, b);

    // Assert
    ASSERT_EQ(c, 2);
}

TEST(SampleCalc, DivideZero) 
{
    // Arrange
    auto a = 10;
	auto b = 0;

    // Act
	//
    // Assert
    ASSERT_THROW(SampleCalc<int>::Divide(a, b), std::invalid_argument);
}

int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}