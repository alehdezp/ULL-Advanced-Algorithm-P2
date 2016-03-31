#include "Numero.hpp"
#include "Exception.hpp"



Numero* Numero::Suma( Numero* Numero2) {
	if(getType()==t_integer){
		return new Entero(getInt(0)+Numero2->getInt(0));
		
	}
	else if(getType()==t_rational){
		int comun=getInt(1)*Numero2->getInt(1);
		int suma=getInt(0)*Numero2->getInt(1)+Numero2->getInt(0)*getInt(1);
		
		if(comun==0)
			throw Rational_execption();

		return new Racional(suma, comun);

	}else if(getType()==t_real){
		return new Real(getDouble(0)+Numero2->getDouble(0));

	}else if(getType()==t_complex){
		double real=getDouble(0)+Numero2->getDouble(0);
		double imaginario=getDouble(1)+Numero2->getDouble(1);
		return new Complejo(real, imaginario);

	}

}

Numero* Numero::Resta(Numero* Numero2){
	if(getType()==t_integer){
		return new Entero(getInt(0)-Numero2->getInt(0));
	}
	else if(getType()==t_rational){
		int comun=getInt(1)*Numero2->getInt(1);
		int suma=getInt(0)*Numero2->getInt(1)-Numero2->getInt(0)*getInt(1);
		
		if(comun==0)
			throw Rational_execption();

		return new Racional(suma, comun);

	}else if(getType()==t_real){
		return new Real(getDouble(0)-Numero2->getDouble(0));

	}else if(getType()==t_complex){
		double real=getDouble(0)-Numero2->getDouble(0);
		double imaginario=getDouble(1)-Numero2->getDouble(1);
		return new Complejo(real, imaginario);

	}

}


Numero* Numero::Multiplica(Numero* Numero2){
	if(getType()==t_integer){
		return new Entero(getInt(0)*Numero2->getInt(0));
	}
	else if(getType()==t_rational){
		int comun=getInt(1)*Numero2->getInt(1);
		int suma=getInt(0)*Numero2->getInt(0);

		if(comun==0)
			throw Rational_execption();

		return new Racional(suma, comun);

	}else if(getType()==t_real){
		return new Real(getDouble(0)*Numero2->getDouble(0));

	}else if(getType()==t_complex){
		double real=getDouble(0)*Numero2->getDouble(0)+getDouble(1)*Numero2->getDouble(1);
		double imaginario=getDouble(0)*Numero2->getDouble(1)+getDouble(1)*Numero2->getDouble(0);
		return new Complejo(real, imaginario);

	}else{cout<<"Error al sumar"<<endl;}

}

		

Numero* Numero::Divide(Numero* Numero2){
	if(getType()==t_integer){
		if(Numero2->getInt(0)==0)
			throw Dividir_execption();

		return new Entero(getInt(0)/Numero2->getInt(0));
	}
	else if(getType()==t_rational){
		int comun=getInt(1)*Numero2->getInt(0);
		int suma=getInt(0)*Numero2->getInt(1);

		if(comun==0)
			throw Rational_execption();
		return new Racional(suma, comun);

	}else if(getType()==t_real){
		if(Numero2->getDouble(0)==0)
			throw Dividir_execption();
		return new Real(getDouble(0)/Numero2->getDouble(0));

	}else if(getType()==t_complex){
		double real=getDouble(0)*Numero2->getDouble(0)+getDouble(1)*-Numero2->getDouble(1);
		double imaginario=getDouble(0)*-Numero2->getDouble(1)+getDouble(1)*Numero2->getDouble(0);
		double divisor=Numero2->getDouble(0)*Numero2->getDouble(0)+Numero2->getDouble(1)*-Numero2->getDouble(1);
		
		if(divisor==0)
			throw Dividir_execption();

		return new Complejo(real/divisor, imaginario/divisor);

	}else{cout<<"Error al sumar"<<endl;}

}





Entero::Entero(int s){
	ent=s;
}

const Numero* Entero::toEntero() const{
	return new Entero(ent);
}

const Numero* Entero::toRacional() const{
	return new Racional(ent, 1);
}

const Numero* Entero::toReal() const{
	return new Real((double) ent);
}

const Numero* Entero::toComplejo() const{
	return new Complejo((double) ent, 0.0);
}

string Entero::toString(){
	return to_string(ent);
}

const ostream& Entero::toStream(ostream& os) const{
	os << to_string(ent);
	return os;
}


Racional::Racional(int s, int n){
	num=s;
	den=n;
}

const Numero* Racional::toEntero() const{

	throw Non_conversion_execption();
	/*return new Entero();*/
}

const Numero* Racional::toRacional() const{
	return new Racional(num, den);
}

const Numero* Racional::toReal()const{
	return new Real((double) num/den);
}

const Numero* Racional::toComplejo() const{
	return new Complejo((double) num/den, 0.0);
}

string Racional::toString(){

	return to_string(num)+'/'+ to_string(den);
}

const ostream& Racional::toStream(ostream& os) const{
	
	os << to_string(num)<<"/"<<to_string(den);
return os;
}




Real::Real(double s){
	real=s;
}

const Numero* Real::toEntero() const{

	throw Non_conversion_execption();
	/*return new Entero();*/
}

const Numero* Real::toRacional() const{

	throw Non_conversion_execption();
	/*return new Racional(num, den);*/
}

const Numero* Real::toReal()const{
	return new Real(real);
}

const Numero* Real::toComplejo()const{
	return new Complejo(real, 0.0);
}

string Real::toString(){
	ostringstream s;
	s << fixed << setprecision(2) << real;
	return s.str();
}

const ostream& Real::toStream(ostream& os) const{
	
	os << fixed << setprecision(2) << real;
return os;
}


Complejo::Complejo(double s, double n){
	real=s;
	imaginario=n;
}

const Numero* Complejo::toEntero() const{

	throw Non_conversion_execption();
	/*return new Entero();*/
}

const Numero* Complejo::toRacional() const{

	throw Non_conversion_execption();
	/*return new Racional(num, den);*/
}

const Numero* Complejo::toReal() const{

	throw Non_conversion_execption();
	/*return new Real(real);*/
}

const Numero* Complejo::toComplejo() const{
	return new Complejo(real, 0.0);
}

string Complejo::toString(){
	ostringstream s, sr;
	s << fixed << setprecision(2) << real;
	sr << fixed << setprecision(2) << imaginario;
	return s.str() + '+' + sr.str() + 'i';
}

const ostream& Complejo::toStream(ostream& os) const{
	
	os << fixed << setprecision(2) << real;
	os << "+";
	os << fixed << setprecision(2) << imaginario;
	os << "i";
	return os;
}

/*
int main(){
	
	Numero* a = new Entero(4);
	Numero* b = new Entero(3);
	
  	cout<<a->toString()<<endl;

	}*/






