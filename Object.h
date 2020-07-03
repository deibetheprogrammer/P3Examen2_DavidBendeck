#ifndef OBJECT_H
#define OBJECT_H

class Object
{
	public:
		Object();
		
		virtual char getTipo() = 0;
		
		~Object();
	protected:
};

#endif
