#ifndef UNIT_H
#define UNIT_H

#include <QGraphicsItem>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QPointF>
#include <QPixmap>
#include <QObject>
#include <QTimer>
#include <QList>
#include <QPixmap>
#include <QList>

#include "character.h"
#include "animationpixmaps.h"

enum availableUnitActions{UNIT_MOVE, UNIT_ATTACK, UNIT_DEFEND};



class Unit : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Unit(unitCharacter::CharacterProperties properties, QObject *parent = nullptr);
    ~Unit();

    QRectF boundingRect(void) const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    // bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;
    // bool collidesWithPath(const QPainterPath &path, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    // void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    bool makeAction(unsigned int actionType, QPointF position);
signals:

private slots:
    void repaintUnit();
private:
    unitCharacter::Character* character_;
    uint8_t currentPhase{0};
    QPixmap* currentPixmap;
    AnimationPixmaps* walkPixmaps;
    QPointF currentPosition;

    QTimeLine* animationTimeLine;
    QGraphicsItemAnimation *animation;

    bool move(QPointF newPosition);

    QTimer testTimer;
protected:
    void advance(int phase) override;
};

#endif // UNIT_H
