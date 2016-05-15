#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "drum.h"
#include <QMainWindow>
#include <QList>
#include <QGraphicsScene>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow//,public QObject
//class MainWindow : public QObject
{
    Q_OBJECT

public:
    drum *drum_arr[10];
    QGraphicsScene * scene;
    QList<drum*> list;
    explicit MainWindow(QWidget *parent = 0);
    Ui::MainWindow *ui;

    ~MainWindow();
public slots:
    void update_time();
    void update_window();
    void update_focus();
private:
    //Ui::MainWindow *ui;
    void set_drum_arr();
    void set_drum_list();
    int seconds;
};

#endif // MAINWINDOW_H
