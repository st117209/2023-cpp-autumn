#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include "button.h"

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator();

private slots:
    void digitClicked();				// ввод цифры
    void unary_operation_Clicked();		// унарные операции
    void binary_operation_Clicked();	// бинарные операции
    void equalCliked();					// вывод значения
    void pointClicked();				// добавление точки
    void signChangeClicked();			// смена знака
    void backClicked();					// удаление элемента
    void clearClicked();				// очистка нижней строчки
    void allClearClicked();				// очистка всего

private:
    double m_sum_memory;

    Button* createButton(const QString& text, const char* member); // функция для создания кнопок (чтоб быстрее было) member - куда нужно подключиться

    void abortOperation();  // выдать ошибку

    QLineEdit* m_display_up;    // врхний экран
    QLineEdit* m_display_down;  // нижний экран
    QLabel* m_sign;             // знак операции

    QString m_pending_operation; // запоминаем выбранную операцию (пока не выполняя её)

    Button* m_digitButtons[10];


    QString m_squareRoot_sign   = QChar(0x0000221A) ;
    QString m_power_sign        = 'x' + QChar(0x000000b2) ;
    QString m_reciprocal_sign   = "1/x" ;
    QString m_division_sign     = "/" ;
    QString m_multiply_sign     = "*" ;
    QString m_plus_sign         = "+" ;
    QString m_minus_sign        = "-" ;
    QString m_change_sign       = QChar(0x000000b1) ;


    bool calculate(double operand, const QString& operation);  // функция для подсчета

};



#endif // CALCULATOR_H
