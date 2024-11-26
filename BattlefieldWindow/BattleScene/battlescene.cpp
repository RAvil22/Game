#include "battlescene.h"

#include <QImageReader>
#include <cmath>


using namespace std;

BattleScene::BattleScene(QObject *parent)
    : QGraphicsScene{parent}
{
    setItemIndexMethod(QGraphicsScene::NoIndex);

    background = new QBrush;
    background->setTextureImage(QImage("WorldMap.jpg"));
    setBackgroundBrush(*background);

    QImageReader reader("WorldMap.jpg");
    QSize sizeOfImage = reader.size();
    setSceneRect(0,0, sizeOfImage.width(), sizeOfImage.height());

    unitCharacter::CharacterProperties charProperties;
    charProperties.name = "Равиль";
    charProperties.surname = "Абдуллин";
    charProperties.department = "ОУОС";
    charProperties.charSpecialTrick = "Я художник, я так вижу!";
    charProperties.specialTrickUses = UINT32_MAX;
    charProperties.strength = 10;
    charProperties.dextrerity = 10;
    charProperties.reaction = 10;
    charProperties.initialRage = 5;
    charProperties.initialHealth = 100;
    charProperties.initialMorale = 100;
    charProperties.initialTiredness = 0;

    Unit* newUnit = new Unit(charProperties);
    playerUnits.append(newUnit);

    this->addItem(newUnit);

    newUnit->setPos(50, 100);
    qDebug() << "New unit position" << newUnit->scenePos();
}

// void BattleScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
//     if(event->button() == Qt::LeftButton){
//         qDebug() << "Left button scene";
//     }
//     else if(event->button() == Qt::RightButton){
//         qDebug() << "Right button scene";
//     }
// }


