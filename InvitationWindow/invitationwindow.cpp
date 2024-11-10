#include "invitationwindow.h"
#include "ui_invitationwindow.h"

InvitationWindow::InvitationWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InvitationWindow)
{
    ui->setupUi(this);
}

InvitationWindow::~InvitationWindow()
{
    delete ui;
}
