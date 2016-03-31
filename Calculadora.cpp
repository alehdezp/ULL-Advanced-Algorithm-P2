#include "Calculadora.hpp"
#include "Exception.hpp"


Calculadora::Calculadora(ifstream& is){
	
	string item;
	
	while(!is.eof()){
    	getline(is >> ws, item, ' ');

	    if(is_number(item)){
    		stack.push(item);
		}else if(is_operand(item)){
			stack.push(Calcula(stack.pop(), stack.pop(), item));
		}else{
			cout<<"error";
		}

	}	
	stack.mostrarTodo();
}

Numero* Calculadora::TipoNumero(const string& s){

			if (is_complex(s)){						
				string::size_type pos = s.find("i");
				string suma = s.substr (0, pos);
				pos = suma.find("+");
				string re = suma.substr (0, pos);
				string im = suma.substr (pos+1);
		
				return new Complejo(stod(re), stod(im));

			}else if(is_real(s)) {
				return new Real(stod(s));

			}else if(is_rational(s)){
		
				string::size_type pos= s.find("/");
				string num = s.substr (0, pos);
				string den = s.substr (pos+1);
			
				return new Racional(stod(num), stod(den));

			}else{
				return new Entero(stod(s));
			}
}

 Numero* Calculadora::IgualaCopia(Numero* Numero1, Numero* Numero2){
	
	if(Numero2->getType()==t_integer){
		return const_cast<Numero*>(Numero1->toEntero());

	}else if (Numero2->getType()==t_rational){
		return const_cast<Numero*>(Numero1->toRacional());

	}else if (Numero2->getType()==t_real){
		return const_cast<Numero*>(Numero1->toReal());

	}else{
		return const_cast<Numero*>(Numero1->toComplejo());
	}
}

string Calculadora::Calcula(const string& s, const string& p, const string& item){

	Numero* Numero1 = TipoNumero(s);

	Numero* Numero2 = TipoNumero(p);
	
	if(Numero1->getType()==Numero2->getType()){

	}else if(Numero1->getType() > Numero2->getType()){

		Numero2 = IgualaCopia(Numero2, Numero1);
		
	}else if(Numero1->getType() < Numero2->getType()){
		Numero1 = IgualaCopia(Numero1, Numero2);
	}

		switch (item[0]){
			case '+':
			    Numero1->toStream(cout); cout << " + ";
			    Numero2->toStream(cout); cout << " = ";
				Numero1= Numero1->Suma(Numero2);
				Numero1->toStream(cout); cout << endl;
				break;
			case '-':
				Numero1->toStream(cout); cout << " - ";
			    Numero2->toStream(cout); cout << " = ";
				Numero1 = Numero1->Resta(Numero2);
				Numero1->toStream(cout); cout << endl;
				break;
			case '*':
				Numero1->toStream(cout); cout << " * ";
			    Numero2->toStream(cout); cout << " = ";
				Numero1 = Numero1->Multiplica(Numero2);
				Numero1->toStream(cout); cout << endl;
				break;
			case '/':
				Numero1->toStream(cout); cout << " / ";
			    Numero2->toStream(cout); cout << " = ";
				Numero1 = Numero1->Divide(Numero2);
				Numero1->toStream(cout); cout << endl;
				break;

			}


	return Numero1->toString();
	
}

bool Calculadora::is_number(const string& s){
    return ( ((s[0] == '-') && isdigit(s[1])) || isdigit(s[0]) );
}

bool Calculadora::is_operand(const string& s){
	size_t sz = s.size();
		return ((sz == 1) && ((s[0] == '-') 
			|| (s[0] == '+') 
			|| (s[0] == '*') 
			|| (s[0] == '/')));
}
bool Calculadora::is_complex(const string& s){
	size_t found = s.find("i");
	
	return is_number(s) && (found != string::npos);
}

bool Calculadora::is_real(const string& s){
	size_t found1 = s.find(".");
	size_t found2 = s.find("E");
	size_t found3 = s.find("e");
	
	return is_number(s) && ((found1 != string::npos) || (found2 != string::npos) || (found3 != string::npos));
}

bool Calculadora::is_rational(const string& s){
	size_t found1 = s.find("/");
	return is_number(s)	&&  (found1 != string::npos);
}