#ifndef MYWINDOW_H
#define MYWINDOW_H

#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QCheckBox>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QMessageBox>

class MyWindow: public QDialog
{
    Q_OBJECT;
public:
    MyWindow(QWidget *parent=0);

private:
    QLabel *l1;
    QLineEdit *le1;
    QCheckBox *cb1;
    QCheckBox *cb2;
    QPushButton *ok;
    QPushButton *close;

private slots:
    void OkCkicked();
    void TextChanged(QString str);

signals:
    void Register(QString str);
    void Inverse(QString str);
    void Simple(QString str);
    void Full(QString str);
};

class Str : public QObject
{

    Q_OBJECT
private :
    QString str;

public slots:
    void Simple(QString str);
    void Inverse(QString str);
    void Register(QString str);
    void Full(QString str);
};

#endif // MYWINDOW_H
