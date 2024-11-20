#include "battlefield.h"
#include "ui_battlefield.h"

Battlefield::Battlefield(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Battlefield)
{
    ui->setupUi(this);

    battlefield = new QGraphicsScene;
    ui->graphicsView->setScene(battlefield);

    // Unit* newUnit = new Unit();
    // playerUnits.append(newUnit);

    // battlefield->addItem(newUnit);

    // newUnit->setPos(50,50);
}

Battlefield::~Battlefield()
{
    delete ui;
}
