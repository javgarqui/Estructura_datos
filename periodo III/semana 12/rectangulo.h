#ifndef RECTANGULO
#define RECTANGULO

class Rectangulo{
    private:
     double base;
     double altura;
public:
    Rectangulo(double b, double h);
    double calcularArea();
    double calcularPerimetro();
    double getBase;
    double getAltura;
};

Rectangulo::Rectangulo(double b, double h){
    this->base = b;
    this->altura = h;
}

double Rectangulo::calcularArea(){
    return this->base * this->altura;
}

double Rectangulo::calcularPerimetro(){
    return 2 * (this->base * this->altura);
}

double Rectangulo::getBase(){
    return this->base;
}

double Rectangulo::getAltura(){
    return this->altura;
}

#endif 


