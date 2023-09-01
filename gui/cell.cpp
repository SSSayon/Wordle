#include "cell.h"
#include <QMouseEvent>
#include <QDebug>

Cell::Cell(QWidget *parent)
    : QFrame(parent)
{
    setStyle(90, 90, 0);

    letterLabel = new QLabel("", this);
    QFont font = letterLabel->font();
    font.setFamily("Monospace");
    font.setBold(true);
    letterLabel->setFont(font);
    setLetterStyle(32, 22, 30, 45, 45);
    letterLabel->show();
    
    color = Color::gray;
}

Cell::~Cell()
{
    delete letterLabel;
}

void Cell::setLetter(const QString &letter)
{
    letterLabel->setText(letter);
}

QString Cell::getLetter() const
{
    return letterLabel->text();
}

void Cell::setPos(int x, int y)
{
    move(x, y);
}

QString Cell::getGridColor() const
{
    switch (color)
    {
    case Color::gray:
        {
            if (type == 1) return "#ffffff";
            else return "#d3d6da";
        }
    case Color::black: // only when type == 1
        return "#ffffff";
    case Color::green:
        return "#6aaa64";
    case Color::yellow:
        return "#c9b458";
    case Color::darkGray:
        return "#787c7e";
    default:
        return "#ffffff";
    }
}

QString Cell::getBorderColor() const
{
    if (type == 2) return "#ffffff";
    switch (color)
    {
    case Color::gray:
        return "#d3d6da";
    case Color::black: // only when type == 1
        return "#878a8c";
    case Color::green:
        return "#6aaa64";
    case Color::yellow:
        return "#c9b458";
    case Color::darkGray:
        return "#787c7e";
    default:
        return "#ffffff";
    }
}

QString Cell::getLetterColor() const
{
    switch (color)
    {
    case Color::gray: 
        {
            if (type == 1) return "#ffffff"; // input is empty, set to invisible
            else return "#000000";
        }
    case Color::black: // only when type == 1
        return "#000000";
    case Color::green:
        return "#ffffff";
    case Color::yellow:
        return "#ffffff";
    case Color::darkGray:
        return "#ffffff";
    default:
        return "#ffffff";
    }
}

void Cell::setStyle(int width, int height, int border_radius)
{
    style.width = width;
    style.height = height;
    style.border_radius = border_radius;
    style.color = getGridColor();
    style.border_color = getBorderColor();

    setFixedSize(style.width, style.height);
    setStyleSheet(QString("background-color: %1; border-radius: %2px; border: 3px solid %3")
                  .arg(style.color).arg(style.border_radius).arg(style.border_color));
}

void Cell::setLetterStyle(int pos_x, int pos_y, int width, int height, int font_size)
{
    letterStyle.pos_x = pos_x;
    letterStyle.pos_y = pos_y;
    letterStyle.width = width;
    letterStyle.height = height;
    letterStyle.color = getLetterColor();
    letterStyle.font_size = font_size;
    letterLabel->setGeometry(letterStyle.pos_x, letterStyle.pos_y, width, height);
    letterLabel->setStyleSheet(QString("background-color: %1; border: 0px; color: %2; font-size: %3px")
                               .arg(style.color).arg(letterStyle.color).arg(letterStyle.font_size));
}

void Cell::changeColor()
{
    setStyle(style.width, style.height, style.border_radius);
    setLetterStyle(letterStyle.pos_x, letterStyle.pos_y, letterStyle.width, letterStyle.height, letterStyle.font_size);
}

void Cell::mousePressEvent(QMouseEvent *event)
{
    QFrame::mousePressEvent(event);
    if (event->button() == Qt::LeftButton)
    {
        emit cellClicked(this);
    }
}
