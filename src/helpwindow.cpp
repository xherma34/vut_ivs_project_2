/**
 * @file        helpwindow.cpp
 * @author      Pavel Heřmann, xherma34, xherma34@fit.vutbr.cz, VUT FIT Brno
 * @date        18.04.2021
 *
 * @brief       Implementation of help window.
 *
 */

#include "helpwindow.h"
#include "ui_helpwindow.h"


/**
 * @brief Construct a new help Window::help Window object
 * 
 * @param parent 
 */
helpWindow::helpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpWindow)
{
    ui->setupUi(this);
}

/**
 * @brief Destroy the help Window::help Window object
 * 
 */
helpWindow::~helpWindow()
{
    delete ui;
}
