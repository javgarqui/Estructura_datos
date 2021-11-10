#ifndef CIRCULO
#define CIRCULO

const double PI = 3.14159265;

class Circulo{
private:
    double radio;
public:
    Circulo(double r);
    double getRadio();
    double calcularArea();
    double calcularDiametro();
    double calcularPerimetro();
};

Circulo::Circulo(double r){
    this->radio = r;
}

double Circulo::getRadio(){
    this->radio;
}

double Circulo::calcularArea(){
    return PI * pow(this->radio, 2);
}

double Circulo::calcularDiametro(){
    return 2 * this->radio;
}

double Circulo::calcularPerimetro(){
    return 2 * PI * this->radio;
}

#endif 
