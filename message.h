#ifndef MESSAGE_H
#define MESSAGE_H

#include <QFrame>

namespace Ui {
class Message;
}

class Message : public QFrame
{
    Q_OBJECT

public:
    explicit Message(QString name = "defoult", QColor color = QColor(200,0,0), QString text = "DEFOULT", QWidget *parent = nullptr);
    ~Message();

private:
    Ui::Message *ui;
};

#endif // MESSAGE_H
