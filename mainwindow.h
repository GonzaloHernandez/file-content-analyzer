#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <field.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QList<Field*>   info;
    FILE*           file;
    uint32_t        viewstart;
    uint16_t        viewlenght;
    //----- temporal variables -------------
    uint            lowerbound,upperbound;
    //----- methods ------------------------
    void reloadView();
public:
    explicit MainWindow(QWidget *parent = 0);

signals:

public slots:

    void paintEvent(QPaintEvent*);
    void mouseMoveEvent(QMouseEvent* e);
    void mousePressEvent(QMouseEvent* e);
    void wheelEvent(QWheelEvent* e);
    void resizeEvent(QResizeEvent* e);
};

#endif // MAINWINDOW_H
