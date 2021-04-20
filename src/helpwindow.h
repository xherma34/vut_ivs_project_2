/**
 * @file        helpwindow.h
 * @author      Pavel Heřmann, xherma34, xherma34@fit.vutbr.cz, VUT FIT Brno
 * @date        18.04.2021
 *
 * @brief       Implementation of help window.
 *
 */

#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QDialog>

/**
 * @brief Help window init.
 * 
 */
namespace Ui {
class helpWindow;
}

class helpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit helpWindow(QWidget *parent = nullptr);
    ~helpWindow();

private:
    Ui::helpWindow *ui;
};

#endif // HELPWINDOW_H
