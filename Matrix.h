#ifndef MATRIX_H
#define MATRIX_H
#include <string>

#include "Object.h"

using namespace std;

class Matrix : public Object
{
	public:
		Matrix();
		
		Matrix(int);
		Matrix(string);
		
		char identificador;
		int** matrix;
		int size;
		
		char virtual getTipo();
		
		//Funcion que sirve para poner la matriz en un formato facil de guardar
		string format();
		
		void display();
		
		Matrix operator+ (const Matrix&);
		Matrix operator- (const Matrix&);
		Matrix operator* (const Matrix&); 
		
		~Matrix();
	protected:
};

#endif
