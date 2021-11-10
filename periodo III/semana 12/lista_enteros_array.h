#ifndef lista_generica_hpp
#define lista_generica_hpp
#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::ostringstream;
using std::cout;
using std::endl;

class ListaEnteros {
private:
    int cuenta;
    int capacidad;
    int *items;
    void agrandar();
public:
    ListaEnteros(int capacidad);
    ListaEnteros();
    ~ListaEnteros();
    ListaEnteros(const ListaEnteros &otra);
    bool estaVacia();
    int tamanio();
    void insertar(int indice, int item);
    void adjuntar(int item);
    int  obtener(int indice);
    bool contiene(int item);
    int remover(int indice);
    string comoCadena();
};

// constructor 
ListaEnteros::ListaEnteros(int capacidad) { 
    cout << "Creando una lista vacia..." << endl;
    this->cuenta = 0;
    this->capacidad = capacidad;
    this->items = new int[capacidad];
    cout << " La lista tiene capacidad para " << this->capacidad << " elementos" << endl;
}

ListaEnteros::ListaEnteros() :  ListaEnteros(4) {}

ListaEnteros::~ListaEnteros() {
    cout << "Destruyendo la lista..." << endl;
    delete[] items;
}

ListaEnteros::ListaEnteros(const ListaEnteros &otra) {
    cout << "Copiando una lista desde otra..." << endl;
    this->cuenta = otra.cuenta;
    this->capacidad = otra.capacidad;
    this->items = new int[capacidad];
    for( int i = 0; i < this->cuenta; i++)
        this->items[i] = otra.items[i];
}

// esta la lista vacia?
bool ListaEnteros::estaVacia() {
    cout << "Comprobando si la lista esta vacia..." << endl;
    return this->cuenta == 0;
}

// tamano de la lista
int ListaEnteros::tamano() {
    cout << "Obteniendo el tamano de la lista..." << endl;
    return this->cuenta;
}

void ListaEnteros::agrandar() {
    cout << "Duplicando el tamano de la lista..." << endl;
    int *temp = this->items;
    this->capacidad *= 2;
    this->items = new int[capacidad];
    for (int i = 0; i < cuenta; i++)
        this->items[i] = temp[i];
    delete[] temp;
    cout << " La lista tiene capacidad para " << this->capacidad << " elementos " << endl;
} 

// insertar un elemento en un indice especifica
void ListaEnteros::insertar(int indice, int item ) {
    // validar el indice
    if(indice < 0 || indice > this->cuenta) throw "Indice fuera de rango";
    
    // agrandar la lista si el elemento no cabe
    if (this->cuenta >= this->capacidad) this->agrandar();

    cout << "Insertando un elemento..."  << endl;
    // Desplazar elementos a partir del indice a la derecha
    for(int i = cuenta - 1; i >= indice; i--) {
        cout << " Desplazando elemento " << items[i] << " del indice";
        cout << i << " al indie " << (i+1) << endl;
        this->items[i+1] = this->items[i];
    }

    // insertar nuevo elemento
    cout << " Insertando elemento " << item << " en el indice " << indice << endl;
    this->items[indice] = item;

    // incrementar la cuenta de elementos
   cout << " Incrementando la cuenta de elementos" << endl;
    this->cuenta++;
}

// Agregando un elemento al final
void ListaEnteros::adjuntar(int item) {
    this->insertar(this->cuenta, item);
} 

// Valor del elemento en la posicion indice
int  ListaEnteros::obtener(int indice) {
    // validar el indice
    if( indice < 0 || indice >= this->cuenta) throw "Indice fuera de rango";
    if(this->estaVacia()) throw "No se puede recuperar elementos de una lista vacia";

    cout << "Recuperando elemento en el indice " << indice << endl;
    return this->items[indice]; 
}

// Esta el item en la lista ?
bool ListaEnteros::contiene(int item) {
    for(int i = 0; i < this->cuenta; i++){
        cout << "Recorriendo elemento con indice " << endl;
        if(this->items[i] == item)
            return true;
    }

    return false;
}

// Remover elementos en ek indice indice'
int ListaEnteros::remover(int indice) {
    // validar el indice
    if(this->estaVacia()) throw "No se puede remover elementos de una lista vacia";
    if(indice < 0 || indice >= this->cuenta) throw "Indice fuera de rango";

    cout << "Removiendo el elemento con indice " << indice << "..." << endl;
    // Lee el valor en el indice y desplaza elementos a la izquierda
   int valor = this->items[indice];
    for( int i = indice; i < cuenta - 1; i++) {
        cout << " Desplazando elemento " << items[i] << " del indice";
        cout << (i+1) << " al indice " << i << endl;
        this->items[i] = this->items[i+1];
    } 

    // Reducir la cuenta de elementos
    cout << " Reduciendo la cuenta de elementos" << endl;
    this->cuenta--;
    return valor;
}

string ListaEnteros::comoCadena() {
    ostringstream s;
    s << "[";
    for(int  i = 0; i <(this->cuenta); i++) {
        s << this->items[i];
        if (i < this->cuenta-1)
            s << " , ";
    }
    s << "]";
    return s.str();

}

#endif 