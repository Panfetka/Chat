#include "message.h"
#include "ui_message.h"

Message::Message(QString name, QColor color, QString text, QWidget *parent):
    QFrame(parent), ui(new Ui::Message)
{
    ui->setupUi(this);
    ui->name->setText(name);
    ui->message->setText(text);
//    QPalette pal=palette();
//    pal.setColor(QPalette::WindowText, color);
//    ui->message->setPalette(pal);
    ui->message->setStyleSheet("QLabel { color :" +color.name()+ "; background-color: rgb(255, 174, 210);}");
    ui->name->setStyleSheet("QLabel { color :" +color.name()+ "; background-color: rgb(255, 174, 210);}");

}

Message::~Message()
{
    delete ui;
}
