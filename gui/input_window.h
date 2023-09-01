#ifndef INPUT_WINDOW_H
#define INPUT_WINDOW_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include "cell.h"

class InputWindow : public QWidget
{
    Q_OBJECT

public:
    InputWindow(QWidget *parent = nullptr);
    ~InputWindow(); 

    void keyPressEvent(QKeyEvent *event);

private:
    Cell *Cells[6][5];
};

#endif // INPUT_WINDOW_H
