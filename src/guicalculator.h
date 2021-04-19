#ifndef GUICALCULATOR_H
#define GUICALCULATOR_H

#include <QMainWindow>

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
