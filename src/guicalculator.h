/**
 * @file        guicalculator.h
 * @author      Pavel Heřmann, xherma34, xherma34@fit.vutbr.cz, VUT FIT Brno
 * @author      Jan Zdeněk, xzdene01, xzdene01@fit.vutbr.cz, VUT FIT Brno
 * @date        18.04.2021
 *
 * @brief       Implementation of gui.
 *
 */

#ifndef GUICALCULATOR_H
#define GUICALCULATOR_H

#include <QMainWindow>

/**
 * @brief GuiCalculator init.
 * 
 */
QT_BEGIN_NAMESPACE
namespace Ui { class GuiCalculator; }
QT_END_NAMESPACE

class GuiCalculator : public QMainWindow
{
    Q_OBJECT

public:
    GuiCalculator(QWidget *parent = nullptr);
    ~GuiCalculator();

private:
    Ui::GuiCalculator *ui;

///Calculator functions.
private slots:
    void numberPressed();
    void clearPressed();
    void operationPressed();
    void equalsPressed();
    void floatPressed();
    void facPressed();
    void helpPressed();
    void logPressed();
    void changeSignPressed();
};
#endif // GUICALCULATOR_H
