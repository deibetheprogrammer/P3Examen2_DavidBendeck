#include "Operator.h"

Operator::Operator()
{
}

Operator::Operator(char operacion) {
	this->operacion = operacion;
}

char Operator::getTipo() {
	return 'O';
}

Operator::~Operator()
{
}
