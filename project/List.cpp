#include "List.h"
#include "Student.h"

List::List()
{
    //ctor
}

List::List(Node *ptr, Node *ptr1)
{
    h = ptr;
    t = ptr1;
}

void List::initialize()
{
    h=nullptr;
    t=nullptr;
}

void List::insertAtBeginning(class Student data)
{
    Node *tmp=new Node(data,nullptr,nullptr);

    if(!h)
    {
        h=tmp;
        t=tmp;
    }else
    {
        tmp->next=h;
        h->prev=tmp;
        h=tmp;
    }
}

void List::display()
{
    Node *aux=h;
    if(h)
    {
        while(aux)
        {
            cout<<"Name: "<<aux->data.name<<endl;
            cout<<"Age: "<<aux->data.age<<endl;
            cout<<"Code: "<<aux->data.code<<endl;
            cout<<"\n"<<endl;
            aux=aux->next;
        }
    }else
    {
        cout<<"List is empty"<<endl;
    }
}

void List::insertAtEnd(class Student data)
{
    Node *tmp=new Node(data,nullptr,nullptr);
    tmp->data=data;

    if(!h)
    {
        h=tmp;
        t=tmp;
    }else if(t)
    {
        t->next=tmp;
        tmp->prev=t;
        t=tmp;
    }
}

void List::insertAtPosition(class Student data, int pos)
{
    Node *tmp=new Node(data,nullptr,nullptr);
    tmp->data=data;
    Node *aux=h;
    pos=pos-1;
    int i=0;

    if(!h)
    {
        h=tmp;
        t=tmp;
    }else if(i!=pos)
    {
        do
        {
            aux=aux->next;
            i++;
        }while(i!=pos);
    }
    if(i==0)
    {
        tmp->next=h;
        h->prev=tmp;
        h=tmp;
    }else if(aux==nullptr)
    {
        t->next=tmp;
        tmp->prev=t;
        t=tmp;
    }else if(i==pos)
    {
        tmp->next=aux;
        tmp->prev=aux->prev;
        aux->prev->next=tmp;
        aux->prev=tmp;
    }
}

void List::Remove(int n)
{
    if(h)
    {
        Node *aux=h;

        while((aux!=nullptr)&&(aux->data.code!=n))
        {
            aux=aux->next;
        }if(aux==nullptr)
        {
            cout<<"Student not found..."<<endl;
        }else if(aux->prev==nullptr)
        {
            h=h->next;
            h->prev=nullptr;
            delete aux;
            cout<<"Student deleted..."<<endl;
        }else if(aux->next==nullptr)
        {
            t=t->prev;
            t->next=nullptr;
            delete aux;
            cout<<"Student deleted..."<<endl;
        }else
        {
            aux->prev->next=aux->next;
            aux->next->prev=aux->prev;
            delete aux;
            cout<<"Student deleted..."<<endl;
        }
    }
}

void List::removeAll()
{
    while(h)
    {
        Node *aux=h;
        h=aux->next;
        delete aux;
    }
}

void List::isEmpty()
{
    if(h)
    {
        cout<<"List has data"<<endl;
    }else
    {
        cout<<"List is empty"<<endl;
    }
}

int List::Size()
{
    Node *aux=h;
    int i=0;
    if(h)
    {
        while(aux)
        {
            aux=aux->next;
            i++;
        }
    }
    return i;
}

Node* List::Search(int id)
{
    Node *aux=h;

    while((aux!=nullptr)&&(aux->data.code!=id))
    {
        aux=aux->next;
    }
    return aux;
}

Node* List::first()
{
    if(h)
    {
        return h;
    }else
    {
        return nullptr;
    }
}

Node* List::last()
{
    if(h)
    {
        return t;
    }else
    {
        return nullptr;
    }
}

Node* List::next(int id)
{
    Node *aux=h;

    while(aux->data.code!=id)
    {
        aux=aux->next;
    }if((aux->data.code==id)&&(aux->next!=nullptr))
    {
        return aux;
    }else
    {
        return nullptr;
    }
}

Node* List::previous(int id)
{
    Node *aux=h;

    while(aux->data.code!=id)
    {
        aux=aux->next;
    }if((aux->data.code==id)&&(aux->prev!=nullptr))
    {
        return aux;
    }else
    {
        return nullptr;
    }
}
