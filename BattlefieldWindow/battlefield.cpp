#include "battlefield.h"
#include "ui_battlefield.h"

#include <QDebug>

Battlefield::Battlefield(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Battlefield)
{
    ui->setupUi(this);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheNone);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    battleScene = new BattleScene();
    ui->graphicsView->setScene(battleScene);

}

Battlefield::~Battlefield()
{
    delete battleScene;
    delete ui;
}
