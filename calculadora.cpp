#include "calculadora.h"
#include <QtWidgets>

Calculadora::Calculadora(QWidget *parent)
    : QMainWindow(parent)
{
    // 100+100+20+100+20+100+20+100+20+100+100
    // 200+100+20+100+20+100+20+100+20+100+100

    // Ajustamos el tamaño de la ventana creada y de asignamos un título
    setFixedSize(780,830);
    setWindowTitle("CALCULADORA");

    // Seleccionamos un tamaño para los textos
    fuente.setPointSize(20);

    // Creamos los atributos que se mostraran en la "pantalla", les damos coordenadas y un tamaño de letra
    num1 = new QLabel{"", this};
    num1 -> setGeometry(100,30,600,50);
    num1 -> setFont(fuente);
    operador = new QLabel{"", this};
    operador -> setGeometry(100,60,600,50);
    operador -> setFont(fuente);
    num2 = new QLabel{"", this};
    num2 -> setGeometry(100,90,600,50);
    num2 -> setFont(fuente);
    numRes = new QLabel{"", this};
    numRes -> setGeometry(460,120,600,50);
    numRes -> setFont(fuente);

    // Hacemos la estructura de la primera fila de elementos en la calculadora
    // Les damos coordenadas, un tamaño de letra y un StatusTip para describir lo que realiza el boton
    boton1 = new QPushButton{"1", this};
    boton1 -> setGeometry(100,200,100,100);
    boton1 -> setStatusTip("Uno");
    boton1 -> setFont(fuente);
    boton2 = new QPushButton{"2", this};
    boton2 -> setGeometry(220,200,100,100);
    boton2 -> setStatusTip("Dos");
    boton2 -> setFont(fuente);
    boton3 = new QPushButton{"3", this};
    boton3 -> setGeometry(340,200,100,100);
    boton3 -> setStatusTip("Tres");
    boton3 -> setFont(fuente);
    botonBorrar = new QPushButton{"BORRAR", this};
    botonBorrar -> setGeometry(460,200,220,100);
    botonBorrar -> setStatusTip("Borrar datos");
    botonBorrar -> setFont(fuente);

    // Hacemos la estructura de la segunda fila de elementos en la calculadora
    // Les damos coordenadas, un tamaño de letra y un StatusTip para describir lo que realiza el boton
    boton4 = new QPushButton{"4", this};
    boton4 -> setGeometry(100,320,100,100);
    boton4 -> setStatusTip("Cuatro");
    boton4 -> setFont(fuente);
    boton5 = new QPushButton{"5", this};
    boton5 -> setGeometry(220,320,100,100);
    boton5 -> setStatusTip("Cinco");
    boton5 -> setFont(fuente);
    boton6 = new QPushButton{"6", this};
    boton6 -> setGeometry(340,320,100,100);
    boton6 -> setStatusTip("Seis");
    boton6 -> setFont(fuente);
    botonSuma = new QPushButton{"+", this};
    botonSuma -> setGeometry(460,320,100,100);
    botonSuma -> setStatusTip("Sumar");
    botonSuma -> setFont(fuente);
    botonResta = new QPushButton{"-", this};
    botonResta -> setGeometry(580,320,100,100);
    botonResta -> setStatusTip("Restar");
    botonResta -> setFont(fuente);

    // Hacemos la estructura de la tercera fila de elementos en la calculadora
    // Les damos coordenadas, un tamaño de letra y un StatusTip para describir lo que realiza el boton
    boton7 = new QPushButton{"7", this};
    boton7 -> setGeometry(100,440,100,100);
    boton7 -> setStatusTip("Siete");
    boton7 -> setFont(fuente);
    boton8 = new QPushButton{"8", this};
    boton8 -> setGeometry(220,440,100,100);
    boton8 -> setStatusTip("Ocho");
    boton8 -> setFont(fuente);
    boton9 = new QPushButton{"9", this};
    boton9 -> setGeometry(340,440,100,100);
    boton9 -> setStatusTip("Nueve");
    boton9 -> setFont(fuente);
    botonMulti = new QPushButton{"*", this};
    botonMulti -> setGeometry(460,440,100,100);
    botonMulti -> setStatusTip("Multiplicar");
    botonMulti -> setFont(fuente);
    botonDivision = new QPushButton{"/", this};
    botonDivision -> setGeometry(580,440,100,100);
    botonDivision -> setStatusTip("Dividir");
    botonDivision -> setFont(fuente);

    // Hacemos la estructura de la cuarta fila de elementos en la calculadora
    // Les damos coordenadas, un tamaño de letra y un StatusTip para describir lo que realiza el boton
    botonAns = new QPushButton{"ANS", this};
    botonAns -> setGeometry(100,560,100,100);
    botonAns -> setStatusTip("Resultado anterior");
    botonAns -> setFont(fuente);
    boton0 = new QPushButton{"0", this};
    boton0 -> setGeometry(220,560,100,100);
    boton0 -> setStatusTip("Cero");
    boton0 -> setFont(fuente);
    botonPunto = new QPushButton{".", this};
    botonPunto -> setGeometry(340,560,100,100);
    botonPunto -> setStatusTip("Punto");
    botonPunto -> setFont(fuente);
    botonResultado = new QPushButton{"=", this};
    botonResultado -> setGeometry(460,560,220,100);
    botonResultado -> setStatusTip("Obtener resultado");
    botonResultado -> setFont(fuente);

    // Hacemos la estructura de la quinta fila de elementos en la calculadora
    // Les damos coordenadas, un tamaño de letra y un StatusTip para describir lo que realiza el boton
    botonSalir = new QPushButton{"SALIR", this};
    botonSalir -> setGeometry(460,680,220,100);
    botonSalir -> setStatusTip("Salir");
    botonSalir -> setFont(fuente);
    // Conectamos el boton de salida a una acción, en el instante en el que es presionado la aplicación se cierra
    // connect(botonSalir, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);

    // Agregamos una barra de estado que nos muestra los Tips y un mensaje al iniciar la aplicación
    QString mensaje{"Bienvenido a mi Calculadora"};
    statusBar() -> showMessage(mensaje);

    // Añadimos la acción de presionar un boton
    botonPresionado();
}

Calculadora::~Calculadora() // Destructor
{

}

void Calculadora::botonPresionado()
{
    // En esta función realizamos la conección de cada uno de los botones con la accion que realiza al ser presionado

    // boton1, boton2, boton3, boton4, boton5
    // boton6, boton7, boton8, boton9, boton0, botonPunto
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

    // botonSuma, botonResta, botonMulti, botonDivision;
    connect(botonSuma, &QPushButton::clicked, this, &Calculadora::setText);
    connect(botonResta, &QPushButton::clicked, this, &Calculadora::setText);
    connect(botonMulti, &QPushButton::clicked, this, &Calculadora::setText);
    connect(botonDivision, &QPushButton::clicked, this, &Calculadora::setText);

    // botonBorrar, botonResultado, ans;
    connect(botonBorrar, &QPushButton::clicked, this, &Calculadora::borrarPresionado);
    connect(botonResultado, &QPushButton::clicked, this, &Calculadora::resultadoPresionado);
    connect(botonAns, &QPushButton::clicked, this, &Calculadora::setText);

    // botonSalir
    connect(botonSalir, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);
}

void Calculadora::setAns() // Coloca el valor del resultado anterior en num1
{
    QString stR = numRes->text(); // Extrae el texto del resultado en un QString
    double valR = stR.toDouble(); // Convierte el QString en un double para realizar operaciones con él
    num1 -> setNum(valR);         // Le asigna el valor contenido en valR a num1
}

void Calculadora::resultadoPresionado() // Realiza las operaciones
{
    QString str1 = num1 -> text(); // Extrae el texto del num1 en un QString
    QString str2 = num2 -> text(); // Extrae el texto del num2 en un QString
    double val1 = str1.toDouble(); // Convierte el QString en un double para realizar operaciones con él
    double val2 = str2.toDouble(); // Convierte el QString en un double para realizar operaciones con él

    if(operador -> text() == "+"){          // Operación Suma
        numRes -> setNum(val1+val2);        // Realiza la suma y le asigna el valor numérico al resultado
    }else if(operador -> text() == "-"){    // Operación Resta
        numRes -> setNum(val1-val2);        // Realiza la resta y le asigna el valor numérico al resultado
    }else if(operador -> text() == "*"){    // Operación Multiplicación
        numRes -> setNum(val1*val2);        // ORealiza la multiplicación y le asigna el valor numérico al resultado
    }else if(operador -> text() == "/"){    // Operación División
        numRes -> setNum(val1/val2);        // Realiza la división y le asigna el valor numérico al resultado
    }else if(operador -> text() == ""){     // Operador Nulo
        numRes -> setNum(val1);             // Devuelve el primer valor ya que no se realizó ninguna operación
    }else{                                  // Excepción
        numRes -> setText("Syntax Error");  // Envía un mensaje de error
    }
}

void Calculadora::borrarPresionado() // Borra lo que haya en la pantalla
{
    // Limpia todos los valores para realizar una operacion nueva
    num1 -> clear();
    num2 -> clear();
    operador -> clear();
    numRes -> clear();
}

void Calculadora::setNum1() // Asigna digitos al primer numero
{
    // La funcion sender() es un puntero y devuelve el objeto que emitió la señal
    // Utilizamos qobject_cast para convertir el puntero generico  de QObject obtenido en uno específico de QPushButton
    boton = qobject_cast<QPushButton *>(sender());
    textoBoton = boton -> text(); // Obtiene el texto del botón presionado
    textoActual = num1 -> text(); // Obtiene el texto actual de num1

    if (boton -> text() == "0" && num1 -> text().isEmpty()){
        // Si el digito presionado es un "0" y la pantalla esta vacia no devuelve nada
        return;
    } else if (boton -> text() == "." && num1 -> text().contains(".")){
        // Si el digito presionado es un "." y el num1 ya contiene un punto no devuelve nada
        return;
    } else{
        // Concatena el texto del botón presionado al texto actual de num1
        num1 -> setText(textoActual + textoBoton);
    }
}

void Calculadora::setNum2() // Asigna digitos al segundo numero
{
    // La funcion sender() es un puntero y devuelve el objeto que emitió la señal
    // Utilizamos qobject_cast para convertir el puntero generico  de QObject obtenido en uno específico de QPushButton
    boton = qobject_cast<QPushButton *>(sender());
    textoBoton = boton -> text(); // Obtiene el texto del botón presionado
    textoActual = num2 -> text(); // Obtiene el texto actual de num1

    if (boton -> text() == "0" && num2 -> text().isEmpty()){
        // Si el digito presionado es un "0" y el num2 esta vacio no devuelve nada
        return;
    }else if (boton -> text() == "." && num2 -> text().contains(".")){
        // Si el digito presionado es un "." y el num2 ya contiene un punto no devuelve nada
        return;
    }else{
        // Concatena el texto del botón presionado al texto actual de num1
        num2 -> setText(textoActual + textoBoton);
    }
}

void Calculadora::setOperador() // Asigna el operador presionado
{
    // La funcion sender() es un puntero y devuelve el objeto que emitió la señal
    // Utilizamos qobject_cast para convertir el puntero generico  de QObject obtenido en uno específico de QPushButton
    boton = qobject_cast<QPushButton *>(sender());
    textoBoton = boton -> text();    // Obtener el texto del botón presionado
    operador -> setText(textoBoton); // Asigna el operador
}

void Calculadora::setText()
{
    // La funcion sender() es un puntero y devuelve el objeto que emitió la señal
    // Utilizamos qobject_cast para convertir el puntero generico  de QObject obtenido en uno específico de QPushButton
    boton = qobject_cast<QPushButton *>(sender());
    textoBoton = boton -> text(); // Obtener el texto del botón presionado

    if((boton -> text() == botonSuma -> text() || boton -> text() == botonResta -> text() ||
         boton -> text() == botonMulti -> text() || boton -> text() == botonDivision -> text()) && num1 -> text().isEmpty()){
        // Si el boton presionado es un operador y la pantalla esta vacia, asigna un "0" al valor de num1
        num1 -> setNum(0);
        // Y agrega el operador seleccionado
        operador -> setText(textoBoton);
    }else if((boton -> text() == botonSuma -> text() || boton -> text() == botonResta -> text() ||
                boton -> text() == botonMulti -> text() || boton -> text() == botonDivision -> text()) && numRes -> text() != ""){
        // Si el boton presionado es un operador y existe un resultado, asigna el valor del resultado a num1
        num1 -> clear();
        num2 -> clear();
        operador -> clear();
        setAns();
        numRes -> clear();
        setOperador();
    }else if((boton -> text() == botonSuma -> text() || boton -> text() == botonResta -> text() ||
                boton -> text() == botonMulti -> text() || boton -> text() == botonDivision -> text()) && num1 -> text() != ""){
        // Si el boton presionado es un operador y existe un valor en num1, agrega el operador
        setOperador();
    }else if(boton -> text() == botonAns -> text()){
        // Si se presionó el boton de "ANS", asigna el valor del resultado a num1 y limpia lo demás
        num1 -> clear();
        num2 -> clear();
        operador -> clear();
        setAns();
        numRes -> clear();
    }else if(operador -> text().isEmpty() && numRes -> text().isEmpty()){
        // Si el boton presionado es un número y no existe un operador ni un resultado, asigna el numero a num1
        setNum1();
    }else if(operador -> text() != "" && numRes -> text().isEmpty()){
        // Si el boton presionado es un número y existe un operador, asigna el numero a num2
        setNum2();
    }else if(!numRes -> text().isEmpty()){
        // Si el boton presionado es un número y existe un resultado, limpia todo y asigna el numero a num1
        num1 -> clear();
        num2 -> clear();
        operador -> clear();
        setNum1();
        numRes -> clear();
    }
}
