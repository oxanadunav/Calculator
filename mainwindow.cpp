#include "mainwindow.h"
#include "ui_gui.h"
#include <iostream>
#include <Core.h>
#include <math.h>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::performOperation(int operation) {
    operatorClicked = true;
    operand = ui->textEdit->toPlainText().toDouble();

    Core::getInstance()->calculate(operand, operation);

    double result = Core::getInstance()->getResult();
    ui->textEdit->setText(QString::number(result));
}

void MainWindow::insertNumber(QString string) {
    Core::getInstance()->setOperatorClicked(true);
    if(operatorClicked){
        ui->textEdit->setText("");
        operatorClicked = false;
    }
    ui->textEdit->setText(ui->textEdit->toPlainText() + string);
}


//Slots

void MainWindow::on_one_button_clicked() {
    insertNumber(ui->one_button->text());
}

void MainWindow::on_two_button_clicked() {
    insertNumber(ui->two_button->text());
}

void MainWindow::on_three_button_clicked() {
    insertNumber(ui->three_button->text());
}

void MainWindow::on_four_button_clicked() {
    insertNumber(ui->four_button->text());
}

void MainWindow::on_five_button_clicked() {
    insertNumber(ui->five_button->text());
}

void MainWindow::on_six_button_clicked() {
    insertNumber(ui->six_button->text());
}

void MainWindow::on_seven_button_clicked() {
    insertNumber(ui->seven_button->text());
}

void MainWindow::on_eight_button_clicked() {
    insertNumber(ui->eight_button->text());
}

void MainWindow::on_nine_button_clicked() {
    insertNumber(ui->nine_button->text());
}

void MainWindow::on_dot_button_clicked() {
    insertNumber(ui->dot_button->text());
}

void MainWindow::on_zero_button_clicked() {
    insertNumber(ui->zero_button->text());
}

void MainWindow::on_plusminus_button_clicked() {
    QString string = ui->textEdit->toPlainText();
    if(string.contains('-') && string.size() > 0){
        string.replace("-", "");
    }else{
        string = "-" + string;
    }

    ui->textEdit->setText(string);
}

void MainWindow::on_plus_button_clicked() {
    performOperation(0);
}

void MainWindow::on_minus_button_clicked() {
    performOperation(1);
}

void MainWindow::on_multiply_button_clicked() {
    performOperation(2);
}

void MainWindow::on_divide_button_clicked() {
    performOperation(3);
}

void MainWindow::on_sqrt_button_clicked() {

    operand = ui->textEdit->toPlainText().toDouble();
    double result = sqrt(operand);
    ui->textEdit->setText(QString::number(result));

}

void MainWindow::on_equal_button_clicked() {
    performOperation(5);
    operatorClicked = true;
    Core::getInstance()->clear();
}

void MainWindow::on_power_button_clicked() {
    operand = ui->textEdit->toPlainText().toDouble();
    double result = pow(operand,2);
    ui->textEdit->setText(QString::number(result));
}

void MainWindow::on_backspace_button_clicked() {
    QString string = ui->textEdit->toPlainText();
    string.remove(string.length() - 1, 1);
    ui->textEdit->setText(string);
}

void MainWindow::on_clear_button_clicked()  {
    Core::getInstance()->clear();
    ui->textEdit->setText("");
}
