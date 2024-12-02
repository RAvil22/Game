#include "battlefield.h"
#include "ui_battlefield.h"

#include <QDebug>
#include <QImageReader>

Battlefield::Battlefield(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Battlefield)
{
    ui->setupUi(this);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheNone);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    QImageReader reader("WorldMap.jpg");
    QSize sizeOfImage = reader.size();

    battleScene = new BattleScene();
    battleScene->setTextureImage(QImage("WorldMap.jpg"));
    battleScene->setBattleSceneSize(sizeOfImage);

    ui->graphicsView->setScene(battleScene);

}

Battlefield::~Battlefield()
{
    delete battleScene;
    delete ui;
}
