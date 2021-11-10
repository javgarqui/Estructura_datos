#include <iostream>

using namespace std;

class Rectangulo{
int ancho, alto;
public:
    Rectangulo();
    Rectangulo(int, int);
    int area() { return ancho * alto;}
};

Rectangulo::Rectangulo(){
    ancho = 5;
    alto = 2;
}

Rectangulo::Rectangulo(int x, int y){
    ancho = x;
    alto = y;
}

class Circulo{
    double radio;
    public:
        Circulo(double r) {radio = r;}
        double circunferencia() { return 2*radio*3.14159265; }
};

int main(){
    Rectangulo rectangulo1(3,4);
    Rectangulo rectangulo2(5,6);
    Rectangulo rectangulo3(7,3);
    Rectangulo rectangulo4;

    cout << "Area rectangulo 1: " << rectangulo1.area() << endl;
    cout << "Area rectangulo 2: " << rectangulo2.area() << endl;
    cout << "Area rectangulo 3: " << rectangulo3.area() << endl;
    cout << "Area rectangulo 4: " << rectangulo4.area() << endl;

    Circulo foo (10.0);
    Circulo bar = 20.0;
    Circulo baz {30.0};
    Circulo lux = {40.0};

    cout << "Circunferencia de foo: " << foo.circunferencia() << endl;
    cout << "Circunferencia de bar: " << bar.circunferencia() << endl;
    cout << "Circunferencia de baz: " << baz.circunferencia() << endl;
    cout << "Circunferencia de lux: " << lux.circunferencia() << endl;

    Rectangulo *rectanglep1, *rectanglep2, *rectanglep3;
    rectanglep1 = &rectangulo1;
    cout << &rectangulo1 << endl;
    rectanglep2 = new Rectangulo(5,7);
    rectanglep3 = new Rectangulo[2]{{2,5},{3,6}};
    cout << "Area rectangulo1: " << rectangulo1.area() << endl;
    cout << "Area rectanglep1: " << rectanglep1->area() << endl;
    cout << "Area rectanglep2: " << rectanglep2->area() << endl;
    cout << "Area rectanglep3[0]: " << rectanglep3[0].area() << endl;
    cout << "Area rectanglep3[0]: " << rectanglep3[1].area() << endl;

    delete rectanglep2;
    delete[] rectanglep3;

    return 0;
}
