#include "gamesettinswindow.h"
#include "ui_gamesettinswindow.h"

GameSettinsWindow::GameSettinsWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameSettinsWindow)
{
    ui->setupUi(this);
}

GameSettinsWindow::~GameSettinsWindow()
{
    delete ui;
}
