#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <QMainWindow>

class Calculadora : public QMainWindow
{
    Q_OBJECT

public:
    Calculadora(QWidget *parent = nullptr);
    ~Calculadora();
};
#endif // CALCULADORA_H
