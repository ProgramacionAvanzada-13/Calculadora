#include "calculadora.h"
#include <QtWidgets>
#include <QAbstractButton>

Calculadora::Calculadora(QWidget *parent)
    : QMainWindow(parent)
{
    // 100+100+20+100+20+100+20+100+20+100+100
    // 200+100+20+100+20+100+20+100+20+100+100

    setFixedSize(780,830);
    setWindowTitle("CALCULADORA");

    num1 = new QLabel{"", this};
    num1 -> setGeometry(100,10,580,160);

    num2 = new QLabel{"", this};
    num2 -> setGeometry(440,10,580,160);

    numRes = new QLabel{"", this};
    numRes -> setGeometry(610,10,580,160);

    operacion = new QLabel{"", this};
    operacion -> setGeometry(270,10,580,160);

    QVBoxLayout *organizador{new QVBoxLayout};
    organizador -> addWidget(operacion);

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
    botonMulti = new QPushButton{"*", this};
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

    botonPunto = new QPushButton{".", this};
    botonPunto -> setGeometry(340,560,100,100);
    botonResultado = new QPushButton{"=", this};
    botonResultado -> setGeometry(460,560,220,100);
    botonResultado -> setStatusTip("Obtener resultado");

    ans = new QPushButton{"ANS", this};
    ans -> setGeometry(100,560,100,100);

    botonSalir = new QPushButton{"SALIR", this};
    botonSalir -> setGeometry(460,680,220,100);
    connect(botonSalir, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);

    QString mensaje{"Bienvenido a mi Calculadora"};
    statusBar() -> showMessage(mensaje);

    digitoPresionado();
}

Calculadora::~Calculadora()
{

}

void Calculadora::digitoPresionado()
{
    connect(boton1, &QPushButton::clicked, this, &Calculadora::setText);
    connect(boton2, &QPushButton::clicked, this, &Calculadora::setText);
    connect(boton3, &QPushButton::clicked, this, &Calculadora::setText);
    connect(boton4, &QPushButton::clicked, this, &Calculadora::setText);
    connect(boton5, &QPushButton::clicked, this, &Calculadora::setText);
    connect(boton6, &QPushButton::clicked, this, &Calculadora::setText);
    connect(boton7, &QPushButton::clicked, this, &Calculadora::setText);
    connect(boton8, &QPushButton::clicked, this, &Calculadora::setText);
    connect(boton9, &QPushButton::clicked, this, &Calculadora::setText);
    connect(boton0, &QPushButton::clicked, this, &Calculadora::setText);
    connect(botonPunto, &QPushButton::clicked, this, &Calculadora::setText);

    //*botonSuma, *botonResta, *botonMulti, *botonDivision;
    connect(botonSuma, &QPushButton::clicked, this, &Calculadora::setText);
    connect(botonResta, &QPushButton::clicked, this, &Calculadora::setText);
    connect(botonMulti, &QPushButton::clicked, this, &Calculadora::setText);
    connect(botonDivision, &QPushButton::clicked, this, &Calculadora::setText);

    //*botonBorrar, *botonResultado, *ans;
    connect(botonBorrar, &QPushButton::clicked, this, &Calculadora::borrarPresionado);
    connect(botonResultado, &QPushButton::clicked, this, &Calculadora::resultadoPresionado);
    connect(ans, &QPushButton::clicked, this, &Calculadora::setText);
}

void Calculadora::setAns()
{
    QString stR = numRes->text();
    double valR = stR.toDouble();
    num1->setNum(valR);
}

void Calculadora::resultadoPresionado()
{
    QString str1 = num1->text();
    QString str2 = num2->text();
    double val1 = str1.toDouble();
    double val2 = str2.toDouble();

    if(operacion->text()=="+"){
        numRes->setNum(val1+val2);
    }else if(operacion->text()=="-"){
        numRes->setNum(val1-val2);
    }else if(operacion->text()=="*"){
        numRes->setNum(val1*val2);
    }else if(operacion->text()=="/"){
        numRes->setNum(val1/val2);
    }else if(operacion->text()==""){
        numRes->setNum(val1);
    }else{
        numRes->setText("Syntax Error");
    }
}

void Calculadora::borrarPresionado()
{
    num1 -> clear();
    num2 -> clear();
    operacion -> clear();
    numRes->clear();
}

void Calculadora::setText1()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    if (button->text() == "0" && num1->text() == "")
    {
        return;
    }else if (button->text() == "." && num1->text().contains("."))
    {
        return;
    }else{
        QString buttonText = button->text(); // Obtener el texto del botón presionado
        QString currentText = num1->text(); // Obtener el texto actual de num1

        // Concatenar el texto del botón presionado al texto actual de num1
        num1->setText(currentText + buttonText);
    }
}

void Calculadora::setText2()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    if (button->text() == "0" && num2->text() == "")
    {
        return;
    }else if (button->text() == "." && num2->text().contains("."))
    {
        return;
    }else{
        QString buttonText = button -> text(); // Obtener el texto del botón presionado
        QString currentText = num2 -> text(); // Obtener el texto actual de num1

        // Concatenar el texto del botón presionado al texto actual de num1
        num2 -> setText(currentText + buttonText);
    }
}

void Calculadora::setTextO()
{
        QPushButton *button = qobject_cast<QPushButton *>(sender());
        QString buttonText = button->text(); // Obtener el texto del botón presionado
        QString currentText = operacion->text(); // Obtener el texto actual de num1

        operacion->setText(buttonText);
}

void Calculadora::setText()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    QString buttonText = button->text();
    QString currentText = operacion->text();

    if((button->text() == botonSuma->text() || button->text() == botonResta->text() ||
        button->text() == botonMulti->text() || button->text() == botonDivision->text()) && num1->text().isEmpty())
    {
        num1->setNum(0);
        operacion->setText(buttonText);
    }else if((button->text() == botonSuma->text() || button->text() == botonResta->text() ||
                button->text() == botonMulti->text() || button->text() == botonDivision->text()) && numRes->text() != ""){
        num1 -> clear();
        num2 -> clear();
        operacion -> clear();
        setAns();
        numRes->clear();
        setTextO();
    }else if((button->text() == botonSuma->text() || button->text() == botonResta->text() ||
                button->text() == botonMulti->text() || button->text() == botonDivision->text()) && num1->text() != ""){
        setTextO();
    }else if(button->text() == ans->text()){
        num1 -> clear();
        num2 -> clear();
        operacion -> clear();
        setAns();
        numRes->clear();
    }else if(operacion->text() == "" && numRes->text().isEmpty()){
        setText1();
    }else if(operacion->text()!="" && numRes->text().isEmpty()){
        setText2();
    }else if(!numRes->text().isEmpty()){
        num1 -> clear();
        num2 -> clear();
        operacion -> clear();
        setText1();
        numRes->clear();
    }
}
