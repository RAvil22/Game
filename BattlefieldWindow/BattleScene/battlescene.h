#ifndef BATTLESCENE_H
#define BATTLESCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QBrush>
#include <QTimer>
#include <QDebug>

#include "items.h"


class BattleScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit BattleScene(QObject *parent = nullptr);

public slots:

signals:

protected:
    // void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QBrush* background;

    QList<Unit*> playerUnits;
    QList<Unit*> opponentUnits;
    Unit* currentUnit;

private slots:
};

#endif // MAPSCENE_H


