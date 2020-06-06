#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QFileDialog"
#include "QPixmap"
#include"QMessageBox"
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


void MainWindow::on_pushButton_clicked()
{
    QString file_name= QFileDialog::getOpenFileName(this,"Open a file","/home");
    QMessageBox::information(this,"..",file_name);
   ui->label->setPixmap(file_name);
}
