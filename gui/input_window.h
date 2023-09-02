#ifndef INPUT_WINDOW_H
#define INPUT_WINDOW_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QGridLayout>
#include "cell.h"

class InputWindow : public QWidget
{
    Q_OBJECT

public:
    InputWindow(QWidget *parent = nullptr);
    ~InputWindow(); 

    void keyPressEvent(QKeyEvent *event);

private:
    QGridLayout *gridLayout;
    Cell *Cells[6][5];
};

#endif // INPUT_WINDOW_H
