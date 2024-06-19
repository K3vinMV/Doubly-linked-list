#ifndef NODE_H
#define NODE_H
#include "Student.h"

class Node
{
    public:
        Node *next;
        Node *prev;

        Student data;
        Node();
        Node(class Student, Node*, Node*);

};

#endif // NODE_H
