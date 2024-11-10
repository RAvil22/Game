#ifndef GAME_H
#define GAME_H

#include <QObject>

#include <memory>

#include "startwindow.h"
//#include "gamesettinswindow.h"
//#include "invitationwindow.h"
//#include "battlefield.h"

using namespace std;

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);

signals:

private:
    unique_ptr<StartWindow> startWin;
    //unique_ptr<GameSettinsWindow> GameSetsWin;
    //unique_ptr<InvitationWindow> InvitWin;
    //unique_ptr<Battlefield> battlefield;
};

#endif // GAME_H
