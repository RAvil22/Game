#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <QWidget>
#include <QList>
#include <QGraphicsScene>



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
    QGraphicsScene* battlefield;
    // QList<Unit*> playerUnits;
    // QList<Unit*> opponentUnits;
    // Unit* currentUnit;
};

#endif // BATTLEFIELD_H
