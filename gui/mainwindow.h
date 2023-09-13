#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "input_window.h"
#include "keyboard_window.h"
#include "message_window.h"
#include "../core/game.h"
#include "options/restart_option.h"
#include "options/hint_option.h"
#include "options/difficulty_option.h"
#include "options/save_option.h"
#include "options/load_option.h"

// QT_BEGIN_NAMESPACE
// namespace Ui { class MainWindow; }
// QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, Game *game = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent* event);
    void closeEvent(QCloseEvent *event) override;

private:
    // Ui::MainWindow *ui;
    // QVBoxLayout *mainLayout;
    QLabel *title;
    MessageWindow *messageWindow;
    InputWindow *inputWindow;
    KeyboardWindow *keyboardWindow;
            
    Game *game;

    RestartOption *restartOption;
    HintOption *hintOption;
    DiffOption *diffOption;
    SaveOption *saveOption;
    LoadOption *loadOption;
};

#endif // MAINWINDOW_H
