#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QListWidgetItem *tableIMG = new QListWidgetItem(QIcon("../Proj/imgs/table.png"), "Стол");
    ui->listWidget->addItem(tableIMG);

    QListWidgetItem *barTableIMG = new QListWidgetItem(QIcon("../Proj/imgs/barTable.png"), "Высокий стол");
    ui->listWidget->addItem(barTableIMG);

    QListWidgetItem *chairIMG = new QListWidgetItem(QIcon("../Proj/imgs/chair.png"), "Стул");
    ui->listWidget->addItem(chairIMG);

    QListWidgetItem *barChairIMG = new QListWidgetItem(QIcon("../Proj/imgs/barChair.png"), "Высокий стул");
    ui->listWidget->addItem(barChairIMG);
    ui->listWidget->addItem("Диван");
    ui->listWidget->addItem("Растение в горшке");
    ui->listWidget->addItem("Подиум");
    ui->listWidget->addItem("Экран для проектора");
    ui->listWidget->addItem("Плазменный телевизор");
    ui->listWidget->addItem("Шкаф");
    ui->listWidget->addItem("Стеллаж");
    ui->listWidget->addItem("Источник света");
}

MainWindow::~MainWindow()
{
    delete ui;
}
