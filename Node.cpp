#include "Node.h"

Node::Node()
{
}

Node::Node(Object* data) {
	
	this->next_node = nullptr;
	this->data = data;
}

Object* Node::getData() {
	return this->data;
}

Node* Node::getNext() {
	return next_node;
}

void Node::setNext(Node* next_node) {
	this->next_node = next_node;
}

Node::~Node()
{
}
