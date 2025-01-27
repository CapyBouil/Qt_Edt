#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSplitter>
#include <QVBoxLayout>
#include <QTabWidget>

class MainWindow
{
    Q_OBJECT

    private:
        QBoxLayout main_layout;

    public:
        MainWindow(QWidget parent);


    private:
        void init_composants(void);
        void init_layout(void);
        void init_slots(void);

};

#endif // MAINWINDOW_H
