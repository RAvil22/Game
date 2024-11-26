#ifndef UNIT_H
#define UNIT_H

#include <QGraphicsItem>
#include <QPointF>
#include <QPixmap>
#include <QObject>
#include <QTimer>
#include <QList>
#include <QPixmap>

#include "character.h"

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
signals:
private slots:
    void choosePix(void){if(!currentPix)currentPix = 1;else currentPix = 0;}
private:
    unitCharacter::Character* character_;
    QTimer animationTimer;
    uint8_t currentPix{0};
    // QPixmap* one;
    // QPixmap* two;

};

#endif // UNIT_H
