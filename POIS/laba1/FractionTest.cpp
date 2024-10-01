#include <gtest/gtest.h>
#include "Fraction.cpp" // Убедитесь, что путь к файлу корректный

TEST(FractionTest, DefaultConstructor) {
    Fraction frac;
    EXPECT_EQ(frac.getDouble(), 0);
    EXPECT_EQ(frac.up, 0);
    EXPECT_EQ(frac.down, 1);
}

TEST(FractionTest, ConstructorValid) {
    Fraction frac(Sign('+'), 1, 2);
    EXPECT_EQ(frac.getDouble(), 0.5);
}

TEST(FractionTest, ConstructorInvalidDenominator) {
    EXPECT_THROW(Fraction(Sign('+'), 1, 0), std::invalid_argument);
}

TEST(FractionTest, Addition) {
    Fraction frac1(Sign('+'), 1, 2);
    Fraction frac2(Sign('+'), 1, 3);
    Fraction result = frac1 + frac2;
    EXPECT_EQ(result.getDouble(), 5.0 / 6.0);
}

TEST(FractionTest, AdditionWithInteger) {
    Fraction frac(Sign('+'), 1, 2);
    Fraction result = frac + 1;
    EXPECT_EQ(result.getDouble(), 3.0 / 2.0);
}

TEST(FractionTest, Subtraction) {
    Fraction frac1(Sign('+'), 1, 2);
    Fraction frac2(Sign('+'), 1, 3);
    Fraction result = frac1 - frac2;
    EXPECT_EQ(result.getDouble(), 1.0 / 6.0);
}

TEST(FractionTest, Simplification) {
    Fraction frac(Sign('+'), 2, 4);
    EXPECT_EQ(frac.getDouble(), 0.5);
}

TEST(FractionTest, NegativeSign) {
    Fraction frac(Sign('-'), 1, 2);
    EXPECT_EQ(frac.getDouble(), -0.5);
}

TEST(FractionTest, NegativeAddition) {
    Fraction frac1(Sign('+'), 1, 2);
    Fraction frac2(Sign('-'), 1, 3);
    Fraction result = frac1 + frac2;
    EXPECT_EQ(result.getDouble(), 1.0 / 6.0);
}

TEST(FractionTest, NegativeSubtraction) {
    Fraction frac1(Sign('-'), 1, 2);
    Fraction frac2(Sign('+'), 1, 3);
    Fraction result = frac1 - frac2;
    EXPECT_EQ(result.getDouble(), -1.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}