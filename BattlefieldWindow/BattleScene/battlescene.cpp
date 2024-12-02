#include "battlescene.h"

using namespace std;

BattleScene::BattleScene(QObject *parent)
    : QGraphicsScene{parent}
{
    setItemIndexMethod(QGraphicsScene::NoIndex);

    background = new QBrush;

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

    newUnit = new Unit(charProperties);
    playerUnits.append(newUnit);


    this->addItem(newUnit);

    currentUnit = newUnit;

    updateTimer = new QTimer();
    updateTimer->setInterval(500);

    connect(updateTimer, &QTimer::timeout, this, &BattleScene::advance);
    //updateTimer->start();
}

void BattleScene::setTextureImage(QImage image)
{
    background->setTextureImage(image);
    setBackgroundBrush(*background);
}

void BattleScene::setBattleSceneSize(QSize size)
{
    setSceneRect(0,0, size.width(), size.height());
}

void BattleScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        currentUnit->makeAction(UNIT_MOVE, event->scenePos());
    }
    else if(event->button() == Qt::RightButton){
    }
    else;
}

bool BattleScene::moveCurrentUnit(const QPointF &pos){
    return currentUnit->makeAction(UNIT_MOVE, pos);
}


