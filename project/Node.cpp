#include "Node.h"
#include "Student.h"

Node::Node()
{
    Student data;
    next = nullptr;
    prev = nullptr;
    //ctor
}

Node::Node(class Student data, Node *next, Node *prev)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}
