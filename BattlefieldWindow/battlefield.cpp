#include "battlefield.h"
#include "ui_battlefield.h"

Battlefield::Battlefield(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Battlefield)
{
    ui->setupUi(this);
}

Battlefield::~Battlefield()
{
    delete ui;
}
