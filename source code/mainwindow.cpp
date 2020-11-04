#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "complex.h"
#include <QString>
#include "about.h"
float real_1;
float real_2;
float im_1;
float im_2;
float mod_1;
float arg_1;
float mod_2;
float arg_2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ok_clicked()
{
    real_1= ui->lineEdit_real_1->text().toFloat();
    real_2=ui->lineEdit_real_2->text().toFloat();
    im_1=ui->lineEdit_imaginary_1->text().toFloat();
    im_2=ui->lineEdit_imaginary_2->text().toFloat();
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->lineEdit_real_1->clear();
    ui->lineEdit_real_2->clear();
    ui->lineEdit_imaginary_1->clear();
    ui->lineEdit_imaginary_2->clear();
}


void MainWindow::on_pushButton_sum_clicked()
{
    if(add(real_1,real_2)==0&&add(im_1,im_2)==0)
        ui->result->insertPlainText("The sum is equal to 0\n");
    else if(add(im_1,im_2)<0)
    {
        QString sum=QString::number(add(real_1,real_2)) + " - i"+ QString::number(-add(im_1,im_2));
        ui->result->insertPlainText("The sum is equal to : "+ sum +"\n");
    }
    else
    {
        QString sum=QString::number(add(real_1,real_2)) + " + i"+ QString::number(add(im_1,im_2));
        ui->result->insertPlainText("The sum is equal to : "+ sum +"\n");
    }
}


void MainWindow::on_pushButton_clear_result_clicked()
{
    ui->result->clear();
}

void MainWindow::on_pushButton_sub_clicked()
{
    if(substract(real_1,real_2)==0&&substract(im_1,im_2)==0)
        ui->result->insertPlainText("The substraction is equal to 0\n");
    else if (substract(im_1,im_2)<0)
    {
        QString sub=QString::number(substract(real_1,real_2)) + " - i"+ QString::number(-substract(im_1,im_2));
        ui->result->insertPlainText("The substraction is equal to : "+ sub +"\n");
    }
    else
    {
        QString sub=QString::number(substract(real_1,real_2)) + " - i"+ QString::number(substract(im_1,im_2));
        ui->result->insertPlainText("The substraction is equal to : "+ sub +"\n");
    }
}

void MainWindow::on_pushButton_div_clicked()
{
    float mod_res,arg_res,real_res,im_res;
    forme_exponentielle(mod_1,arg_1,real_1,im_1);
    forme_exponentielle(mod_2,arg_2,real_2,im_2);
    mod_res=mod_1/mod_2;
    arg_res=arg_1-arg_2;
    forme_algebrique(mod_res,arg_res,real_res,im_res);
    if(mod_res==0)
        ui->result->insertPlainText("The division is equal to 0\n");
    else if (im_res<0)
    {
        QString div=QString::number(real_res) + " - i"+ QString::number(-im_res);
        ui->result->insertPlainText("The division is equal to : "+ div +"\n");
    }
    else
    {
        QString div=QString::number(real_res) + " + i"+ QString::number(im_res);
        ui->result->insertPlainText("The division is equal to : "+ div +"\n");
    }
}

void MainWindow::on_pushButton_mul_clicked()
{
    float mod_res,arg_res,real_res,im_res;
    forme_exponentielle(mod_1,arg_1,real_1,im_1);
    forme_exponentielle(mod_2,arg_2,real_2,im_2);
    mod_res=mod_1*mod_2;
    arg_res=arg_1+arg_2;
    forme_algebrique(mod_res,arg_res,real_res,im_res);
    if(mod_res==0)
        ui->result->insertPlainText("The multiplication is equal to 0\n");
    else if (im_res<0)
    {
        QString mul=QString::number(real_res) + " - i"+ QString::number(-im_res);
        ui->result->insertPlainText("The multiplication is equal to : "+ mul +"\n");
    }
    else
    {
        QString mul=QString::number(real_res) + " + i"+ QString::number(im_res);
        ui->result->insertPlainText("The multiplication is equal to : "+ mul +"\n");
    }
}

void MainWindow::on_actionAbout_triggered()
{
    About about;
    about.setModal(true);
    about.exec();
}
