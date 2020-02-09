#include "person.h"
#include "ui_person.h"
#include<QSqlQuery>
#include<QTextCharFormat>
#include<QCalendarWidget>
#include<QProgressBar>

Person::Person(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Person)
{
    ui->setupUi(this);
}
void Person::init(QString sno, QString sname)
{
    ui->label->setText("学号： "+sno);
       ui->label_2->setText("姓名： "+sname);
       QSqlQuery q;
       q.exec(QString("select count(*),date_format(now(),'%d') from signinfo "
                                " where sno='%1' and date_format(signtime,'%y-%m')="
                                " date_format(now(),'%y-%m') ").arg(sno));
       q.next();
       ui->label_3->setText("签到次数: "+q.value(0).toString());
       ui->progressBar->setRange(0,q.value(1).toInt());
       ui->progressBar->setValue(q.value(0).toInt());
       QSqlQuery s;
       QTextCharFormat f;
       f.setBackground(Qt::green);
       f.setForeground(Qt::black);
       s.exec(QString("select signtime from signinfo where sno = %1").arg(sno));
       while(s.next()){
          ui->calendarWidget->setDateTextFormat(s.value(0).toDate(),f);

 }
}

Person::~Person()
{
    delete ui;
}
