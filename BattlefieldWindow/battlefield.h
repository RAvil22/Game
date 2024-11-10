#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <QWidget>

namespace Ui {
class Battlefield;
}

class Battlefield : public QWidget
{
    Q_OBJECT

public:
    explicit Battlefield(QWidget *parent = nullptr);
    ~Battlefield();

private:
    Ui::Battlefield *ui;
};

#endif // BATTLEFIELD_H
