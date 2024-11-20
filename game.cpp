#include "game.h"

Game::Game(QObject *parent)
    : QObject{parent}
{
    serverConnection = new QTcpSocket();

    startWin = new StartWindow();
    //gameSetsWin = new GameSettingsWindow();
    invitWin = new InvitationWindow();
    battlefield = new Battlefield();

    //startWin->show();
    //gameSetsWin->show();
    //invitWin->show();
    battlefield->show();
}

void Game::makeStartWinConnects()
{
    connect(startWin, &StartWindow::playerName, this, &Game::setPlayerName);
}

void Game::makeGameSetsWinConnects()
{

}

void Game::makeInvWinConnects()
{

}

void Game::makeBattleWinConnects()
{

}

void Game::setPlayerName(QString name)
{
    this->playerNickname = name;
}

