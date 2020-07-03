#include <iostream>
#include <string>
#include <vector>
#include "Stack.h"
#include "Node.h"
#include "Object.h"
#include "Matrix.h"
#include "Operator.h"


using namespace std;

//Funcion que elimina espacios
string eliminarEspacios(string);

int main(int argc, char** argv) {
	
	vector<Matrix*> matrices;
	
	while(true) {
		cout << ">>";
		
		string line;
		getline(cin,line);
		
		//cin.clear();
		//cin.ignore(100,'\n');
		
		//limpiar de espacios
		line = eliminarEspacios(line);
		
		if(line.back() == ']') {
			
			matrices.push_back(new Matrix(line));
			
			matrices.back()->display();
			
		} else if (line == "exit") {
			
			break;
			
		} else {
			
			Stack stack;
			
			for(int i = line.size()-1; i >= 0 ; i--) {
				if(line[i] == '+' || line[i] == '-' || line[i] == '*') {
					stack.push(new Node(new Operator(line[i])));
				} else {
					for(int j = 0; j < matrices.size(); j++) {
						if (matrices[j]->identificador == line[i]) {
							stack.push(new Node(matrices[j]));
							break;
						}
					} 
				}
			}
			
			Matrix res;
			while(stack.top()->getNext() != nullptr) {
				
				Matrix* m1;
				Matrix* m2;
				Operator* op;
				
				m1 = (Matrix*) (stack.pop()->getData()) ;
				op = (Operator*) stack.pop()->getData() ;
				m2 = (Matrix*) stack.pop()->getData();
				
				switch(op->operacion) {
					case '+': {
						res = *m1 + (*m2); 
						stack.push(new Node(&(res)));
						break;
					}
					case '-': {
						res = *m1 - (*m2);
						stack.push(new Node(&(res)));
						break;
					}
					case '*': {
						res = *m1 * (*m1);
						stack.push(new Node(&(res)));
						break;
					}
				}
			}
			
			Matrix* m4 = (Matrix*) (stack.top()->getData());
			m4->display();
			
		}
		
	}
	
	
	return 0;
}

//Funcion que elimina espacios
string eliminarEspacios(string str) {
	
	for(int i = 0; i < str.size(); i++) {
		if(str[i] == ' ') {
			str.erase(str.begin() + i);
		}
	}
	
	return str;
}
