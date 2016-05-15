#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "drum.h"
#include <time.h>
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //set background

    QImage bg_image(":/bg_p2.png");
    QPixmap bg_pixmap = QPixmap::fromImage(bg_image);
    QGraphicsPixmapItem *back= new QGraphicsPixmapItem();
    back->setPixmap(bg_pixmap);
    back->setZValue(-1);

    //set target
    QImage target_image(":/target.png");
    QPixmap target_pixmap = QPixmap::fromImage(target_image);
    QGraphicsPixmapItem *target= new QGraphicsPixmapItem();
    target->setPixmap(target_pixmap);
    target->setX(20);
    target->setY(170);
    target->setZValue(0);

    //drum arr
    //set_drum_arr();
    set_drum_list();
    //drum_arr[0]->setFocus();
    list.at(0)->setFocus();
    //list.at(1)->setFocus();

    //add scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,512,400);

    //add item to scene
    scene->addItem(back);
    scene->addItem(target);
    //scene->addItem(drum_blue_1);
    for(int i=0;i<10;i++)
    {
        //scene->addItem(drum_arr[i]);
        scene->addItem(list.at(i));
    }
    ui->label_score_num->setText(QString::number(drum::score));
    seconds=60;
    ui->label_time_num->setText(QString::number(seconds));
    ui->view->setScene(scene);
    ui->view->show();

    QTimer *time =new QTimer();
    //QObject::connect(time,SIGNAL(timeout()),this,SLOT(update_window(scene)));
    QObject::connect(time,SIGNAL(timeout()),this,SLOT(update_window()));
    time->start(30);

    //===
    QTimer *time_count= new QTimer();
    QObject::connect(time_count,SIGNAL(timeout()),this,SLOT(update_time()));
    time_count->start(1000);
    //
    QTimer *t= new QTimer();
    QObject::connect(t,SIGNAL(timeout()),this,SLOT(update_focus()));
    t->start(30);
}

void MainWindow::set_drum_arr()
{
    QImage drum_image_blue(":/drum_blue.png");
    QImage drum_image_red(":/drum_red.png");
    QPixmap bdrum_pixmap = QPixmap::fromImage(drum_image_blue);
    QPixmap rdrum_pixmap = QPixmap::fromImage(drum_image_red);

    srand(time(NULL));
    for(int i=0;i<10;i++)
    {
        int a=(rand()%3)+1;
        drum_arr[i] = new drum();
        if(a==1)
            drum_arr[i]->setPixmap(bdrum_pixmap);
        else
            drum_arr[i]->setPixmap(rdrum_pixmap);
        drum_arr[i]->setX(460+i*90);
        drum_arr[i]->setY(180);
        drum_arr[i]->setFlag(QGraphicsItem::ItemIsFocusable);

    }

}

void MainWindow::set_drum_list()
{
    QImage drum_image_blue(":/drum_blue.png");
    QImage drum_image_red(":/drum_red.png");
    QPixmap bdrum_pixmap = QPixmap::fromImage(drum_image_blue);
    QPixmap rdrum_pixmap = QPixmap::fromImage(drum_image_red);

    srand(time(NULL));
    for(int i=0;i<10;i++)
    {
        int a=(rand()%3)+1;
        drum *tmp = new drum();
        if(a==1)
            tmp->setPixmap(bdrum_pixmap);
        else
            tmp->setPixmap(rdrum_pixmap);
        tmp->setX(460+i*90);
        tmp->setY(180);
        tmp->setFlag(QGraphicsItem::ItemIsFocusable);
        list<<tmp;
    }

}

//void MainWindow::update_focus(QGraphicsScene * s)
void MainWindow::update_focus()
{
    //qDebug()<<"update";

    if(scene->hasFocus())
    {
        qDebug()<<"has";
    }
    else
    {
        qDebug()<<"no";
        list.at(drum::counter)->setFocus();
    }
}

void MainWindow::update_window()
{
    this->ui->label_score_num->setText(QString::number(drum::score));
    /*if(s->hasFocus())
    {

    }
    else
    {
        list.at(drum::counter)->setFocus();
    }*/
}

void MainWindow::update_time()
{
    if(seconds>0)
        seconds--;
    ui->label_time_num->setText(QString::number(seconds));
}

MainWindow::~MainWindow()
{
    delete ui;
}
