#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <QMainWindow>
#include <QtWidgets>

class Calculadora : public QMainWindow
{
    Q_OBJECT
private:
    QPushButton *boton0, *boton1, *boton2, *boton3, *boton4;
    QPushButton *boton5, *boton6, *boton7, *boton8, *boton9;
    QPushButton *botonSuma, *botonResta, *botonMulti, *botonDivision;
    QPushButton *botonPunto, *botonBorrar, *botonResultado, *botonSalir, *ans;
    QLabel *operacion;
    QLabel *num1, *num2, *numRes;

public:
    Calculadora(QWidget *parent = nullptr);
    ~Calculadora();

private slots:
    void digitoPresionado();
    void setAns();
    void resultadoPresionado();
    void borrarPresionado();

    void setText();
    void setText1();
    void setText2();
    void setTextO();

};
#endif // CALCULADORA_H
