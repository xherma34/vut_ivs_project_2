#include "guicalculator.h"
#include "ui_guicalculator.h"
#include "helpwindow.h"
#include "math_lib.h"

double ans = 0.0;
bool divBool = false;
bool mulBool = false;
bool addBool = false;
bool subBool = false;
bool powerBool = false;
bool sqrtBool = false;

GuiCalculator::GuiCalculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GuiCalculator)
{
    ui->setupUi(this);

    //Display ans
    ui->Display->setText(QString::number(ans));

    //setting numButtons
    connect(ui->Num0, SIGNAL(released()), this, SLOT (numberPressed()));
    connect(ui->Num1, SIGNAL(released()), this, SLOT (numberPressed()));
    connect(ui->Num2, SIGNAL(released()), this, SLOT (numberPressed()));
    connect(ui->Num3, SIGNAL(released()), this, SLOT (numberPressed()));
    connect(ui->Num4, SIGNAL(released()), this, SLOT (numberPressed()));
    connect(ui->Num5, SIGNAL(released()), this, SLOT (numberPressed()));
    connect(ui->Num6, SIGNAL(released()), this, SLOT (numberPressed()));
    connect(ui->Num7, SIGNAL(released()), this, SLOT (numberPressed()));
    connect(ui->Num8, SIGNAL(released()), this, SLOT (numberPressed()));
    connect(ui->Num9, SIGNAL(released()), this, SLOT (numberPressed()));

    //Delete&Clear
    connect(ui->clearButton, SIGNAL(released()), this, SLOT (clearPressed()));

    //float button
    connect(ui->floatButton, SIGNAL(released()), this, SLOT (floatPressed()));

    //operation
    connect(ui->addButton, SIGNAL(released()), this, SLOT (operationPressed()));
    connect(ui->subButton, SIGNAL(released()), this, SLOT (operationPressed()));
    connect(ui->mulButton, SIGNAL(released()), this, SLOT (operationPressed()));
    connect(ui->divButton, SIGNAL(released()), this, SLOT (operationPressed()));
    connect(ui->powerButton, SIGNAL(released()), this, SLOT (operationPressed()));
    connect(ui->sqrtButton, SIGNAL(released()), this, SLOT (operationPressed()));

    //fac
    connect(ui->facButton, SIGNAL(released()), this, SLOT (facPressed()));

    //log
    connect(ui->logButton, SIGNAL(released()), this, SLOT (logPressed()));

    //Equals button
    connect(ui->eqButton, SIGNAL(released()), this, SLOT (equalsPressed()));

    //Help button
    connect(ui->helpButton, SIGNAL(released()), this, SLOT (helpPressed()));
}


GuiCalculator::~GuiCalculator()
{
    delete ui;
}


//Display number pressed on diplsay
void GuiCalculator::numberPressed()
{
    QPushButton * buttonPressed = (QPushButton *)sender();
    QString value = buttonPressed->text();
    QString displayValue = ui->Display->text();

    if((displayValue.toDouble() == 0) || (displayValue.toDouble() == 0.0))
    {
        //rewrite number on display
        ui->Display->setText(value);
    }
    else
    {
        //add number to displayed number to create new value
        QString newValue = displayValue + value;
        //double doubleNewValue = newValue.toDouble();
        ui->Display->setText(newValue);
    }
}

void GuiCalculator::floatPressed()
{
    QString displayValue = ui->Display->text();
    QString newValue = displayValue + ".";
    ui->Display->setText(newValue);
}

void GuiCalculator::clearPressed()
{
    divBool = false;
    mulBool = false;
    addBool = false;
    subBool = false;
    powerBool = false;
    sqrtBool = false;
    ui->Display->setText("0");
}

void GuiCalculator::operationPressed()
{
    //Clearing operation buttons
    divBool = false;
    mulBool = false;
    addBool = false;
    subBool = false;
    powerBool = false;
    sqrtBool = false;

    QPushButton * buttonPressed = (QPushButton *)sender();
    QString operatorPressed = buttonPressed->objectName();
    QString pressedValue = ui->Display->text();
    double dblPressedValue = pressedValue.toDouble();
    ans = dblPressedValue;

    if(QString::compare(operatorPressed, "addButton", Qt::CaseInsensitive)==0)
    {
        addBool = true;
    }
    else if(QString::compare(operatorPressed, "subButton", Qt::CaseInsensitive)==0)
    {
        subBool = true;
    }
    else if(QString::compare(operatorPressed, "divButton", Qt::CaseInsensitive)==0)
    {
        divBool = true;
    }
    else if(QString::compare(operatorPressed, "mulButton", Qt::CaseInsensitive)==0)
    {
        mulBool = true;
    }
    else if(QString::compare(operatorPressed, "powerButton", Qt::CaseInsensitive)==0)
    {
        powerBool = true;
    }
    else if(QString::compare(operatorPressed, "sqrtButton", Qt::CaseInsensitive)==0)
    {
        sqrtBool = true;
    }
    ui->Display->setText("");
}

void GuiCalculator::equalsPressed()
{
    double num = 0.0;
    QString displayValue = ui->Display->text();
    double dblValue = displayValue.toDouble();
    if(addBool || subBool || divBool || mulBool || powerBool || sqrtBool)
    {
        if(addBool)
        {
            //INSERT FUNCTION
            num = sum(ans, dblValue);
        }
        else if(subBool)
        {
            num = sub(ans, dblValue);
        }
        else if(divBool)
        {
            num = div(ans, dblValue);
        }
        else if(mulBool)
        {
            num = mul(ans, dblValue);
        }
        else if(powerBool)
        {
            num = power(ans, dblValue);
        }
        else if(sqrtBool)
        {
            num = rooting(ans, dblValue);
        }
    }
    ui->Display->setText(QString::number(num));
}

void GuiCalculator::facPressed()
{
    QString displayValue = ui->Display->text();
    double dblValue = displayValue.toDouble();
    dblValue = fac(dblValue);
    ui->Display->setText(QString::number(dblValue));
}

void GuiCalculator::logPressed()
{
    QString displayValue = ui->Display->text();
    double dblValue = displayValue.toDouble();
    dblValue = ln(dblValue);
    ui->Display->setText(QString::number(dblValue));
}



void GuiCalculator::helpPressed()
{
    helpWindow window;
    window.setModal(true);
    window.exec();
}
