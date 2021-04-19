/**
 * @file        main.cpp
 * @author      Pavel Heřmann, xherma34, xherma34@fit.vutbr.cz, VUT FIT Brno
 * @author      Jan Zdeněk, xzdene01, xzdene01@fit.vutbr.cz, VUT FIT Brno
 * @date        26.03.2021
 *
 * @brief       Main for gui implementation.
 *
 */

#include "guicalculator.h"
#include <QApplication>

/**
 * @brief Main function in main.cpp.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GuiCalculator w;
    w.show();
    return a.exec();
}
