/*
 * @file        cal_code.cpp
 * @author      Maxim Plicka, VUT FIT Brno, xplick04@fit.vutbr.cz
 * @date        26.03.2021
 *
 * @brief       Implementace matematickych knihoven.
 *
 */

#include <math.h>
#include <stdexcept>

double sum(const double num1, const double num2)
{
    return(num1+num2);
}

double sub(const double num1, const double num2)
{
    return(num1-num2);
}

double mul(const double num1, const double num2)
{
    return(num1 * num2);
}

double div(const double num1, const double num2)
{
    if((num1 == 0) || (num2 == 0))
    {
        throw std::runtime_error("Can not divide ZERO");
    }
    else{
        return(num1/num2);
    }
}

int fac(double num1)
{
    //Kontrola prirozenych cisel
    if(num1 - int(num1) != 0)
    {
        throw std::runtime_error("Musi byt prirozene cislo");
    }

    int result = 1;

    int x = abs(num1);


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


double power(const double num1, const double num2)
{
    //Kontrola prirozenych cisel
    if(num2 - int(num2) != 0)
    {
        throw std::runtime_error("Musi byt prirozene cislo");
    }

    double result = pow(num1,num2);
    return(result);
}

double rooting(const double num1, const double num2) {

    double result;

    if (num2 <= 0) {
        throw std::runtime_error("Root must be > 0");
    }

    int x = int(num2);
    if((num2 - x) != 0)
    {
        throw std::runtime_error("Musi byt prirozene cislo");
    }

    if (num1 < 0)
    {
        if(int(num2) % 2 == 0)
        {
            throw std::runtime_error("Doesnt exist");
        }

        result = pow(abs(num1),1/num2);
        return(result*(-1));
    }

    result = pow(num1,1/num2);
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
