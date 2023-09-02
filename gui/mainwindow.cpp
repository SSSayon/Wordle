#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    // , ui(new Ui::MainWindow)
{
    // ui->setupUi(this);
    setWindowTitle("Wordle");
    setStyleSheet("background-color: #ffffff");

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);

    QSpacerItem* spacer1 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    mainLayout->addItem(spacer1);

    title = new QLabel("Wordle", centralWidget);
    QFont font = title->font();
    font.setFamily("Consolas");
    font.setPointSize(50);
    font.setBold(true);
    title->setFont(font);
    mainLayout->addWidget(title, 0, Qt::AlignCenter);

    inputWindow = new InputWindow(centralWidget);
    mainLayout->addWidget(inputWindow, 0, Qt::AlignCenter);

    keyboardWindow = new KeyboardWindow(centralWidget);
    mainLayout->addWidget(keyboardWindow, 0, Qt::AlignCenter);

    QSpacerItem* spacer2 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    mainLayout->addItem(spacer2);
    centralWidget->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    // delete ui;
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);

    int minWidth = 1200;
    int minHeight = 1000;
    QSize currentSize = size();
    if (currentSize.width() < minWidth || currentSize.height() < minHeight)
    {
        resize(qMax(currentSize.width(), minWidth), qMax(currentSize.height(), minHeight));
    }
}