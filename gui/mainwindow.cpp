#include "mainwindow.h"
// #include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent, Game *game)
    : QMainWindow(parent), game(game)
    // , ui(new Ui::MainWindow)
{
    // ui->setupUi(this);
    setWindowTitle("Wordle");
    setStyleSheet("background-color: #ffffff");

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QHBoxLayout* outerLayout =  new QHBoxLayout(centralWidget);
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QVBoxLayout* optionLayout = new QVBoxLayout();

    // main window components ----------------------------------------------
    inputWindow = new InputWindow(centralWidget, game, nullptr, nullptr);
    messageWindow = new MessageWindow(centralWidget, game);
    keyboardWindow = new KeyboardWindow(centralWidget, game, nullptr);

    restartOption = new RestartOption(centralWidget, game, nullptr, nullptr, nullptr);
    diffOption = new DiffOption(centralWidget, game);
    hintOption = new HintOption(centralWidget, game);
    saveOption = new SaveOption(centralWidget, game, nullptr);
    loadOption = new LoadOption(centralWidget, game, nullptr, nullptr, nullptr);

    inputWindow->setKeyboardWindow(keyboardWindow);
    inputWindow->setMessageWindow(messageWindow);
    keyboardWindow->setInputWindow(inputWindow);
    
    restartOption->setInputWindow(inputWindow);
    restartOption->setKeyboardWindow(keyboardWindow);
    restartOption->setMessageWindow(messageWindow);
    diffOption->setMessageWindow(messageWindow);
    saveOption->setMessageWindow(messageWindow);
    loadOption->setInputWindow(inputWindow);
    loadOption->setMessageWindow(messageWindow);
    loadOption->setDiffOption(diffOption);

    // main layout --------------------------------------------------------
    QSpacerItem* spacer1 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QSpacerItem* spacer2 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    
    title = new QLabel("Wordle"); // title bar
    QFont font = title->font();
    font.setFamily("Consolas");
    font.setPointSize(50);
    font.setBold(true);
    title->setFont(font);
    
    mainLayout->addItem(spacer1);
    mainLayout->addWidget(title, 0, Qt::AlignCenter);
    mainLayout->addWidget(inputWindow, 0, Qt::AlignCenter);
    mainLayout->addWidget(messageWindow, 0, Qt::AlignCenter);
    mainLayout->addWidget(keyboardWindow, 0, Qt::AlignCenter);
    mainLayout->addItem(spacer2);

    // option layout --------------------------------------------------------
    QSpacerItem* spacer3 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QSpacerItem* spacer34 = new QSpacerItem(0, 500, QSizePolicy::Minimum, QSizePolicy::Minimum);
    QSpacerItem* spacer4 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    optionLayout->addSpacing(3);
    optionLayout->addItem(spacer3);
    optionLayout->addWidget(restartOption, 0, Qt::AlignCenter);
    optionLayout->addWidget(diffOption, 0, Qt::AlignCenter);
    optionLayout->addWidget(hintOption, 0, Qt::AlignCenter);
    optionLayout->addWidget(saveOption, 0, Qt::AlignCenter);
    optionLayout->addWidget(loadOption, 0, Qt::AlignCenter);
    optionLayout->addItem(spacer34);
    optionLayout->addItem(spacer4);

    // outer layout ---------------------------------------------------------
    QSpacerItem* leftSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);    
    QSpacerItem* rightSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    outerLayout->addItem(leftSpacer);
    outerLayout->addLayout(mainLayout);
    outerLayout->addLayout(optionLayout);
    outerLayout->addItem(rightSpacer);

    centralWidget->setLayout(outerLayout);
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
void MainWindow::closeEvent(QCloseEvent *event)
{
    if (hintOption != nullptr)
        hintOption->close();
    event->accept();
}
