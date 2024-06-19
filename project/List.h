#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "Student.h"
#include "Node.h"

using namespace std;

class List
{
    public:
        Node *h; //Header
        Node *t; //Tail

        List();
        List(Node*, Node*);
        void initialize();
        void insertAtBeginning(class Student);
        void display();
        void insertAtEnd(class Student);
        void insertAtPosition(class Student, int);
        void Remove(int);
        void removeAll();
        void isEmpty();
        int Size();
        Node* Search(int);
        Node* first();
        Node* last();
        Node* next(int);
        Node* previous(int);

};

#endif // LIST_H
