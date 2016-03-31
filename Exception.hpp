#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <iostream>
#include <exception>

using namespace std;

class vector_exception: public exception{
  
};

class Non_conversion_execption : public vector_exception{
public:
  virtual const char * what () const throw ()
  {
    return "Error en tiempo de ejecución en la clase hija de 'Numero': Tipo de conversion no definido";
  }
};


class Dividir_execption : public vector_exception{
public:
  virtual const char * what () const throw ()
  {
    return "Error en tiempo de ejecución en la clase 'Numero': División por 0";
  }
};

class Rational_execption : public vector_exception{
public:
  virtual const char * what () const throw ()
  {
    return "Error en tiempo de ejecución en clase 'Numero': Denominador de la clase Racional es 0, valor no valido";
  }
};

class Dinamic_memory_exception : public bad_alloc{
public:
  virtual const char * what () const throw ()
  {
    return "Error en tiempo de ejecución al asignar memoria dinamica: Fallo en el uso de new";
  }
};

class Stack_empty_exception: public exception
{
public:
  virtual const char * what () const throw ()
  {
    return "Error en tiempo de ejecución en clase 'vector_t': Tamaño de vector incorrecto";
  }
};
#endif // NODO_H_INCLUDED
