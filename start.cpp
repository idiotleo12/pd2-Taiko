#include "start.h"
#include "ui_start.h"
#include <QObject>
#include "mainwindow.h"
start::start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);

    QImage bg_gogo(":/bglayer_gogo.png");
    QPixmap gogo_pixmap = QPixmap::fromImage(bg_gogo);
    ui->label->setPixmap(gogo_pixmap);
    QObject::connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(hide()));
}

start::~start()
{
    delete ui;
}


void start::on_pushButton_clicked()
{
    //w=new MainWindow(this);
    w.show();
}
