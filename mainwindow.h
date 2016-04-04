#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <Core.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void performOperation(int operation);
    void insertNumber(QString string);

private slots:
    void on_one_button_clicked();
    void on_two_button_clicked();
    void on_three_button_clicked();
    void on_four_button_clicked();
    void on_five_button_clicked();
    void on_six_button_clicked();
    void on_seven_button_clicked();
    void on_eight_button_clicked();
    void on_nine_button_clicked();
    void on_zero_button_clicked();

    void on_dot_button_clicked();   
    void on_plusminus_button_clicked();
    void on_plus_button_clicked();
    void on_minus_button_clicked();
    void on_multiply_button_clicked();
    void on_divide_button_clicked();
    void on_sqrt_button_clicked();
    void on_equal_button_clicked();
    void on_power_button_clicked();

    void on_backspace_button_clicked();
    void on_clear_button_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton *one_button;
    QPushButton *two_button;
    QPushButton *three_button;
    QPushButton *four_button;
    QPushButton *five_button;
    QPushButton *six_button;
    QPushButton *seven_button;
    QPushButton *eight_button;
    QPushButton *nine_button;
    QPushButton *zero_button;
    QPushButton *dot_button;
    QPushButton *reset_button;
    QPushButton *ac_button;
    QPushButton *plus_button;
    QPushButton *minus_button;
    QPushButton *multiply_button;
    QPushButton *divide_button;
    QPushButton *equal_button;
    QPushButton *sqrt_button;
    QPushButton *plusminus_button;

    Core *core;
    double operand;
    bool operatorClicked = false;
    enum Operation {plus, minus, multiply, divide, squareRoot, power};
};

#endif // MAINWINDOW_H
