#include "mainwindow.h"
#include <QPainter>
#include <QDebug>
#include <QMenu>

void MainWindow::reloadView() {
    info.clear();
    viewlenght = (height()-50)/25;
    lowerbound = upperbound = -1;
    fseek(file,viewstart,SEEK_SET);
    for (int i=0; i<viewlenght; i++) {
        unsigned char buffer;
        fread(&buffer,1,1,file);
        info.append(new Field(200,20+i*25,QString("%1").arg(buffer),viewstart+i,1));
    }
    setStyleSheet("QMainWindow {background: 'white';}");
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    resize(500,400);
    file = fopen("/home/chalo/song.mp3","r");
    viewstart = 0;
    reloadView();
}

void MainWindow::paintEvent(QPaintEvent* ) {
    QPainter painter(this);
    QFont font = painter.font();
    font.setPixelSize(10);
    painter.setFont(font);
    foreach (Field* f, info) {
        f->draw(painter);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* e) {
    foreach (Field* f, info) {
        f->setFocused(false);
        if (f->isInArea(e->x(),e->y())) {
            upperbound = f->getPosition();
        }
    }
    foreach (Field* f, info) {
        if (f->getPosition() >= lowerbound && f->getPosition() <= upperbound) {
            f->setFocused(true);
        }
    }
    repaint();
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        foreach (Field* f, info) {
            if (f->isInArea(e->x(),e->y())) {
                f->setFocused(true);
                lowerbound = f->getPosition();
            } else {
                f->setFocused(false);
            }
        }
        repaint();
    } else if (e->button() == Qt::RightButton) {
        QMenu* join = new QMenu("Join");
        join->addAction("String");
        join->addAction("Integer 32");
        QMenu MyMenu(this);
        MyMenu.addMenu(join);
        MyMenu.exec(e->globalPos());
    }
}

void MainWindow::wheelEvent(QWheelEvent *e)
{
    if (e->delta() < 0) {
        viewstart++;
        reloadView();
        repaint();
    } else {
        if (viewstart>0) {
            viewstart--;
            reloadView();
            repaint();
        }
    }
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    reloadView();
}
