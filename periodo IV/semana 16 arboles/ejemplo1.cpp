#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class ArbolBinarioBusqueda;


class NodoArbol {
    friend class ArbolArbolBinarioBusqueda;
private:
   string Clave;
   int valor;
   NodoArbol *izq;
   NodoArbol *der;

public:
    NodoArbol(string Clave, int valor) : Clave(Clave), valor(valor), izq(0), der(0) {

    }
};

class ArbolBinarioBusqueda {
    private:
        NodoArbol *raiz;
        int numeroNodos;
        void auxiliarPoner(NodoArbol *&raizSubarbol, string clave, int valor);
        void auxiliarDestruir(NodoArbol *raizSubarbol);
        void auxiliarBorrar(NodoArbol *&raizSubarbol,string clave);
        void auxiliarEnOrden(NodoArbol *raizSubarbol, vector<string> &v);
        void auxiliarCopiar(NodoArbol *raizSubarbol);
        NodoArbol *desvincularMinimo(NodoArbol *&raizSubarbol);
    public:
        ArbolBinarioBusqueda();
        ~ArbolBinarioBusqueda();
        ArbolBinarioBusqueda(const ArbolBinarioBusqueda &otro);
        int obtener(string clave);
        void poner(string clave, int valor);
        bool contiene (const string &clave);
        void borrar(string clave);
        bool estaVacio();
        bool tamano();
        vector<string> claves();

};
