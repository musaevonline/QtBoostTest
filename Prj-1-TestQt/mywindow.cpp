#include "mywindow.h"
MyWindow::MyWindow(QWidget *parent) :QDialog(parent)
{
    setWindowTitle("Test");

    l1=new QLabel("Enter");
    le1=new QLineEdit;

    cb1=new QCheckBox("Верхний регистр");
    cb2=new QCheckBox("Инверсия");

    ok=new QPushButton("ОК");
    ok->setDefault(true);
    ok->setEnabled(false);
    close=new QPushButton("Выход");

    QHBoxLayout *Hlabel1=new QHBoxLayout;
    Hlabel1->addWidget(l1);
    Hlabel1->addWidget(le1);

    QVBoxLayout *Vlabel1=new QVBoxLayout;
    Vlabel1->addLayout(Hlabel1);
    Vlabel1->addWidget(cb1);
    Vlabel1->addWidget(cb2);

    QVBoxLayout *Vlabel2=new QVBoxLayout;
    Vlabel2->addWidget(ok);
    Vlabel2->addWidget(close);

    QHBoxLayout *Hlabel2=new QHBoxLayout;
    Hlabel2->addLayout(Vlabel1);
    Hlabel2->addLayout(Vlabel2);

    setLayout(Hlabel2);
    connect(le1,SIGNAL(textChanged(QString)),this,SLOT(TextChanged(QString)));
    connect(close,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ok,SIGNAL(clicked(bool)),this,SLOT(OkCkicked()));
}

void MyWindow::TextChanged(QString str)
{
    ok->setEnabled(!str.isEmpty());
}

void MyWindow::OkCkicked()
{
    if(!cb1->isChecked() && !cb2->isChecked())
        emit Simple(le1->text());
    else if(cb1->isChecked() && cb2->isChecked())
        emit Full(le1->text());
    else
    {
    if(cb1->isChecked())
        emit Register(le1->text());
    if(cb2->isChecked())
        emit Inverse(le1->text());
    }
}

void message(QString str)
{
    QMessageBox msg;
    msg.setText(str);
    msg.exec();
}

QString inverse(QString str)
{
    QString result=str;
    for(int i=str.size()-1,j=0;i>=0;j++,i--)
    {
        result[j]=str[i];
    }
    return result;
}

void Str::Simple(QString str)
{
message(str);
}

void Str::Inverse(QString str)
{
message(inverse(str));
}
void Str::Register(QString str)
{
message(str.toUpper());
}

void Str::Full(QString str)
{
message(inverse(str).toUpper());
}
/////////
