#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTcpSocket>
#include <QMainWindow>
#include "message.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onRead();
    void onConnect();
    void on_send_pressed();

private:
    Ui::MainWindow *ui;
    QTcpSocket socket;
    QString name;
    QColor color;
};

#endif // MAINWINDOW_H
