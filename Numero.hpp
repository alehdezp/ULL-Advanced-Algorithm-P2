#include <iostream>
#include <fstream> 
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h> 
#include "Exception.hpp"

using namespace std;


enum token_id{
	t_integer,
	t_rational,
	t_real,
	t_complex
};
 
class Numero{
	
public:
	
	virtual const Numero* toEntero() const = 0;
	virtual const Numero* toRacional() const = 0;
	virtual const Numero* toReal() const = 0;
   	virtual const Numero* toComplejo() const = 0;

   	virtual const ostream& toStream(ostream& os) const = 0;
   	virtual const ifstream& fromStream(ifstream& os) const = 0;

	virtual int getType () const = 0;
	virtual string toString () = 0;
	virtual int getInt (int i) = 0;
	virtual double getDouble (int i) = 0;

	Numero* Suma (Numero* Numero2);
	Numero* Resta (Numero* Numero2);
	Numero* Multiplica (Numero* Numero2);
	Numero* Divide (Numero* Numero2);

};


class Entero: public Numero{
int ent;
public:
	Entero(){};
	Entero(int s);
	virtual ~Entero(){}

	const Numero* toEntero() const;
	const Numero* toRacional() const;
	const Numero* toReal() const;
   	const Numero* toComplejo() const;

   	const ostream& toStream(ostream& os) const ;
   	const ifstream& fromStream(ifstream& os) const {}

   	int getType() const {return t_integer;}
	string toString();
	int getInt(int i){ return ent;}
	double getDouble(int i){}

	

};


class Racional: public Numero{
int  num, den;
public:
	Racional(){}
	Racional(int s, int n);
	virtual ~Racional(){}

	const Numero* toEntero() const;
	const Numero* toRacional() const;
	const Numero* toReal() const;
   	const Numero* toComplejo() const;

   	const ostream& toStream(ostream& os) const;
   	const ifstream& fromStream(ifstream& os) const{}
   	
   	int getType() const {return t_rational;}
	string toString();
	int getInt(int i){ if(i==0) {return num;} return den;}
	double getDouble(int i){}

};


class Real: public Numero{
double real;
public:
	Real(){}
	Real(double s);
	virtual ~Real() {}

 	const Numero* toEntero() const;
	const Numero* toRacional() const;
	const Numero* toReal() const;
   	const Numero* toComplejo() const;

   	const ostream& toStream(ostream& os) const;
   	const ifstream& fromStream(ifstream& os) const{}

   	int getType() const {return t_real;}
	string toString();
	int getInt(int i){}
	double getDouble(int i){return real;}

};

class Complejo: public Numero{
double real, imaginario;
public:
	Complejo(){}
	Complejo(double s, double n);
	virtual ~Complejo() {}

 	const Numero* toEntero() const;
	const Numero* toRacional() const;
	const Numero* toReal() const;
   	const Numero* toComplejo() const;

   	const ostream& toStream(ostream& os) const;
   	const ifstream& fromStream(ifstream& os) const{}
  
   	int getType() const {return t_complex;}
	string toString();
	int getInt(int i){}
	double getDouble(int i){ if(i==0) {return real;} return imaginario;}
};


