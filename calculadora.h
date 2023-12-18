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
    QPushButton *botonPunto, *botonBorrar, *botonResultado, *botonSalir, *botonAns;
    QLabel *operador;
    QLabel *num1, *num2, *numRes;
    QFont fuente;
    QPushButton *boton;
    QString textoBoton;
    QString textoActual;

public:
    Calculadora(QWidget *parent = nullptr);
    ~Calculadora();

private slots:
    void botonPresionado();
    void resultadoPresionado();
    void borrarPresionado();
    void setNum1();
    void setOperador();
    void setNum2();
    void setText();
    void setAns();

};
#endif // CALCULADORA_H
