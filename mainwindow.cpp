#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Login l(this);
    connect(&l, &QDialog::accepted,
            this, &MainWindow::onConnect);
    l.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onRead()
{
    while(socket.bytesAvailable())
    {
        QString str = socket.readAll();
        auto l = str.split('#');
        qDebug()<<l;
        auto m=new Message(l[0], QColor(200,0,0), l[1]);
        m->setLayoutDirection(Qt::LeftToRight);
        ui->chat->layout()->addWidget(m);

    }
}

void MainWindow::onConnect()
{
    auto l = qobject_cast<Login*>(sender());
    name = l->name;
//    color = l->color
    socket.connectToHost(l->ip, 6000);
    qDebug()<<socket.isWritable();
    connect(&socket, &QTcpSocket::readyRead,
            this, &MainWindow::onRead);
}


void MainWindow::on_send_pressed()
{
    socket.write(name.toLocal8Bit());
    socket.write("#");
    auto str=ui->text->toPlainText();
    socket.write(str.toLocal8Bit());

    auto m=new Message(name, QColor(200,0,0), str);
    ui->chat->layout()->addWidget(m);
    m->setLayoutDirection(Qt::RightToLeft);
    ui->text->clear();


}

