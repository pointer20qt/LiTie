#include "reg.h"
#include "ui_reg.h"
#include<QSqlQuery>
#include<QString>
#include<QMessageBox>
#include <QSqlDatabase>
#include <QDebug>

Reg::Reg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reg)
{
    ui->setupUi(this);
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("20_sign");
    db.setUserName("root");
    db.setPassword("123456");
    if(db.open()){
        qDebug()<<"打开数据库成功";
    }
    else{
        qDebug()<<"打开数据库失败";
    }
}

Reg::~Reg()
{
    delete ui;
}

void Reg::on_pushButton_clicked()
{
    QString usersno=ui->lineEdit->text();
    QString username=ui->lineEdit_2->text();
    QString userclass=ui->lineEdit_3->text();
    QString userpwd=ui->lineEdit_4->text();
    QString i=QString("insert into student values('%1','%2','%3','%4');").arg(usersno).arg(username).arg(userclass).arg(userpwd);
    QSqlQuery q;
    if(q.exec(i)){
        QMessageBox::information(this,"注册成功","注册成功!");
    }
    else{
        QMessageBox::warning(this,"warn","注册失败！");
    }
    this->close();

}
