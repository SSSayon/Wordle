#ifndef HINT_OPTION_H
#define HINT_OPTION_H

#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QStringList>
#include <QString>

class Game;

class HintOption : public QLabel
{
    Q_OBJECT

private:
    Game *game;
    QWidget *hintWindow;
    QVBoxLayout *hintWindowLayout;
    QLabel *hintLabel;
    void _onHintWindowClosed();
    void _setHintWindowCentered();
    QString _getHint();
    
    

public:
    HintOption(QWidget *parent = nullptr, Game *game = nullptr);
    ~HintOption();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
};

#endif // HINT_OPTION_H
