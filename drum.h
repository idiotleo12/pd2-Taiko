#ifndef DRUM_H
#define DRUM_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QLabel>
//#include <QKeyEvent>

class drum : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    static int score;
    static int counter;
    //void clone(drum *d);
    int color;//1=blue 2=red
    void keyPressEvent(QKeyEvent * event);
    drum();
    ~drum();
public slots:
    void move();
private:


};

#endif // DRUM_H
