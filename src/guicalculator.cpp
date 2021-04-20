/**
 * @file        guicalculator.cpp
 * @author      Pavel Heřmann, xherma34, xherma34@fit.vutbr.cz, VUT FIT Brno
 * @author      Jan Zdeněk, xzdene01, xzdene01@fit.vutbr.cz, VUT FIT Brno
 * @date        18.04.2021
 *
 * @brief       Implementation of gui.
 *
 */


#include "guicalculator.h"
#include "ui_guicalculator.h"
#include "helpwindow.h"
#include "math_lib.h"

/**
 * @brief Help variables for functions.
 * 
 */
double ans = 0.0;
bool divBool = false;
bool mulBool = false;
bool addBool = false;
bool subBool = false;
bool powerBool = false;
bool sqrtBool = false;
bool firstNum = false;

/**
 * @brief Construct a new Gui Calculator:: Gui Calculator object.
 * 
 * @param parent 
 */
GuiCalculator::GuiCalculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GuiCalculator)
{
    ui->setupUi(this);

    ///Display ans.
    ui->Display->setText(QString::number(ans));

    ///setting numButtons.
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

    ///setting delete&Clear.
    connect(ui->clearButton, SIGNAL(released()), this, SLOT (clearPressed()));

    ///setting float button.
    connect(ui->floatButton, SIGNAL(released()), this, SLOT (floatPressed()));

    ///setting operation.
    connect(ui->addButton, SIGNAL(released()), this, SLOT (operationPressed()));
    connect(ui->subButton, SIGNAL(released()), this, SLOT (operationPressed()));
    connect(ui->mulButton, SIGNAL(released()), this, SLOT (operationPressed()));
    connect(ui->divButton, SIGNAL(released()), this, SLOT (operationPressed()));
    connect(ui->powerButton, SIGNAL(released()), this, SLOT (operationPressed()));
    connect(ui->sqrtButton, SIGNAL(released()), this, SLOT (operationPressed()));

    ///setting fac.
    connect(ui->facButton, SIGNAL(released()), this, SLOT (facPressed()));

    ///setting log.
    connect(ui->logButton, SIGNAL(released()), this, SLOT (logPressed()));

    ///setting equals button.
    connect(ui->eqButton, SIGNAL(released()), this, SLOT (equalsPressed()));

    //setting help button.
    connect(ui->helpButton, SIGNAL(released()), this, SLOT (helpPressed()));

    //setting change sign button.
    connect(ui->ChangeSign, SIGNAL(released()), this, SLOT (changeSignPressed()));
}

/**
 * @brief Destroy the Gui Calculator:: Gui Calculator object
 * 
 */
GuiCalculator::~GuiCalculator()
{
    delete ui;
}


/**
 * @brief Number pressed on calculator handling.
 * 
 */
void GuiCalculator::numberPressed()
{
    QPushButton * buttonPressed = (QPushButton *)sender();
    QString value = buttonPressed->text();
    QString displayValue = ui->Display->text();

    if(firstNum == false)
    {
        //rewrite number on display
        ui->Display->setText(value);
        firstNum = true;
    }
    else
    {
        //add number to displayed number to create new value
        QString newValue = displayValue + value;
        //double doubleNewValue = newValue.toDouble();
        ui->Display->setText(newValue);
    }
}

/**
 * @brief Float point number handling.
 * 
 */
void GuiCalculator::floatPressed()
{
    QString displayValue = ui->Display->text();
    QString newValue = displayValue + ".";
    ui->Display->setText(newValue);
}

/**
 * @brief Clear button handling.
 * 
 */
void GuiCalculator::clearPressed()
{
    divBool = false;
    mulBool = false;
    addBool = false;
    subBool = false;
    powerBool = false;
    sqrtBool = false;
    firstNum = false;
    ui->Display->setText("0");
}

/**
 * @brief Operation switch.
 * 
 */
void GuiCalculator::operationPressed()
{
    ///Clearing operation buttons.
    divBool = false;
    mulBool = false;
    addBool = false;
    subBool = false;
    powerBool = false;
    sqrtBool = false;
    firstNum = false;

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

/**
 * @brief Executing operations and getting result.
 * 
 */
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
            if(dblValue == 0)
            {
                ui->Display->setText("Syntax error");
                return;
            }
            else
            {
                num = div(ans, dblValue);
            }
        }
        else if(mulBool)
        {
            num = mul(ans, dblValue);
        }
        else if(powerBool)
        {
            if(dblValue - int(dblValue) != 0)
            {
                ui->Display->setText("Syntax error");
                return;
            }
            else
            {
                num = power(ans, dblValue);
            }
        }
        else if(sqrtBool)
        {
            if((dblValue <= 0) || (dblValue - int(dblValue) != 0) || (ans < 0 && int(dblValue) % 2 == 0))
            {
                ui->Display->setText("Syntax error");
                return;
            }
            else
            {
                num = rooting(ans, dblValue);
            }
        }
    }
    ui->Display->setText(QString::number(num));
}

/**
 * @brief Factorial handling.
 * 
 */
void GuiCalculator::facPressed()
{
    QString displayValue = ui->Display->text();
    double dblValue = displayValue.toDouble();
    if(dblValue - int(dblValue) != 0)
    {
        ui->Display->setText("Syntax error");
    }
    else
    {
        dblValue = fac(dblValue);
        ui->Display->setText(QString::number(dblValue));
    }
}

/**
 * @brief Natural logarithm handling.
 * 
 */
void GuiCalculator::logPressed()
{
    QString displayValue = ui->Display->text();
    double dblValue = displayValue.toDouble();
    if(dblValue <= 0)
    {
        ui->Display->setText("Syntax error");
    }
    else
    {
        dblValue = ln(dblValue);
        ui->Display->setText(QString::number(dblValue));
    }
}

/**
 * @brief Changing sign of a number via button on calculator.
 * 
 */
void GuiCalculator::changeSignPressed()
{
    QString displayValue = ui->Display->text();
    double dblValue = displayValue.toDouble();
    dblValue = dblValue * -1;
    ui->Display->setText(QString::number(dblValue));
}

/**
 * @brief Help pop up window.
 * 
 */
void GuiCalculator::helpPressed()
{
    helpWindow window;
    window.setModal(true);
    window.exec();
}
