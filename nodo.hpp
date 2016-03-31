#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <iostream>
#include "Exception.hpp"
using namespace std;



class Nodo{
private:
    string valor;
    Nodo *sig;
public:
    Nodo();
    ~Nodo();
    void setValor(std::string);
    string getValor();
    void setSig(Nodo*);
    Nodo *getSig();
};

#endif // NODO_H_INCLUDED
