#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//C++ refrences
#include <QPixmap>
#include <QMainWindow>
#include <QString>
#include <QRadioButton>
#include "zork.h"
#include "player.h"
#include "text.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //global variable
    int doNotUse;
private slots:

    void on_up_clicked();

    void on_right_clicked();

    void on_down_clicked();

    void on_left_clicked();

    void on_item2_clicked();

    void on_item1_clicked();









    void on_end_clicked();

private:
    Zork* Game;
    Text* Dialog;
    Ui::MainWindow *ui;
    Room* currentRoom;
    void createRooms();
    void display();
    void inv();
    void Displayinv();

    vector <QRadioButton*> buttons;

    friend vector <Item> Room::getItem();
    vector <Item> bag;
    vector <Item> tory;
    Player* Me;
    void checkRoom();

};
#endif // MAINWINDOW_H
