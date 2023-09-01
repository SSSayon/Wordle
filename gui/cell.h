#ifndef CELL_H
#define CELL_H

#include <QFrame>
#include <QLabel>
#include <QString>

class Cell : public QFrame
{
    Q_OBJECT

public:
    struct Style
    {
        int width, height;
        QString color;
        int border_radius;
        QString border_color;
    } style;
    QString getGridColor() const;
    QString getBorderColor() const;

    struct LetterStyle
    {
        int pos_x, pos_y;
        int width, height;
        QString color;
        int font_size;
    } letterStyle;
    QString getLetterColor() const;

    QLabel *letterLabel;
    
public:
    Cell(QWidget *parent = nullptr);
    ~Cell();

    int type = 1; // 1: input, 2: keyboard
    enum class Color {gray, black, green, yellow, darkGray};
    Color color = Color::gray;

    void setLetter(const QString &);
    QString getLetter() const;
    void setPos(int x, int y);
    void setStyle(int width, int height, int border_radius);
    void setLetterStyle(int pos_x, int pos_y, int width, int height, int font_size);
    void changeColor();

signals:
    void cellClicked(Cell *cell);

protected:
    void mousePressEvent(QMouseEvent *event) override;    
};

#endif // CELL_H
