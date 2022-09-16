//PROYECTO 1 - PARCIAL 1 PROGRAMACION ORIENTADA A OBJETOS (POO)
//ANGEL EMANUEL MENDOZA REYES 
//22110083
//CETI COLOMOS
//GRUPO 2 O
//PROFESOR :LUIS MANUEL MORALES MEDINA
#include <iostream>
#include <conio.h>  //SE INCLUYEN LIBRERIAS 
#include <stdlib.h>
using namespace std;

class Shape { //CREAMOS LA CLASE SHAPE 

public://METODOS DE LA CLASE SHAPE
    bool lleno; //DECLARAMOS LA VARIABLE LLENO QUE VA SER BOOLEANO EN ESTE CASO TRUE O FALSE
    int ejeX, ejeY;
    virtual void draw() = 0; //DECLARAMOS UNA FUNCION VIRTUAL LLAMADA DRAW.

    void setejeX(int posicion) {
        if (posicion < 0) ejeX = 0;//NO VA A ACEPTAR NUMEROS NEGATIVOS 
        else ejeX = posicion;
    }

    void setejeY(int posicion) {
        if (posicion < 0) ejeY = 0;//NO VA A ACEPTAR NUMEROS NEGATIVOS 
        else ejeY = posicion;
    }
};

class Rectangle : public Shape { //CREAMOS LA CLASE RECTANGLE Y LE HEREDAMOS LOS METODOS DE LA CLASE SHAPE
public:
    int tamano, Tamano;//DECLARAMOS LAS VARIABLES DE LAS DIMENSIONES DEL RECTANGULO

    Rectangle(char lleno, int tamano, int Tamano, int ejeX, int ejeY) { //CONSTRUCTOR DE LA CLASE RECTANGLE
        if ( lleno == 'y' or lleno == 'Y') Rectangle::lleno = true;
        else Rectangle::lleno = false;
        if (tamano < 2) Rectangle::tamano = 2;
        else Rectangle::tamano = tamano;
        Rectangle::Tamano = Tamano;
        Rectangle::setejeX(ejeX);
        Rectangle::setejeY(ejeY);
    }
    void draw() {
        for (int contador = 0; contador < tamano + ejeY; contador++) { //FUNCION PARA DIBUJAR EL RECTANGLE	
            for (int auxcontador = 0; auxcontador < Tamano + ejeX; auxcontador++) {
                if (auxcontador < ejeX or contador < ejeY) cout << "   ";
                else {
                    if (!lleno) {
                        if (contador == ejeY or contador == tamano + ejeY - 1 or auxcontador == ejeX or auxcontador == Tamano + ejeX - 1) cout << " * ";
                        else cout << "   ";
                    }
                    else cout << " * ";
                }
            }
            cout << endl;
        }
    }
};

class Square : public Shape { //CREAMOS LA CLASE SQUARE Y LE HEREDAMOS LOS METODOS DE LA CLASE SHAPE
public:
    int tamano; //DECLARAMOS LAS VARIABLES DE LAS DIMENSIONES DEL CUADRADO

    Square(char lleno, int tamano, int ejeX, int ejeY) {//CONSTRUCTOR DE LA CLASE SQUARE 
        if (lleno == 'y' or lleno == 'Y') Square::lleno= true;
        else Square::lleno = false;
        if (tamano < 2) Square::tamano = 2;
        else Square::tamano = tamano;
        Square::setejeX(ejeX);
        Square::setejeY(ejeY);
    }
    void draw() { //FUNCION PARA DIBUJAR EL CUADRADO 
        for (int contador = 0; contador < tamano + ejeY; contador++) {
            for (int auxcontador = 0; auxcontador < tamano + ejeX; auxcontador++) {
                if (auxcontador < ejeX or contador < ejeY) cout << "   ";
                else {
                    if (!lleno) {
                        if (contador == ejeY or contador == tamano + ejeY - 1 or auxcontador == ejeX or auxcontador == tamano + ejeX - 1) cout << " * ";
                        else cout << "   ";
                    }
                    else cout << " * ";
                }
            }
            cout << endl;
        }
    }
};

class Triangle : public Shape { //CREAMOS LA CLASE TRIANGLE Y LE HEREDAMOS LOS METODOS DE LA CLASE SHAPE
public:
    int tamano;

    Triangle(char lleno, int tamano, int ejeX, int ejeY) { //CONSTRUCTOR DE LA CLASE TRIANGLE
        if (lleno == 'y' or lleno == 'Y') Triangle::lleno = true;
        else Triangle::lleno = false;
        if (tamano < 2) Triangle::tamano = 2;
        else Triangle::tamano = tamano;
        Triangle::setejeX(ejeX);
        Triangle::setejeY(ejeY);
    }
    void draw() { //FUNCION PARA DIBUJAR EL TRIANGULO
        int aumentar = ejeY * -1;
        for (int contador = 0; contador < tamano + ejeY; contador++) {
            for (int auxcontador = 0; auxcontador <= ejeX + aumentar; auxcontador++) {
                if (auxcontador < ejeX or contador < ejeY) cout << "   ";
                else {
                    if (!lleno) {
                        if (contador == ejeY or contador == tamano + ejeY - 1 or auxcontador == ejeX or auxcontador == aumentar + ejeX) cout << " * ";
                        else cout << "   ";
                    }
                    else cout << " * ";
                }
            }
            aumentar++;
            cout << endl;
        }
    }
};
void drawShape(Shape*);//DECLARAMOS DRAWSHAPE EN CUAL ADENTRO DE SU PARAMETRO VA TENER UN PUNTERO ASI LA CLASE SHAPE
int main() {
    while (true) {
        int shape;//DECLARAMOS LA VARIABLE PARA GUARDAR LA RESPUESTA DEL USUARIO CONFORME A QUE FIGURA DESEA DIBUJAR
        while (true) {
            //MENU DE OPCIONES QUE EL USUARIO DECIDA EJEGIR
            cout << "SELECCIONE LA FIGURA QUE DESEA DIBUJAR\n";
            cout << "1- CUADRADO\n";
            cout << "2- RECTANGULO\n";
            cout << "3- TRIANGULO\n";
            cout << "4- SALIR\nFIGURA DESEADA: ";
            cin >> shape;

            if (shape < 1 or shape > 4) {
                system("cls");//SE LIMPIA LA PANTALLA
                cout << "FAVOR DE INGRESAR UNA OPCION VALIDA\n\n";
            }
            else break;
        }
        if (shape == 4) break;//SE ROMPE EL CICLO PRINCIPAL

        int tamano, Tamano, ejeX, ejeY;//SE DECLARAN LAS PROPIEDADES DE LAS FIGURAS
        char lleno;
        //INSTRUCCIONES QUE DEBE SEGUIR EL USUARIO
        cout << "INGRESAR EL TAMANO DE LA FIGURA *MINIMO 2*: ";
        cin >> tamano;
        if (shape == 2) {
            do {
                cout << "LAS DIMENSIONES DEBEN SER DISTINTAS PARA FORMAR UN RECTANGULO\n";
                cout << "INGRESAR EL SEGUNDO TAMANO DE LA FIGURA *MINIMO 3*: ";
                cin >> Tamano;
            } while (tamano == Tamano or Tamano < 3);
        }
        cout << "INGRESAR LA COORDENADA EN X DONDE DESEE QUE EMPIECE *POSITIVOS*: ";
        cin >> ejeX;
        cout << "INGRESAR LA COORDENADA EN Y DONDE DESEE QUE EMPIECE *POSITIVOS*: ";
        cin >> ejeY;
        do {
            cout << "\nDESEA QUE LA FIGURA ESTE LLENA? [y/n]: ";
            cin >> lleno;
        } while (lleno != 'y' && lleno != 'Y' && lleno != 'n' && lleno != 'N');
        system("cls");//SE LIMPIA LA PANTALLA
        
        //AÑADIMOS UN SWITCH EL CUAL VA A GUARDAR LA VARIABLE SHAPE 
        switch (shape) {
        case 1: {
            Square square(lleno, tamano, ejeX, ejeY);//CREAMOS EL OBJETO square con sus parametros
            drawShape(&square);//LO MANDAMOS A DIBUJAR
            break;
            }
        case 2: {
            Rectangle rectangle(lleno, tamano, Tamano, ejeX, ejeY);//CREAMOS EL OBJETO rectangle con sus parametros
            drawShape(&rectangle);//LO MANDAMOS A DIBUJAR
            break;
            }
        case 3: {
            Triangle triangle(lleno, tamano, ejeX, ejeY);//CREAMOS EL OBJETO triangle con sus parametros 
            drawShape(&triangle);//LO MANDAMOS A DIBUJAR
            break;
            }
        }
        system("cls");//SE LIMPIA LA PANTALLA
    }
}
void drawShape(Shape* shape) {//UTILIZAMOS UN PUNTERO AL OBJETO HIJO QUE SE NOS PROPORCIONE
    shape->draw();
    while (true) {
        char key = _getch();//DECLARAMOS LA VARIABLE DE TIPO CARACTER KEY SE OBTIENE LA TECLA PULSADA POR EL USUARIO
        switch (key) {
        case 27:
            return;//SALIRSE DEL CICLO "Esc" o "Escape"
            break;
        case 119://'w'
        case 87://'W'
            shape->setejeY(shape->ejeY - 1);//MOVERSE HACIA ARRIBA
            break;
        case 115://'s'
        case 83://'S' 
            shape->setejeY(shape->ejeY + 1);//MOVERSE HACIA ABAJO
            break;
        case 97://'a' 
        case 65://'A'
            shape->setejeX(shape->ejeX - 1);//MOVERSE HACIA LA IZQUIERDA
            break;
        case 100://'d'
        case 68://'D'
            shape->setejeX(shape->ejeX + 1);//MOVERSE HACIA LA DERECHA
            break;
        }
        system("cls");//SE LIMPIA PANTALLA
        shape->draw();
    }
}

