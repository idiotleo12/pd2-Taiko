#include "mainwindow.h"
#include <QApplication>
#include "drum.h"
#include <QTimer>
#include "start.h"
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    start st;
    st.show();
    //w.show();

    return a.exec();
}
