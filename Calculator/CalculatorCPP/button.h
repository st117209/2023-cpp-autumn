#ifndef BUTTON_H
#define BUTTON_H

#include<QToolButton>
//#include<QWidget>
//#include<QAbstractButton>

class Button : public QToolButton
{
    Q_OBJECT

public:
    explicit Button(const QString& text, QWidget* parent = nullptr);
    QSize sizeHint() const override;
};


#endif // BUTTON_H

