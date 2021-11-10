#include <iostream>

using namespace std;

class Cuadrado;

class Rectangulo{
        double ancho, alto;
    public:
        double area(){ return (ancho * alto); }
        void convertir (Cuadrado a);
};

class Cuadrado{
    friend class Rectangulo;
    private:
        double lado;
    public:
        Cuadrado(double a) : lado(a) {}
};

void Rectangulo::convertir(Cuadrado a){
    ancho = a.lado;
    alto = a.lado;
}

int main(){
    Rectangulo r1;
    Cuadrado c1(4);
    r1.convertir(c1);
    cout << r1.area();
    return 0;
}