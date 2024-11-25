#include "battlefield.h"
#include "ui_battlefield.h"

#include <QDebug>

Battlefield::Battlefield(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Battlefield)
{
    ui->setupUi(this);

    battlefield = new QGraphicsScene;
    ui->graphicsView->setScene(battlefield);
    battlefield->setSceneRect(ui->graphicsView->maximumViewportSize().width() * (-0.5), ui->graphicsView->maximumViewportSize().height() * (-0.5),
                              ui->graphicsView->maximumViewportSize().width(), ui->graphicsView->maximumViewportSize().height());
    qDebug() << battlefield->sceneRect();

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

    battlefield->addItem(newUnit);

    qDebug() << newUnit->scenePos();
    newUnit->setPos(0, 0);
    qDebug() << newUnit->scenePos();
}

Battlefield::~Battlefield()
{
    delete ui;
}
