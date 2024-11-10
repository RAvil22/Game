#ifndef GAMESETTINSWINDOW_H
#define GAMESETTINSWINDOW_H

#include <QWidget>

namespace Ui {
class GameSettingsWindow;
}

class GameSettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameSettingsWindow(QWidget *parent = nullptr);
    ~GameSettingsWindow();

private:
    Ui::GameSettingsWindow *ui;
};

#endif // GAMESETTINSWINDOW_H
