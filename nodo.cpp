

#include "nodo.hpp"
#include <iostream>
#include "Exception.hpp"

Nodo::Nodo(){
    sig = NULL;
}

Nodo::~Nodo(){

}

void Nodo::setValor(std::string v){
    valor = v;
}

string Nodo::getValor(){
    return valor;
}

void Nodo::setSig(Nodo *p){
    sig = p;
}

Nodo* Nodo::getSig(){
    return sig;
}