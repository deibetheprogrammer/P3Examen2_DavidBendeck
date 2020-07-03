
#pragma once

#include "Node.h"

class Stack{
    private:
        Node* head;
    public:
        Stack(){
            head = nullptr;
        };
        Stack(Node* _head){
            head = _head;
        };
        Node* pop(){
            Node* temp_head = head;
            head = head->getNext();
            return temp_head;
        };
        Node* top(){
            return head;
        };
        void push(Node* _node){
            _node->setNext(head);
            head = _node;
        };
        void delete_stack(Node* _node){
            if (_node->getNext() != nullptr){
                delete_stack(_node->getNext());
            }            
            delete _node;
        }
        ~Stack(){
            delete_stack(head);
        }
};

