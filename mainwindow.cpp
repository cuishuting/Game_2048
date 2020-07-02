#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>
#include <QImage>
#include <QLabel>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette PAllbackground = this->palette();
    QImage ImgAllbackground(":/image_2048/background2.jpg");
    QImage fitimgpic=ImgAllbackground.scaled(this->width(),this->height(), Qt::IgnoreAspectRatio);
    PAllbackground.setBrush(QPalette::Window, QBrush(fitimgpic));
    this->setPalette(PAllbackground);
    ui->label->setWordWrap(true);
    ui->label_2->setWordWrap(true);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            QLabel* label = new QLabel;
            label->setGeometry(0,0,125,125);
            label->setPixmap(QPixmap(":/image_2048/BoardNode(1).png"));
            label->setScaledContents(true);
            label->setParent(this);
            label->move(i*125, 200+j*125);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
