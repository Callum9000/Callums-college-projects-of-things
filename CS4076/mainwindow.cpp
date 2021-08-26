#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
//init list
    : QMainWindow(parent)
    , Game(new Zork), Dialog(new Text()), ui(new Ui::MainWindow), Me(new Player("boy"))
{

    ui->setupUi(this);
    buttons.push_back(ui->inv1);
    buttons.push_back(ui->inv2);
    buttons.push_back(ui->inv3);
    buttons.push_back(ui->inv4);
    buttons.push_back(ui->inv5);
    buttons.push_back(ui->inv6);
    ui->textOut->append(QString::fromStdString(Dialog->date()));
    ui->textOut->append(QString::fromStdString(Dialog->change()));
    ui->textOut->append(QString::fromStdString(Dialog->obj()));

    display();



}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display(){
    QPixmap pic(QString::fromStdString(":/img/" + Game->getRoom()->shortDescription() + ".jpg"));
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));
    ui->label->setAlignment(Qt::AlignCenter);
}
void MainWindow::inv(){
    bag = Game->getRoom()->getItem();
    vector <QPushButton*> invbutton;
    invbutton.push_back(ui->item1);
    invbutton.push_back(ui->item2);

    for(QPushButton *x: invbutton ){
    if(bag.size() > 0){
     x->setEnabled(true);
     QPixmap pic(QString::fromStdString(":/img/" + bag.front().getShortDescription() + ".png"));
     x->setIcon(pic);
     x->setIconSize(QSize(65, 65));
    bag.erase(bag.begin());
    }
    else{
          QPixmap pic("");
          x->setIcon(pic);
          x->setEnabled(false);
        }

    }

}


void MainWindow::on_up_clicked()
{

    ui->textOut->append(QString::fromStdString(Game->go("north")));
    display();
    inv();
}

void MainWindow::on_right_clicked()
{
    ui->textOut->append(QString::fromStdString(Game->go("east")));
    display();
    inv();
}

void MainWindow::on_down_clicked()
{
    ui->textOut->append(QString::fromStdString(Game->go("south")));
    display();
    inv();
}

void MainWindow::on_left_clicked()
{
    ui->textOut->append(QString::fromStdString(Game->go("west")));
    display();
    inv();

}

void MainWindow::Displayinv(){


    tory = Me->getItems();
    if(tory.size() == 6){
        QPixmap pic(QString::fromStdString(":/img/end.jpg"));
        int w = ui->label->width();
        int h = ui->label->height();
        ui->label->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));
        ui->label->setAlignment(Qt::AlignCenter);

        ui->right->setEnabled(false);
        ui->left->setEnabled(false);
        ui->up->setEnabled(false);
        ui->down->setEnabled(false);

        ui->right->setStyleSheet("QPushButton { background-color: transparent }");
        ui->left->setStyleSheet("QPushButton { background-color: transparent }");
        ui->up->setStyleSheet("QPushButton { background-color: transparent }");
        ui->down->setStyleSheet("QPushButton { background-color: transparent }");
        ui->right->setText("");
        ui->left->setText("");
        ui->up->setText("");
        ui->down->setText("");
        ui->end->setText("End Game");
        ui->end->setEnabled(true);
        ui->end->setStyleSheet("QPushButton { font: 15pt ; background-color: rgb(0, 0, 0); color: rgb(156, 0, 0); }");
        ui->textOut->append(QString::fromStdString(Dialog->end()));
    }
    for(QRadioButton *x: buttons ){

     if(tory.size() > 0){

     QPixmap pic(QString::fromStdString(":/img/" + tory.front().getShortDescription() + ".png"));
     x->setIcon(pic);
     x->setIconSize(QSize(65, 65));
    tory.erase(tory.begin());
    }
    else{
          QPixmap pic("");
          x->setIcon(pic);
        }

    }
}

void MainWindow::on_item1_clicked()
{
  Me->addItem(bag[0]);
  Game->getRoom()->removeItemFromRoom(0);
  inv();
  Displayinv();

}

void MainWindow::on_item2_clicked()
{
 Me->addItem(bag[1]);
 Game->getRoom()->removeItemFromRoom(1);
 inv();
 Displayinv();
}









void MainWindow::on_end_clicked()
{
 MainWindow::close();
}
