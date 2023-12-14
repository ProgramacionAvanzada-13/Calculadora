#include "calculadora.h"
#include <QtWidgets>

Calculadora::Calculadora(QWidget *parent)
    : QMainWindow(parent)
{
    // 100+100+20+100+20+100+20+100+20+100+100
    // 200+100+20+100+20+100+20+100+20+100+100

    setFixedSize(780,830);
    setWindowTitle("CALCULADORA");

    operacion = new QLabel{"Seleccione una opcion", this};
    operacion -> setGeometry(100,10,580,160);
    QVBoxLayout *organizador{new QVBoxLayout};
    organizador -> addWidget(operacion);
    //    QWidget *widget{new QWidget};
    //    widget -> setLayout(organizador);
    //    widget -> setGeometry(100,10,580,160);

    boton1 = new QPushButton{"1", this};
    boton1 -> setGeometry(100,200,100,100);
    boton2 = new QPushButton{"2", this};
    boton2 -> setGeometry(220,200,100,100);
    boton3 = new QPushButton{"3", this};
    boton3 -> setGeometry(340,200,100,100);
    botonBorrar = new QPushButton{"BORRAR", this};
    botonBorrar -> setGeometry(460,200,220,100);

    boton4 = new QPushButton{"4", this};
    boton4 -> setGeometry(100,320,100,100);
    boton5 = new QPushButton{"5", this};
    boton5 -> setGeometry(220,320,100,100);
    boton6 = new QPushButton{"6", this};
    boton6 -> setGeometry(340,320,100,100);
    botonSuma = new QPushButton{"+", this};
    botonSuma -> setGeometry(460,320,100,100);
    botonSuma -> setStatusTip("Sumar");
    botonResta = new QPushButton{"-", this};
    botonResta -> setGeometry(580,320,100,100);
    botonResta -> setStatusTip("Restar");

    boton7 = new QPushButton{"7", this};
    boton7 -> setGeometry(100,440,100,100);
    boton8 = new QPushButton{"8", this};
    boton8 -> setGeometry(220,440,100,100);
    boton9 = new QPushButton{"9", this};
    boton9 -> setGeometry(340,440,100,100);
    botonMulti = new QPushButton{"x", this};
    botonMulti -> setGeometry(460,440,100,100);
    botonMulti -> setStatusTip("Multiplicar");
    botonDivision = new QPushButton{"/", this};
    botonDivision -> setGeometry(580,440,100,100);
    botonDivision -> setStatusTip("Dividir");

    boton0 = new QPushButton{"0", this};
    boton0 -> setGeometry(220,560,100,100);
    botonResultado = new QPushButton{"=", this};
    botonResultado -> setGeometry(460,560,220,100);
    botonResultado -> setStatusTip("Obtener resultado");

    botonSalir = new QPushButton{"SALIR", this};
    botonSalir -> setGeometry(460,680,220,100);
    connect(botonSalir, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);

    QString mensaje{"Bienvenido a mi Calculadora"};
    statusBar() -> showMessage(mensaje);
}

Calculadora::~Calculadora()
{
}

void Calculadora::digitoPresionado()
{

}

void Calculadora::operadorPresionado()
{

}

void Calculadora::resultadoPresionado()
{

}

void Calculadora::borrarPresionado()
{

}
