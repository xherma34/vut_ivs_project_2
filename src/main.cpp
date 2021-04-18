#include "guicalculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GuiCalculator w;
    w.show();
    return a.exec();
}
