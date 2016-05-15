#include "drum.h"
#include "mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>
//#include <unistd.h>

#include <QDebug>
int drum::score=0;
int drum::counter=0;
void drum::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        if(counter<19)
            counter++;

        if(this->x()<=40&&this->x()>=20&&this->color==1)
        {
            score=score+10;
        }
        this->scene()->clearFocus();
        this->hide();
        qDebug()<<"score:"<<drum::score;

      }
    else if(event->key() == Qt::Key_Right)
        {
        if(counter<19)
            counter++;

        if(this->x()<=40&&this->x()>=20&&this->color==2)
        {
            score=score+10;
        }
        this->scene()->clearFocus();
        this->hide();
        qDebug()<<"score:"<<drum::score;

        }
}
drum::drum()
{
    //MainWindow::ui->label_score_num->setText(QString::number(0));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
    color=0;
}

void drum::move()
{
    if(this->x() <0)
    {
        this->scene()->clearFocus();
        this->removeFromIndex();
        //counter++;
    }
    setPos(x()-5,y());
}

drum::~drum()
{
    delete this;
}
