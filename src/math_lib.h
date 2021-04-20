/**
 * @file        math_lib.h
 * @author      Maxim Plicka, VUT FIT Brno, xplick04@fit.vutbr.cz, VUT FIT Brno
 * @date        26.03.2021
 *
 * @brief       Implementation of math library.
 *
 */

#include <math.h>
#include <stdexcept>

/**
 * @brief Summarization of two numbers.
 *
 * @param num1
 * @param num2
 * @return double
 */
double sum(const double num1, const double num2)
{
    return(num1+num2);
}

/**
 * @brief Subtraction of two numbers.
 *
 * @param num1
 * @param num2
 * @return double
 */
double sub(const double num1, const double num2)
{
    return(num1-num2);
}

/**
 * @brief Multiplication of two numbers.
 *
 * @param num1
 * @param num2
 * @return double
 */
double mul(const double num1, const double num2)
{
    return(num1 * num2);
}

/**
 * @brief Division of two nubmers.
 * @warning Cannot divide by zero
 * @param num1
 * @param num2
 * @return double
 */
double div(const double num1, const double num2)
{
    ///Checking for dividing by zero.
    if(num2 == 0)
    {
        throw std::runtime_error("Cannot divide by zero.");
        return 0;
    }
    else{
        return(num1/num2);
    }
}

/**
 * @brief Factorial of a number.
 * @warning Must be natural number
 * @param num1
 * @return int
 */
int fac(double num1)
{
    ///Control for natural numbers.
    if(num1 - int(num1) != 0)
    {
        throw std::runtime_error("Must be natural number.");
        return 0;
    }

    int result = 1;

    int x = abs(num1);

    ///Checking if num1 is greater than zero.
    if(num1 >= 0)
    {
        for(int i = 1; i <= x; i++)
        {
            result *= i;
        }
    }

    ///Checking if num1 is lesser than zero.
    if(num1 < 0)
    {
        for(int i = 1; i <= x; i++)
        {
            result *= i;
        }
        result *= -1;
    }
    return(result);
}

/**
 * @brief Power of num1 to num2.
 * @warning Must be natural number
 * @param num1
 * @param num2
 * @return double
 */
double power(const double num1, const double num2)
{
    ///Checking for natural numbers.
    if(num2 - int(num2) != 0)
    {
        throw std::runtime_error("Must be natural number.");
    }

    double result = pow(num1,num2);
    return(result);
}

/**
 * @brief Root of num1 to num2.
 * @warning Must be natural number
 * @warning Root must be greater than zero
 * @warning Does not exist
 * @param num1
 * @param num2
 * @return double
 */
double rooting(const double num1, const double num2) {

    double result;

    ///Checking for negative root.
    if (num2 <= 0) {
        throw std::runtime_error("Root must be greater than zero.");
    }

    ///Checking if num2 is natural number.
    int x = int(num2);
    if((num2 - x) != 0)
    {
        throw std::runtime_error("Must be natural number.");
    }

    ///Checking if num1 is lesser than zero.
    if (num1 < 0)
    {
        ///Checking for invalid root of negative number.
        if(int(num2) % 2 == 0)
        {
            throw std::runtime_error("Doesnt exist.");
        }

        result = pow(abs(num1),1/num2);
        return(result*(-1));
    }

    result = pow(num1,1/num2);
    return(result);
}

/**
 * @brief Natural logarithm of num1.
 * @warning Root must be greater than zero
 * @param num1
 * @return double
 */
double ln(const double num1)
{
    ///num1 must be greater than zero.
    if(num1 <= 0)
    {
        throw std::runtime_error("Root must be greater than zero.");
    }
    return (log(num1));
}
