#include <math.h>
#include <stdexcept>

double sum(const double num1, const double num2)
{
    return(num1 + num2);
}

double sub(const double num1, const double num2)
{
    return(num1 - num2);
}

double mul(const double num1, const double num2)
{
    return(num1 * num2);
}

double div(const double num1, const double num2)
{

    if(num2 == 0)
    {
        throw std::runtime_error("Can not divide ZERO");
    }

    return (num1/num2);
}

int fac(double num1)
{

    int result = 1;

    int x = abs(num1);
//
//    if(num1 % 0 != 0)
//    {
//        throw std::runtime_error("Musi byt prirozene cislo");
//        return (0);
//    }


    if(num1 >= 0)
    {
        for(int i = 1; i <= x; i++)
        {
            result *= i;
        }
    }

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


double power(const double num1, const int num2)
{
    return(pow(num1,num2));
}

double rooting(const double num1, const double num2) {

    if (num2 <= 0) {
        throw std::runtime_error("Root must be > 0");
    }

    int x = int(num2);
    if((num2 - x) != 0)
    {
        throw std::runtime_error("Root must be > 0");
    }

    if (num1 < 0)
    {
        if(int(num2) % 2 == 0)
        {
            throw std::runtime_error("Doesnt exist");
        }
    }

    double result = pow(num1,1/num2);
    return(result);
}

double ln(const double num1)
{
    if(num1 <= 0)
    {
        throw std::runtime_error("Root must be > 0");
    }
    return (log(num1));
}
