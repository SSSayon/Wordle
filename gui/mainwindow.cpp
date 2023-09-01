#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Wordle");
    setFixedSize(1200, 1000);
    setStyleSheet("background-color: #ffffff");

    title = new QLabel("Wordle", this);
    title->setGeometry(480, 10, 800, 80);
    QFont font = title->font();
    font.setFamily("Consolas");
    font.setPointSize(50);
    font.setBold(true);
    title->setFont(font);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete title;
}

