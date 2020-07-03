#include "Matrix.h"
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

Matrix::Matrix()
{
	this->size = 0;
	this->matrix = nullptr;
}

Matrix::Matrix(int size) {
	
	this->size = size;
	
	this->matrix = new int*[size];
	
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}
	
}

Matrix::Matrix(string cont) {
	
	this->identificador = cont[0];
	
	this->size = sqrt(std::count(cont.begin(),cont.end(),',') + 1);
	
	this->matrix = new int*[size];
	
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}
	
	//LLENAR LA MATRIZ
	
	int x = 3;
	
	for (int i = 0; i < this->size; i++) {
		for(int j = 0; j < this->size; j++) {
			matrix[i][j] = (int)(cont[x] - '0');
			x += 2;
		}
	}
	
}

char Matrix::getTipo() {
	return 'M';
}

string Matrix::format() {
	string res = "";
	
	
}

void Matrix::display() {
	
	cout << this->identificador << " = " << endl;
	
	for(int i = 0; i < this->size; i++) {
		cout << "  | ";
		for(int j = 0; j < this->size; j++) {
			cout << this->matrix[i][j] << " ";
		}
		cout << "|" << endl;
	}
	
	cout << endl;
}

Matrix Matrix::operator+(const Matrix& rhs) {
	
	Matrix *result = new Matrix(this->size);
	
	for(int i = 0; i < this->size; i++) {
		for(int j = 0; j < this->size; j++) {
			result->matrix[i][j] = this->matrix[i][j] + rhs.matrix[i][j];
		}
	}
	
	return *result;
}

Matrix Matrix::operator-(const Matrix& rhs) {
	
	
	Matrix *result = new Matrix(this->size);
	
	for(int i = 0; i < this->size; i++) {
		for(int j = 0; j < this->size; j++) {
			result->matrix[i][j] = this->matrix[i][j] - rhs.matrix[i][j];
		}
	}
	
	return *result;
}

Matrix Matrix::operator*(const Matrix& rhs) {
	
	Matrix *result = new Matrix(this->size);
	
	for(int i = 0; i < this->size; i++) {
		for(int j = 0; j < this->size; j++) {
			result->matrix[i][j] = 0;
			for(int k = 0; k < this->size; k++) {
				result->matrix[i][j] += this->matrix[i][k] * rhs.matrix[k][j];
			}
		}
	}
	
	return *result;
	
}

Matrix::~Matrix()
{
}
