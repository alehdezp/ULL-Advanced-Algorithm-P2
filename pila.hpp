


#ifndef PILA_INCLUDED
#define PILA_INCLUDED
#pragma once
#include "nodo.hpp"
#include "Exception.hpp"
#include <exception>

#include <iostream>

using namespace std;

class Pila{
private:
    int size;
    Nodo *prim;
    Nodo *ult;
public:
    Pila();
    ~Pila();
    void push(string);
    string pop();
    int sizen();
    void mostrarTodo();
};

class Stack_empty_exception: public exception
{
public:
  virtual const char * what () const throw ()
  {
    return "Error en tiempo de ejecución en clase 'vector_t': Tamaño de vector incorrecto";
  }
};


#endif // PILA_INCLUDED
