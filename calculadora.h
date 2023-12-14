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
    QPushButton *botnPunto, *botonBorrar, *botonResultado, *botonSalir;
    QLabel *operacion;



public:
    Calculadora(QWidget *parent = nullptr);
    ~Calculadora();

private slots:
    void digitoPresionado();
    void operadorPresionado();
    void resultadoPresionado();
    void borrarPresionado();

};
#endif // CALCULADORA_H
