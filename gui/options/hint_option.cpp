#include "hint_option.h"
#include "../../core/game.h"
#include <QSvgRenderer>
#include <QPixmap>
#include <QPainter>
#include <QDebug>

HintOption::HintOption(QWidget *parent, Game *game)
    : QLabel(parent), game(game)
{
    QSvgRenderer *renderer = new QSvgRenderer(QString(":/icons/lightbulb-regular.svg"));
    QPixmap *pixmap = new QPixmap(28, 36);
    pixmap->fill(Qt::transparent);
    QPainter *painter = new QPainter(pixmap);
    renderer->render(painter);
    painter->end();
    setPixmap(*pixmap);
    setScaledContents(true);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    setToolTip("Hint");
    hintWindow = nullptr;
    hintWindowLayout = nullptr;
    hintLabel = new QLabel("", nullptr);
}

HintOption::~HintOption() 
{
    delete hintWindow;
    delete hintWindowLayout;
    delete hintLabel;
}

void HintOption::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // qDebug() << "Hint clicked";
        if (hintWindow == nullptr)
        {
            hintWindow = new QWidget();
            hintWindow->setAttribute(Qt::WA_DeleteOnClose);
            hintWindow->setWindowTitle("Hint");
            hintWindow->resize(200, 200);
            hintWindowLayout = new QVBoxLayout(hintWindow);

            hintLabel->setText(_getHint());
            hintLabel->setParent(hintWindow);
            QFont font = hintLabel->font();
            font.setFamily("Consolas");
            font.setPointSize(20);
            hintLabel->setFont(font);

            hintWindowLayout->addWidget(hintLabel);
            hintWindow->setLayout(hintWindowLayout);
            connect(hintWindow, &QWidget::destroyed, this, &HintOption::_onHintWindowClosed);
            _setHintWindowCentered();
            hintWindow->show();
        }
        else
        {
            hintWindow->close();
            _onHintWindowClosed();
        }
    }
}
void HintOption::_onHintWindowClosed()
{
    hintWindow = nullptr;
    hintWindowLayout = nullptr;
    hintLabel->setParent(nullptr);
}
void HintOption::_setHintWindowCentered()
{
    if (hintWindow != nullptr)
    {
        hintWindow->move(this->parentWidget()->parentWidget()->x() + this->parentWidget()->width() / 2 - hintWindow->width() / 2,
                         this->parentWidget()->parentWidget()->y() + this->parentWidget()->height() / 2 - hintWindow->height() / 2);
    }
}
QString HintOption::_getHint()
{
    QString hint = "\n";
    QStringList words = game->getValidWords();
    for (QString word : words) hint += "  " + word + "\n";
    return hint;
}
void HintOption::closeEvent(QCloseEvent *event)
{
    if (hintWindow != nullptr)
        hintWindow->close();
    event->accept();
}
