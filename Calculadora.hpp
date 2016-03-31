#include <fstream>
#include <iostream>
#include "pila.hpp"
#include "Numero.hpp"
using namespace std;


class Calculadora{
	Pila stack;
public:
	Calculadora(ifstream& is);
	~Calculadora(){};

	
	string Calcula(const string& s, const string& p, const string& item);
private:
	bool is_number(const string& s);
	bool is_operand(const string& s);
	bool is_complex(const string& s);
	bool is_real(const string& s);
	bool is_rational(const string& s);

	Numero* TipoNumero(const string& s);
	Numero* IgualaCopia(Numero* Numero1, Numero* Numero2);
};


