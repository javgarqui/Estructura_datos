#include <iostream>

using namespace std;

class Rectangulo2 {
int ancho,alto;
public:
Rectangulo2(int,int);
int area() {return ancho*alto;}
};

Rectangulo2::Rectangulo2 (int x, int y) {
ancho=x;
alto=y;
} 

class Rectangulo {
int ancho,alto;
public:
Rectangulo(int,int);
int area() {return ancho*alto;}
};
Rectangulo::Rectangulo (int x, int y) : ancho(x), alto(y) { }

int main () {
Rectangulo2 rect1(10,6);
Rectangulo2 rect2{12,8};
Rectangulo2 rect3 = {4,8};
cout << "rect1 area: " << rect1.area() << endl;
cout << "rect2 area: " << rect2.area() << endl;
cout << "rect3 area: " << rect3.area() << endl;
return 0;
}