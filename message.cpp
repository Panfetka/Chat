#include "message.h"
#include "ui_message.h"

Message::Message(QString name, QColor color, QString text, QWidget *parent):
    QFrame(parent), ui(new Ui::Message)
{
    ui->setupUi(this);
    ui->name->setText(name);
    ui->message->setText(text);
    QPalette pal=palette();
    pal.setColor(QPalette::WindowText, color);
    setPalette(pal);
}

Message::~Message()
{
    delete ui;
}
