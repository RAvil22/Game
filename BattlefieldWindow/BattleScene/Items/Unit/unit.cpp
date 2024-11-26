#include "unit.h"

#include <QPainter>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>

Unit::Unit(unitCharacter::CharacterProperties properties, QObject *parent)
    : QObject{parent}
{
    character_ = new unitCharacter::Character(properties);
    setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsMovable);
    //setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsSelectable);
    one = new QPixmap("walk1.png");
    two = new QPixmap("walk2.png");
    one->scaled(40,40, Qt::KeepAspectRatio);
    two->scaled(40,40, Qt::KeepAspectRatio);
}

Unit::~Unit()
{
    if(character_)delete character_;
}

QRectF Unit::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void Unit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRoundedRect(0, 0, 20, 20, 5, 5);
    if(!currentPix)painter->drawPixmap(0,0, 50, 50, *one);
    else painter->drawPixmap(0,0,50,50, *two);
}

// bool Unit::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
// {

// }

// bool Unit::collidesWithPath(const QPainterPath &path, Qt::ItemSelectionMode mode) const
// {

// }



void Unit::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Press unit" <<this->scenePos() << currentPix;
    if(!currentPix)currentPix = 1;
    else currentPix = 0;
}

// void Unit::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
// {
//     qDebug() << "End" <<this->scenePos();
// }
