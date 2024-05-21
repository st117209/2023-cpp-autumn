#include "calculator.h"

#include <QGridLayout>

#include <QtMath>

#include <QDebug>

#include "button.h"

#include <QWidget>


Calculator::Calculator()
{
    m_display_up = new QLineEdit();
    m_display_down = new QLineEdit();
    m_sign = new QLabel();
    QGridLayout* mainLayout = new QGridLayout;    // создаём слой

    setLayout(mainLayout); // добавляем в слой

    mainLayout->setSizeConstraint(QLayout::SetFixedSize); // устанавливаем фиксированный размер столбцов и строк

    // невозможность ввода с клавиатуры
    m_display_up->setReadOnly(true);
    m_display_down->setReadOnly(true);

    // выравнивание текста справа
    m_display_up->setAlignment(Qt::AlignRight);
    m_display_down->setAlignment(Qt::AlignRight);
    m_sign->setAlignment(Qt::AlignRight);

    // ограничение длинны ввода текста
    m_display_up->setMaxLength(20);
    m_display_down->setMaxLength(20);


    // увеличиваем шрифт
    QFont font = m_display_up->font();  //запрашиваем настройки шрифта
    font.setPointSize(font.pointSize() + 10); //меняем шрифт
    m_display_up->setFont(font);
    m_display_down->setFont(font);
    m_sign->setFont(font);


    // создаём кнопки
    for (int i = 0; i < 10; i++)
    {
        m_digitButtons[i] = createButton (QString::number(i), SLOT(digitClicked()));
    }

    Button* pointButton         = createButton(".", SLOT(pointClicked()));
    Button* changeSignButton    = createButton(m_change_sign, SLOT(signChangeClicked()));
    Button* backButton          = createButton("<-", SLOT(backClicked()));
    Button* clearButton         = createButton("C", SLOT(clearClicked()));
    Button* clearAllButton      = createButton("AC", SLOT(allClearClicked()));
    Button* plusButton          = createButton(m_plus_sign, SLOT(binary_operation_Clicked()));
    Button* minusButton         = createButton(m_minus_sign, SLOT(binary_operation_Clicked()));
    Button* multiplyButton      = createButton(m_multiply_sign, SLOT(binary_operation_Clicked()));
    Button* divisionButton      = createButton(m_division_sign, SLOT(binary_operation_Clicked()));
    Button* squareRootButton    = createButton(m_squareRoot_sign, SLOT(unary_operation_Clicked()));
    Button* powerButton         = createButton(m_power_sign, SLOT(unary_operation_Clicked()));
    Button* reciprocalButton    = createButton(m_reciprocal_sign, SLOT(unary_operation_Clicked()));
    Button* equalButton         = createButton("=", SLOT(equalCliked()));
    /*
    Button* clearMemoryButton   = createButton("MC", SLOT(clearMemoryClicked()));
    Button* readMemoryButton    = createButton("MR", SLOT(readMemoryClicked()));
    Button* setMemoryButton     = createButton("M+", SLOT(setMemoryClicked()));
    Button* addToMemoryButton   = createButton("M-", SLOT(addToMemoryClicked()));
    */

    // добавляем виджеты
    mainLayout->addWidget(m_display_up,     0, 0, 1, 6);
    mainLayout->addWidget(m_sign,           1, 5, 1, 1);
    mainLayout->addWidget(m_display_down,   2, 0, 1, 6);

    mainLayout->addWidget(backButton,       3, 0, 1, 2);
    mainLayout->addWidget(clearButton,      3, 2, 1, 2);
    mainLayout->addWidget(clearAllButton,   3, 4, 1, 2);

    // быстрое создание цифр 1 - 9
    for(int i = 0; i < 10; i++)
    {
        int row = ((9 - i) / 3) + 4;
        int column = ((i - 1) % 3) + 1;
        mainLayout->addWidget(m_digitButtons[i], row, column);
    }

    mainLayout->addWidget(m_digitButtons[0],    7, 1);
    mainLayout->addWidget(pointButton,          7, 2);
    mainLayout->addWidget(changeSignButton,     7, 3);

    mainLayout->addWidget(plusButton,           4, 4);
    mainLayout->addWidget(minusButton,          5, 4);
    mainLayout->addWidget(multiplyButton,       6, 4);
    mainLayout->addWidget(divisionButton,       7, 4);

    mainLayout->addWidget(squareRootButton,     4, 5);
    mainLayout->addWidget(powerButton,          5, 5);
    mainLayout->addWidget(reciprocalButton,     6, 5);
    mainLayout->addWidget(equalButton,          7, 5);


    setWindowTitle("Calculator"); // добавляем заголовок окна программы
}

// для упрощенного создания кнопок
Button* Calculator::createButton(const QString& text, const char* member)
{
    Button* btn = new Button(text);
    connect(btn, SIGNAL(clicked()), this, member); // подключение кнопки btn
    return btn;
}

void Calculator::digitClicked()
{
    Button* btn = (Button* )sender();  // возвращает указатель на объект, который вызвал данный слот
    int digit = btn->text().toUInt();
    // qDebug() << "digit" << digit;

    if(m_display_down->text() == "0")
    {
        m_display_down->clear();
        m_display_up->clear();
    }

    m_display_down->setText(m_display_down->text() + QString::number(digit));
}


void Calculator::unary_operation_Clicked()
{
    Button* btn = (Button*)sender();
    QString operation = btn->text();

    double operand = m_display_down->text().toDouble();
    double res = 0.0;

    if (operation == m_squareRoot_sign) {
        if (operand < 0.0)
        {
            abortOperation();
            return;
        }
        res = std::sqrt(operand);
    }
    else if (operation == m_power_sign)
    {
        res = std::pow(operand, 2.0);
    }
    else if (operation == m_reciprocal_sign)
    {
        if (operand == 0.0)
        {
            abortOperation();
            return;
        }

        res = 1.0 / operand;
    }

    m_display_down->setText(QString::number(res));
}
void Calculator::binary_operation_Clicked()
{
    Button* btn = (Button*)sender();
    QString operation = btn->text();

    double operand = m_display_down->text().toDouble();

    if (m_display_down->text() == "0")
    {
        return;
    }

    m_sign->setText(operation);

    if (m_display_down->text() == "")
    {
        return;
    }

    m_display_down->clear();

    if (!m_pending_operation.isEmpty())
    {
        if (!calculate(operand, m_pending_operation))
        {
            abortOperation();
            return;
        }
        m_pending_operation.clear();
    }
    else
    {
        m_display_up->setText(QString::number(operand));
    }

    m_pending_operation = operation;
}
void Calculator::equalCliked()
{
    double operand = m_display_down->text().toDouble();

    if (!m_pending_operation.isEmpty())
    {
        if (!calculate(operand, m_pending_operation))
        {
            abortOperation();
            return;
        }
        m_pending_operation.clear();
    }

    m_display_down->setText(m_display_up->text());
    m_display_up->clear();
    m_sign->clear();
}
void Calculator::pointClicked()
{

    if (!m_display_down->text().contains(".")) // узнаём есть ли уже точка
    {
        m_display_down->setText(m_display_down->text() + ".");
    }

}
void Calculator::signChangeClicked()
{
    QString text = m_display_down->text();
    double val = m_display_down->text().toDouble();

    if (val > 0.0)
    {
        text.prepend("-"); //добавить в начало
    }
    else if (val < 0.0)
    {
        text.remove(0, 1);  // удалить 1 символ в начале
    }
    m_display_down->setText(text);
}
void Calculator::backClicked()
{
    QString text = m_display_down->text();
    text.chop(1); // удаляет с конца один элемент

    if (text.isEmpty())
    {
        text = '0';
    }
    m_display_down->setText(text);
}
void Calculator::clearClicked()
{
    m_display_down->setText("0");
}
void Calculator::allClearClicked()
{
    m_display_down->setText("0");
    m_display_up->clear();
    m_sign->clear();
}

void Calculator::abortOperation()
{
    m_display_up->setText("EROR");
    m_display_down->setText("EROR");
}

bool Calculator::calculate(double operand, const QString& operation) //получилось посчитать или нет
{
    double temp_total   = m_display_up->text().toDouble();

    if (operation == m_plus_sign)
    {
        temp_total += operand;
    }
    else if (operation == m_minus_sign)
    {
        temp_total -= operand;
    }
    else if (operation == m_multiply_sign)
    {
        temp_total *= operand;
    }
    else if (operation == m_division_sign)
    {
        if (operand == 0)
        {
            return false;
        }
        temp_total /= operand;
    }

    m_display_up->setText(QString::number(temp_total));

    return true;

}
