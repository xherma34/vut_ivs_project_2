/**
 * @file        tdd_tests.cpp
 * @author      Alexander Sila, VUT FIT Brno, xsilaa00@fit.vutbr.cz
 * @date        26.03.2021
 *
 * @brief       Math libraries tests
 *
 */

#include "../src/math_lib.h"
#include <gtest/gtest.h>

/**
 * @brief Summarization tests with different input integer values.
 */
TEST(Summation, IntValues)
{
    //Positive Values
    EXPECT_EQ(10, sum(7,3));
    EXPECT_EQ(0, sum(0,0));
    EXPECT_EQ(1, sum(0,1));
    EXPECT_EQ(1, sum(1,0));
    EXPECT_EQ(895, sum(569,326));

    //Negative Values
    EXPECT_EQ(50, sum(-10,60));
    EXPECT_EQ(-60, sum(-20,-40));
    EXPECT_EQ(57, sum(-9,66));
    EXPECT_EQ(-40, sum(-120,80));
    EXPECT_EQ(895, sum(-569,1464));

}

/**
 * @brief Summarization tests with different input double values.
 */
TEST(Summation, DoubleValues)
{
    double result;

    //Positive Values
    result = 19.2 + 1.3;
    EXPECT_EQ(result,sum(19.2,1.3));
    EXPECT_EQ(result,sum(1.3,19.2));
    result = 30.5 + 20.1;
    EXPECT_EQ(result,sum(30.5,20.1));
    result = 19.80 + 131.80;
    EXPECT_EQ(result,sum(19.80,131.80));
    EXPECT_EQ(2986512.512,sum(995632.235,1990880.277));

    //Negative Values
    result = 30.25 + 40.16;
    EXPECT_EQ(result,sum(30.25,40.16));
    result = 80.26 + 200.59;
    EXPECT_EQ(result,sum(80.26,200.59));
    result = -70.15 + (-50.26);
    EXPECT_EQ(result,sum(-70.15,-50.26));
    result = 28.126 + (-32.289);
    EXPECT_EQ(result,sum(28.126,-32.289));
    result = 2100.459 + (-469.126);
    EXPECT_EQ(result,sum(2100.459,-469.126));
    result = -520.787 + 198.598;
    EXPECT_EQ(result,sum(-520.787,198.598));
    result = -816.111 + 297.269;
    EXPECT_EQ(result,sum(-816.111,297.269));

}

/**
 * @brief Substraction tests with different input integer values.
 */
TEST(Substraction, IntValues)
{
    //Positive Values
    EXPECT_EQ(0, sub(0,0));
    EXPECT_EQ(168, sub(188,20));
    EXPECT_EQ(666, sub(1000,334));
    EXPECT_EQ(28, sub(98,70));
    EXPECT_EQ(69842, sub(95462,25620));

    //Negative Values
    EXPECT_EQ(-10,sub(30,40));
    EXPECT_EQ(-120,sub(80,200));
    EXPECT_EQ(-20,sub(-70,-50));
    EXPECT_EQ(60,sub(28,-32));
    EXPECT_EQ(2569,sub(2100,-469));
    EXPECT_EQ(-718,sub(-520,198));
    EXPECT_EQ(-1113,sub(-816,297));
}

/**
 * @brief Substraction tests with different input double values.
 */
TEST(Substraction, DoubleValues)
{
    double result;

    //Positive Values
    result = 19.2 - 1.3;
    EXPECT_EQ(result,sub(19.2,1.3));
    result = 1.3 - 19.2;
    EXPECT_EQ(result,sub(1.3,19.2));
    result = 30.5 - 20.1;
    EXPECT_EQ(result,sub(30.5,20.1));
    result = 19.80 - 131.80;
    EXPECT_EQ(result,sub(19.80,131.80));
    EXPECT_EQ(-995248.042,sub(995632.235,1990880.277));

    //Negative Values
    result = 30.25 - 40.16;
    EXPECT_EQ(result,sub(30.25,40.16));
    result = 80.26 - 200.59;
    EXPECT_EQ(result,sub(80.26,200.59));
    result = -70.15 - (-50.26);
    EXPECT_EQ(result,sub(-70.15,-50.26));
    result = 28.126 - (-32.289);
    EXPECT_EQ(result,sub(28.126,-32.289));
    result = 2100.459 - (-469.126);
    EXPECT_EQ(result,sub(2100.459,-469.126));
    result = -520.787 - 198.598;
    EXPECT_EQ(result,sub(-520.787,198.598));
    result = -816.111 - 297.269;
    EXPECT_EQ(result,sub(-816.111,297.269));
}

/**
 * @brief Multiplication tests with different input integer values.
 */
TEST(Multiplication, IntValues)
{
    //Positive Values
    EXPECT_EQ(21, mul(7,3));
    EXPECT_EQ(546, mul(21,26));
    EXPECT_EQ(546, mul(26,21));
    EXPECT_EQ(81, mul(9,9));
    EXPECT_EQ(894, mul(149,6));
    EXPECT_EQ(2580, mul(30,86));

    //Negative Values
    EXPECT_EQ(-21, mul(-7,3));
    EXPECT_EQ(-546, mul(-21,26));
    EXPECT_EQ(-546, mul(26,-21));
    EXPECT_EQ(81, mul(-9,-9));
    EXPECT_EQ(894, mul(-149,-6));
    EXPECT_EQ(-2580, mul(30,-86));

}

/**
 * @brief Multiplication tests with different input double values.
 */
TEST(Multiplication, DoubleValues)
{
    double result;
    //Positive Values
    result = 7.23 * 3.56;
    EXPECT_EQ(result, mul(7.23,3.56));
    result = 21.20 * 26.6;
    EXPECT_EQ(result, mul(21.20,26.6));
    result = 26.89 * 21;
    EXPECT_EQ(result, mul(26.89,21));
    result = 9.6 * 9.8;
    EXPECT_EQ(result, mul(9.6,9.8));
    result = 149.25 * 6.6;
    EXPECT_EQ(result, mul(149.25,6.6));
    result = 30.215 * 86.365;
    EXPECT_EQ(result, mul(30.215,86.365));

    //Negative Values
    result = -7.23 * -3.56;
    EXPECT_EQ(result, mul(-7.23,-3.56));
    result = 21.20 * -26.6;
    EXPECT_EQ(result, mul(21.20,-26.6));
    result = -26.89 * 21.5;
    EXPECT_EQ(result, mul(-26.89,21.5));
    result = -9.6 * 9.8;
    EXPECT_EQ(result, mul(-9.6,9.8));
    result = -149.25 * -6.6;
    EXPECT_EQ(result, mul(-149.25,-6.6));
    result = 30.215 * -86.365;
    EXPECT_EQ(result, mul(30.215,-86.365));

}

/**
 * @brief Division tests with different input integer values.
 */
TEST(Division, IntValues)
{
    //Positive Values
    EXPECT_EQ(5.0,div(50.0,10.0));
    EXPECT_EQ(1.0,div(1.0,1.0));
    EXPECT_EQ(9.0,div(180.0,20.0));
    EXPECT_EQ(3.0,div(21.0,7.0));
    EXPECT_EQ(10921.0,div(43684.0,4.0));

    //Negative Values
    EXPECT_EQ(-5.0,div(-50.0,10.0));
    EXPECT_EQ(-1.0,div(1.0,-1.0));
    EXPECT_EQ(9.0,div(-180.0,-20.0));
    EXPECT_EQ(3.0,div(-21.0,-7.0));
    EXPECT_EQ(-10921.0,div(43684.0,-4.0));
}

/**
 * @brief Division tests with different input double values.
 */
TEST(Division, DoubleValues)
{
    double result;
    //Positive Values
    result = 5.25/5.1;
    EXPECT_EQ(result,div(5.25,5.1));
    result = 12.2/3.1;
    EXPECT_EQ(result,div(12.2,3.1));
    result = 180.0/5.8;
    EXPECT_EQ(result,div(180.0,5.8));
    result = 268.6/8.2;
    EXPECT_EQ(result,div(268.6,8.2));
    result = 4368.24/96.62;
    EXPECT_EQ(result,div(4368.24,96.62));

    //Negative Values
    result = -7.23 / -3.56;
    EXPECT_EQ(result, div(-7.23,-3.56));
    result = 21.20 / -26.6;
    EXPECT_EQ(result, div(21.20,-26.6));
    result = -26.89 / 21.5;
    EXPECT_EQ(result, div(-26.89,21.5));
    result = -9.6 / 9.8;
    EXPECT_EQ(result, div(-9.6,9.8));
    result = -149.25 / -6.6;
    EXPECT_EQ(result, div(-149.25,-6.6));
    result = 30.215 / -86.365;
    EXPECT_EQ(result, div(30.215,-86.365));
}

/**
 * @brief Factorial tests with different input integer values.
 */
TEST(Factorial, AllIntValues)
{
    //Positive Values
    EXPECT_EQ(6, fac(3));
    EXPECT_EQ(120, fac(5));
    EXPECT_EQ(362880, fac(9));
    EXPECT_EQ(5040, fac(7));
    EXPECT_EQ(1, fac(0));

    //Negative Values
    EXPECT_EQ(-120, fac(-5));
    EXPECT_EQ(-24, fac(-4));
    EXPECT_EQ(-6, fac(-3));
    EXPECT_EQ(-1, fac(-1));
}

/**
 * @brief Factorial tests with different input double values.
 */
TEST(Factorial, AllDoubleValues)
{
    //Positive Values
    EXPECT_ANY_THROW(fac(5.2));
    EXPECT_ANY_THROW(fac(1.5));

    //Negative Values
    EXPECT_ANY_THROW(fac(-5.2));
    EXPECT_ANY_THROW(fac(-4.1));
}

/**
 * @brief Power tests with different input integer and double values.
 */
TEST(Power, AllValues)
{
    //Positive Values
    EXPECT_EQ(8,power(2,3));
    EXPECT_EQ(64,power(4,3));
    EXPECT_EQ(32,power(2,5));
    EXPECT_EQ(1,power(1,9));
    EXPECT_EQ(2097152,power(8,7));
    EXPECT_EQ(1,power(6,0));

    double result;

    EXPECT_EQ(5.76,power(2.4,2));
    result = pow(10.8,4);
    EXPECT_EQ(result,power(10.8,4));
    result = pow(4.6,6);
    EXPECT_EQ(result,power(4.6,6));
    result = pow(9.2,5);
    EXPECT_EQ(result,power(9.2,5));
    result = pow(208.124,3);
    EXPECT_EQ(result,power(208.124,3));
    EXPECT_ANY_THROW(power(10,5.2));
    EXPECT_ANY_THROW(power(10.5,5.2));

    //Negative Values
    EXPECT_EQ(4,power(-2,2));
    EXPECT_EQ(-64,power(-4,3));
    EXPECT_EQ(16,power(-2,4));
    EXPECT_EQ(-1,power(-1,9));
    EXPECT_EQ(-2097152,power(-8,7));
    EXPECT_EQ(5.76,power(-2.4,2));
    result = pow(10.8,4);
    EXPECT_EQ(result,power(-10.8,4));
    result = pow(4.6,6);
    EXPECT_EQ(result,power(-4.6,6));
    result = pow(-9.2,5);
    EXPECT_EQ(result,power(-9.2,5));
    result = pow(-208.124,3);
    EXPECT_EQ(result,power(-208.124,3));
    result = pow(-2,-2);
    EXPECT_EQ(result,power(-2,-2));
    result = pow(4,-3);
    EXPECT_EQ(result,power(4,-3));
    result = pow(10,-3);
    EXPECT_EQ(result,power(10,-3));
    result = pow(6,-5);
    EXPECT_EQ(result,power(6,-5));
    //Num2 musi byt prirozene cislo
    EXPECT_ANY_THROW(power(-10,-5.2));
    EXPECT_ANY_THROW(power(10.5,-5.2));
}

/**
 * @brief Rooting tests with different input integer and double values.
 */
TEST(ROOT, AllValues)
{
    double result;
    //Positive Values

    EXPECT_EQ(3,rooting(27,3));
    EXPECT_EQ(2,rooting(8,3));
    result = pow(5.2,1/3.0);
    EXPECT_EQ(result,rooting(5.2,3.0));
    result = pow(12.3,1/5.0);
    EXPECT_EQ(result,rooting(12.3,5.0));
    result = pow(100.1,1/7.0);
    EXPECT_EQ(result,rooting(100.1,7.0));
    result = pow(68.5,1/6.0);
    EXPECT_EQ(result,rooting(68.5,6.0));

    EXPECT_ANY_THROW(rooting(27,3.5));
    EXPECT_ANY_THROW(rooting(64,4.2));


    //Negative Values
    EXPECT_DOUBLE_EQ(-3,rooting(-27,3));
    EXPECT_DOUBLE_EQ(-10,rooting(-1000,3));
    EXPECT_DOUBLE_EQ(-5,rooting(-3125,5));
    EXPECT_DOUBLE_EQ(-1,rooting(-1,7));


    //Even root test
    EXPECT_ANY_THROW(rooting(-2,2));
    EXPECT_ANY_THROW(rooting(-68,4));
    EXPECT_ANY_THROW(rooting(-16,6));


    //Negative root
    EXPECT_ANY_THROW(rooting(10,-5));
    EXPECT_ANY_THROW(rooting(10,-1));

}

/**
 * @brief Natural logarithm tests with different input integer and double values.
 */
TEST(ln, AllValues)
{
    double result;
    result = log(5.6);
    EXPECT_EQ(result,ln(5.6));
    result = log(10);
    EXPECT_EQ(result,ln(10));
    result = log(26.5);
    EXPECT_EQ(result,ln(26.5));
    result = log(256.8);
    EXPECT_EQ(result,ln(256.8));

    EXPECT_ANY_THROW(ln(-5.6));
    EXPECT_ANY_THROW(ln(0));

}

/**
 * @brief main() declaration.
 */
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
