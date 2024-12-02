#include "unit.h"

#include <QPainter>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>

#include <QThread>
#include <QFuture>
#include <QtConcurrent>

Unit::Unit(unitCharacter::CharacterProperties properties, QObject *parent)
    : QObject{parent}
{
    character_ = new unitCharacter::Character(properties);
    setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsMovable);
    setFlag(QGraphicsItem::GraphicsItemFlag::ItemIsSelectable);
    walkPixmaps = new AnimationPixmaps();
    walkPixmaps->appendPixmap("walk1.png");
    walkPixmaps->appendPixmap("walk2.png");
    currentPixmap = walkPixmaps->getPixmap(0);

    testTimer.setInterval(500);
    connect(&testTimer, &QTimer::timeout, this, &Unit::repaintUnit);
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
    // painter->eraseRect(0,0, 50, 50);
    painter->drawPixmap(0,0, 50, 50, *currentPixmap);
    if(currentPhase)painter->setBrush(Qt::red);
    else painter->setBrush(Qt::green);
    painter->drawRoundedRect(0, 0, 20, 20, 5, 5);
}

// bool Unit::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
// {

// }

// bool Unit::collidesWithPath(const QPainterPath &path, Qt::ItemSelectionMode mode) const
// {

// }



void Unit::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Press unit" <<this->scenePos() << currentPhase;
}

bool Unit::makeAction(unsigned int actionType, QPointF position){
    // switch (actionType) {
    // case UNIT_MOVE:{
    //     QFuture<bool> moveResult = QtConcurrent::run(&Unit::move, this, position);
    //     return moveResult.result();
    //     // return move(position);
    //     break;
    // }
    // default:
    //     break;
    // }
    testTimer.start();
    return true;
}

void Unit::repaintUnit()
{
    setPos(this->scenePos().x() + 100, this->scenePos().y() + 100);
    currentPixmap = walkPixmaps->nextPixmap();
    qDebug() << "Repaint" << this->scenePos();
}

bool Unit::move(QPointF newPosition){
    //Проверка на усталость.
    int xStep{currentPosition.x() > newPosition.x() ? -50 : 50};
    int yStep{currentPosition.y() > newPosition.y() ? -50 : 50};

    qDebug() << currentPosition << newPosition;
    while(currentPosition != newPosition){
        if(std::abs(newPosition.x() - currentPosition.x()) < xStep)xStep = newPosition.x() - currentPosition.x();
        if(std::abs(newPosition.y() - currentPosition.y()) < yStep)yStep = newPosition.y() - currentPosition.y();
        currentPosition.setX(currentPosition.x() + xStep);
        currentPosition.setY(currentPosition.y() + yStep);
        // animation->setPosAt(1 ,currentPosition);
        setPos(currentPosition);
        if(currentPhase);
        else currentPhase = 1;
        qDebug() << currentPosition;
        QThread::msleep(500);

    }
    return true;
}

void Unit::advance(int phase)
{
    if(!phase)return;

    setPos(scenePos().x() + 25, scenePos().y() + 25);
}

// void Unit::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
// {
//     qDebug() << "End" <<this->scenePos();
// }
