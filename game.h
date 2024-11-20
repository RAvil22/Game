#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QString>

#include "startwindow.h"
//#include "gamesettingswindow.h"
#include "invitationwindow.h"
#include "battlefield.h"

using namespace std;

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);

signals:

private:
    StartWindow* startWin;
    //GameSettingsWindow* gameSetsWin;
    InvitationWindow* invitWin;
    Battlefield* battlefield;

    QTcpSocket* serverConnection;

    void makeStartWinConnects(void);
    void makeGameSetsWinConnects(void);
    void makeInvWinConnects(void);
    void makeBattleWinConnects(void);

    QString playerNickname;
    uint64_t passwordHash{0};

private slots:
    ///StartWinSlots
    void setPlayerName(QString name);
};

#endif // GAME_H
