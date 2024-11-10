#ifndef GAMESETTINSWINDOW_H
#define GAMESETTINSWINDOW_H

#include <QWidget>

namespace Ui {
class GameSettinsWindow;
}

class GameSettinsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameSettinsWindow(QWidget *parent = nullptr);
    ~GameSettinsWindow();

private:
    Ui::GameSettinsWindow *ui;
};

#endif // GAMESETTINSWINDOW_H
