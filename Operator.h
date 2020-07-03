#ifndef OPERATOR_H
#define OPERATOR_H

#include "Object.h"

class Operator : public Object
{
	public:
		Operator();
		
		Operator(char);
		
		char getTipo();
		
		char operacion;
		
		~Operator();
	protected:
};

#endif
