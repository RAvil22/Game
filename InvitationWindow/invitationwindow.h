#ifndef INVITATIONWINDOW_H
#define INVITATIONWINDOW_H

#include <QWidget>

namespace Ui {
class InvitationWindow;
}

class InvitationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit InvitationWindow(QWidget *parent = nullptr);
    ~InvitationWindow();

private:
    Ui::InvitationWindow *ui;
};

#endif // INVITATIONWINDOW_H
