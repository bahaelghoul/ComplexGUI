#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ok_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_sum_clicked();

    void on_pushButton_clear_result_clicked();

    void on_pushButton_sub_clicked();

    void on_pushButton_div_clicked();

    void on_pushButton_mul_clicked();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
