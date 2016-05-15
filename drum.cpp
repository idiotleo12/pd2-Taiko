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
        if(counter<9)
            counter++;
        //setPos(x(),y()-10);
        //qDebug()<<this->pos();
        //scene()->removeItem(this);
        if(this->x()<=40&&this->x()>=20)
        {
            score=score+10;
        }
        this->scene()->clearFocus();
        this->hide();
        qDebug()<<"score:"<<drum::score;

      }
    else if(event->key() == Qt::Key_Right)
        {
            //setPos(x(),y()-10);
            //qDebug()<<"key right get";

        }
}
drum::drum()
{
    //MainWindow::ui->label_score_num->setText(QString::number(0));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void drum::move()
{
    if(this->x() <0)
        this->hide();
    setPos(x()-5,y());
}
