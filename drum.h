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
    void keyPressEvent(QKeyEvent * event);
    drum();

    //void start();
public slots:
    //void update_score(QLabel * label);
    void move();
private:


};

#endif // DRUM_H
