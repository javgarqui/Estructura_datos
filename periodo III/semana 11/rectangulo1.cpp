#include <iostream>

using namespace std;

class Rectangulo1 {
int ancho, alto;
public:
Rectangulo1();
Rectangulo1(int,int);
int area (void) {return ancho*alto;}
};
Rectangulo1::Rectangulo1() {
ancho = 5;
alto = 5;
}
Rectangulo1:: Rectangulo1 (int x, int y) {
ancho = x;
alto = y;
}
int main () {
Rectangulo1 rect(3,4);
Rectangulo1 rectb;
cout << "rect area: " << rect.area() << endl;
cout << "rectb area: " << rectb.area() << endl;
return 0;
}
