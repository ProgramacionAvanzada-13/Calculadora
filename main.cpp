#include "calculadora.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Creamos una ventana a partir de la clase Calculadora y la mostramos
    Calculadora calculadora;
    calculadora.show();
    return a.exec();
}
