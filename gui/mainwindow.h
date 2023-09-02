#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include "input_window.h"
#include "keyboard_window.h"

// QT_BEGIN_NAMESPACE
// namespace Ui { class MainWindow; }
// QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent* event);

private:
    // Ui::MainWindow *ui;
    // QVBoxLayout *mainLayout;
    // Game game;
    QLabel *title;
    InputWindow *inputWindow;
    KeyboardWindow *keyboardWindow;
};

#endif // MAINWINDOW_H
