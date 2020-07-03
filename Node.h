#ifndef NODE_H
#define NODE_H
#include "Object.h"

class Node
{
	public:
		Node();
		
		Node(Object*);
		
		Object* getData();
		
		void setNext(Node*);
		Node* getNext();
		
		~Node();
	protected:
		
		Node* next_node;
		Object* data;

};

#endif
