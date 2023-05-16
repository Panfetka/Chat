#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    Ui::Login *ui;
    QString ip;
    QString name;
private slots:
    void on_pushButton_pressed();
    void on_Color_clicked();
};

#endif // LOGIN_H
