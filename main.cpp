#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Stack.h"
#include "Node.h"
#include "Object.h"
#include "Matrix.h"
#include "Operator.h"


using namespace std;

//Funcion que elimina espacios
string eliminarEspacios(string);

//Funcion que escribe las matrices
void escribirMatrices(vector<Matrix*>);

//Funcion que lee las matrices
void leerMatrices(vector<Matrix*>&);

int main(int argc, char** argv) {
	
	vector<Matrix*> matrices;
	
	leerMatrices(matrices);
	
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
			
			int size = -1;
			
			Stack stack;
			
			bool error = false;
			
			for(int i = line.size()-1; i >= 0 ; i--) {
				if(line[i] == '+' || line[i] == '-' || line[i] == '*') {
					stack.push(new Node(new Operator(line[i])));
				} else {
					for(int j = 0; j < matrices.size(); j++) {
						if (matrices[j]->identificador == line[i]) {
							if(size == -1) {
								size = matrices[j]->size;
							}
							if(size != matrices[j]->size) {
								cout << endl << "No se puede realizar la operacion: Matrices de diferente dimension" << endl;
								error = true;
								break;
							}
							stack.push(new Node(matrices[j]));
							break;
						}
						
					} 
				}
				
				if(error) {
					break;
				}
			}
			
			if(error) {
				continue;
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
						res = *m1 * (*m2);
						stack.push(new Node(&(res)));
						break;
					}
				}
			}
			
			Matrix* m4 = (Matrix*) (stack.top()->getData());
			m4->display();
			
		}
		
	}
	
	escribirMatrices(matrices);
	
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


//Funcion que escribe las matrices
void escribirMatrices(vector<Matrix*> matrices) {
	
	ofstream os("Matrices.txt");
	
	if(os.is_open()) {
		
		for(auto pm : matrices) {
			os << pm->format() << endl;
		}
		
		os.close();
		
	} else {
		cout << endl << "No se pudo abrir archivo de salida Matrices.txt" << endl;
	}
	
}

//Funcion que lee las matrices
void leerMatrices(vector<Matrix*>& matrices) {
	
	ifstream ifs("Matrices.txt");
	
	if(ifs.is_open()) {
		
		string line;
		
		while(!getline(ifs,line).eof()) {
			
			line = eliminarEspacios(line);
			
			matrices.push_back(new Matrix(line));
			
		}
		
		ifs.close();
	} else {
		
		cout << endl << "No se pudo abrir archivo de entrada Matrices.txt" << endl; 
	}
	
}

