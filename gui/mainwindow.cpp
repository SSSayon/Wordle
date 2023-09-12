#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Game *game)
    : QMainWindow(parent), game(game)
    // , ui(new Ui::MainWindow)
{
    // ui->setupUi(this);
    setWindowTitle("Wordle");
    setStyleSheet("background-color: #ffffff");

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);

    QSpacerItem* spacer1 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QSpacerItem* spacer2 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    
    title = new QLabel("Wordle", centralWidget); // title bar
    QFont font = title->font();
    font.setFamily("Consolas");
    font.setPointSize(50);
    font.setBold(true);
    title->setFont(font);
    
    inputWindow = new InputWindow(centralWidget, game, nullptr, nullptr); // input window
    keyboardWindow = new KeyboardWindow(centralWidget, game, nullptr); // keyboard window
    messageWindow = new MessageWindow(centralWidget, game, nullptr); // message window
    inputWindow->setKeyboardWindow(keyboardWindow);
    inputWindow->setMessageWindow(messageWindow);
    keyboardWindow->setInputWindow(inputWindow);
    messageWindow->setInputWindow(inputWindow);

    mainLayout->addItem(spacer1);
    mainLayout->addWidget(title, 0, Qt::AlignCenter);
    mainLayout->addWidget(inputWindow, 0, Qt::AlignCenter);
    mainLayout->addWidget(messageWindow, 0, Qt::AlignCenter);
    mainLayout->addWidget(keyboardWindow, 0, Qt::AlignCenter);
    mainLayout->addItem(spacer2);

    centralWidget->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    // delete ui;
    delete title;
    delete inputWindow;
    delete keyboardWindow;
    delete messageWindow;
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);

    int minWidth = 1200;
    int minHeight = 1050;
    QSize currentSize = size();
    if (currentSize.width() < minWidth || currentSize.height() < minHeight)
    {
        resize(qMax(currentSize.width(), minWidth), qMax(currentSize.height(), minHeight));
    }
}