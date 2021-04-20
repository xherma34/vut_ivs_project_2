/**
 * @file        stddev.cpp
 * @author      Jan Zdeněk, xzdene01, xzdene01@fit.vutbr.cz, VUT FIT Brno
 * @date        20.04.2021
 *
 * @brief       Implementation of profiliong.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../math_lib.h"
#include <unistd.h>

int main()
{
    double loadNumber;
    char delim;
    double count = 0;
    double x = 0;
    double xPow2 = 0;
    double bracket;
    double result;

    if(isatty(0))
    {
        std::cout << "Invalid input file.\n";
        return 1;
    }

    while(scanf("%lf%c", &loadNumber, &delim)!=EOF)
    {
        if(!isspace(delim))
        {
            std::cout << "Invalid input file.\n";
            return 1;
        }
        xPow2 = sum(xPow2, power(loadNumber, 2.0));
        x = sum(x, loadNumber);
        count++;
    }

    if(count == 0)
    {
        std::cout << "Invalid input file.\n";
        return 1;
    }

    x = div(x, count);

    bracket = sub(xPow2, mul(count, power(x, 2)));

    result = rooting(div(bracket, count-1), 2);

    printf("%f\n", result);

    return 0;
}