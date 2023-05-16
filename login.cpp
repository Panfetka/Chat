#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_pressed()
{
    ip=ui->ip->text();
    name=ui->nickname->text();
    accept();
}

void Login::on_Color_clicked()
{

}

