

#include "pila.hpp"
#include "nodo.hpp"
#include "Exception.hpp"



Pila::Pila(){
    prim = NULL;
    ult = NULL;
    size = 0;
}

Pila::~Pila(){
}

void Pila::push(string v){
    if(size == 0){
       Nodo *e = new Nodo();
       e->setValor(v);
       prim = e;
       ult = e;
       size++;
    }
    else{
        Nodo *e = new Nodo();
        e->setValor(v);
        ult->setSig(e);
        ult = e;
        size++;
    }
}

string Pila::pop(){
    if(size == 0){
        throw Stack_empty_exception();
        
        

    }else if(size==1){

         string s=prim->getValor();
         delete ult;
         ult=prim;
         size--;
         return s;
    
    }else{
        Nodo *aux = prim;
        string s=ult->getValor();
        while(aux->getSig() != ult){
            aux = aux->getSig();
        }
        delete ult;
        ult = aux;
        ult->setSig(NULL);
        size--;
        return s;
    }
}

void Pila::mostrarTodo(){
   
      

    Nodo *aux = prim;
    cout << "Elementos restantes en la pila = ";
    while(aux != NULL){
        if(aux->getSig() == NULL){
            cout << aux->getValor() << endl;
        }
        else{
            cout << aux->getValor() << ", ";
        }
        aux = aux->getSig();
    }
}

int Pila::sizen(){
    return size;
}




