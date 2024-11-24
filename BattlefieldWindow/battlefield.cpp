#include "battlefield.h"
#include "ui_battlefield.h"

Battlefield::Battlefield(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Battlefield)
{
    ui->setupUi(this);

    battlefield = new QGraphicsScene;
    ui->graphicsView->setScene(battlefield);

    unitCharacter::CharacterProperties charProperties;
    charProperties.name = "Равиль";
    charProperties.surname = "Абдуллин";
    charProperties.department = "ОУОС";
    charProperties.charSpecialTrick = "Я художник, я так вижу!";
    charProperties.specialTrickUses = "INFINITE";
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

    newUnit->setPos(25, 75);
}

Battlefield::~Battlefield()
{
    delete ui;
}
