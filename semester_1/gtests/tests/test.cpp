#include <gtest/gtest.h>

#include "mersen.h"

TEST(IsPrimeTest, BoundaryConditions)
{
    EXPECT_FALSE(isPrime(-10));
    EXPECT_FALSE(isPrime(-1));
    EXPECT_FALSE(isPrime(0));
    EXPECT_FALSE(isPrime(1));
}

TEST(IsPrimeTest, NormalConditions)
{
    EXPECT_TRUE(isPrime(2));
    EXPECT_TRUE(isPrime(3));
    EXPECT_TRUE(isPrime(5));
    EXPECT_TRUE(isPrime(7));
    EXPECT_TRUE(isPrime(97));

    EXPECT_FALSE(isPrime(4));
    EXPECT_FALSE(isPrime(9));
    EXPECT_FALSE(isPrime(25));
    EXPECT_FALSE(isPrime(49));
    EXPECT_FALSE(isPrime(100));
}

TEST(MersensTest, WhenEmpty)
{
    EXPECT_TRUE(Mersens(-10).empty());
    EXPECT_TRUE(Mersens(0).empty());
    EXPECT_TRUE(Mersens(2).empty());
}

TEST(MersensTest, NormalConditions)
{
    EXPECT_EQ(Mersens(3), (std::vector <int> {3}));
    EXPECT_EQ(Mersens(30), (std::vector <int> {3, 7}));
    EXPECT_EQ(Mersens(31), (std::vector <int> {3, 7, 31}));
    EXPECT_EQ(Mersens(1000), (std::vector <int> {3, 7, 31, 127}));
    EXPECT_EQ(Mersens(2046), (std::vector <int> {3, 7, 31, 127}));
    EXPECT_EQ(Mersens(2047), (std::vector <int> {3, 7, 31, 127, 2047}));
}