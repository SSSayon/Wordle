#ifndef CELL_H
#define CELL_H

#include <QFrame>
#include <QLabel>
#include <QString>
#include <QMouseEvent>

class Cell : public QFrame
{
    Q_OBJECT

private:
    struct Style
    {
        int width, height;
        QString color;
        int border_radius;
        QString border_color;
    } style;
    QString getGridColor() const;
    QString getBorderColor() const;
    void setStyle(int width, int height, int border_radius);
    struct LetterStyle
    {
        int pos_x, pos_y;
        int width, height;
        QString color;
        int font_size;
    } letterStyle;
    QString getLetterColor() const;
    void setLetterStyle(int pos_x, int pos_y, int width, int height, int font_size);

    QLabel *letterLabel;
    int type; // 1: input, 2: keyboard, 3: enter, 4: backspace

public:
    Cell(QWidget *parent = nullptr);
    ~Cell();

    enum class Color {gray, black, green, yellow, darkGray};
    Color color;

    void setLetter(const QString &);
    QString getLetter() const;
    void changeColor();
    void setType(int type);

signals:
    void cellClicked(Cell *cell);

protected:
    void mousePressEvent(QMouseEvent *event) override;    
};

#endif // CELL_H
