#include "button.h"


Button::Button(const QString &text, QWidget *parent) : QToolButton(parent)           // делаем функцию для того чтобы сразу вводить текст в кнопку
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred); // Expanding - кнопка занимает по горизонтали всё отведенное место
                                                                   // Preferred - рекомендуемое
    setText(text);
}

QSize Button::sizeHint() const
{
    QSize size = QToolButton::sizeHint();
    size.rheight() += 30 ;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}
