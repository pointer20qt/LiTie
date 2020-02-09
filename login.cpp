#include "login.h"
#include "ui_login.h"
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<Widget.h>
#include<QMessageBox>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include<reg.h>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
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
    setStyleSheet(
                       "QPushButton{"
                       "background-color:rgba(100,225,100,30);"
                       "border-style:inset;"
                       "border-width:4px;"
                       "border-radius:10px;"
                       "border-color:rgba(255,255,255,30);"
                       "font:bold 18px;"
                       "color:red;"
                       "padding:6px;"
                       "}"
                       "QPushButton:pressed{"
                       "background-color:rgba(100,255,100,200);"
                       "border-color:rgba(255,255,255,30);"
                       "border-style:inset;"
                       "color:rgba(0,0,0,100);"
                       "}"
                       "QPushButton:hover{"
                       "background-color:rgba(100,255,100,100);"
                       "border-color:rgba(255,255,255,200);"
                       "color:rgba(0,0,0,200);"
                       "}");

}

login::~login()
{
    delete ui;
}

void login::on_loginButton_clicked()
{
    QString sname=ui->userEdit->text();
    QString pwd=ui->pwdEdit->text();
    QSqlQuery q;
    q.exec(QString("select * from student where sname='%1'").arg(sname));
    if(q.size()>0){
       q.exec(QString("select * from student where sname='%1' and pwd='%2'").arg(sname).arg(pwd));
       if(q.size()>0){
           Widget *w=new Widget(NULL,sname);
           w->show();
           this->close();
       }
       else{
          QMessageBox::warning(this,"warn","密码错误");
       }
    }
    else{
        QMessageBox::warning(this,"warn","用户不存在");
    }
}


void login::on_pushButton_clicked()
{
     Reg *r=new Reg();
     r->show();
}
