#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <QWidget>
#include <QList>
#include <QGraphicsScene>

#include "department.h"
#include "specialtrick.h"
#include "battlescene.h"

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
    BattleScene* battleScene;
};

#endif // BATTLEFIELD_H
