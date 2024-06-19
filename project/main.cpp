#include <iostream>
#include "Student.h"
#include "List.h"
#include "Node.h"

using namespace std;

void pause();

int main()
{
    List *lis=new List();

    int opt;
    Student data;

    do
    {
        system("cls");
        cout<<"----------------DOUBLY LINKED LIST------------------"<<endl;
        cout<<"1.-Initialize"<<endl;
        cout<<"2.-Insert at beginning"<<endl;
        cout<<"3.-Insert at end"<<endl;
        cout<<"4.-Insert at position"<<endl;
        cout<<"5.-Remove"<<endl;
        cout<<"6.-Remove everything"<<endl;
        cout<<"7.-Search student"<<endl;
        cout<<"8.-Is empty?"<<endl;
        cout<<"9.-First"<<endl;
        cout<<"10.-Last"<<endl;
        cout<<"11.-Size"<<endl;
        cout<<"12.-Next"<<endl;
        cout<<"13.-Previous"<<endl;
        cout<<"14.-Display list"<<endl;
        cout<<"15.-Exit"<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<"\nPlease enter an option: "<<endl;
        cin>>opt;


        switch(opt)
        {
        case 1:
            system("cls");
            cout<<"-------INITIALIZE-------"<<endl;
            cout<<"List started"<<endl;
            lis->initialize();
            pause();
            break;

        case 2:
            system("cls");
            cout<<"-------INSERT AT BEGINNING-------"<<endl;
            cout<<"Insert name: "<<endl;
            cin>>data.name;
            cout<<"Insert age: "<<endl;
            cin>>data.age;
            cout<<"Insert code: "<<endl;
            cin>>data.code;
            lis->insertAtBeginning(Student(data));
            pause();
            break;

        case 3:
            system("cls");
            cout<<"-------INSERT AT END-------"<<endl;
            cout<<"Insert name: "<<endl;
            cin>>data.name;
            cout<<"Insert age: "<<endl;
            cin>>data.age;
            cout<<"Insert code: "<<endl;
            cin>>data.code;
            lis->insertAtEnd(Student(data));
            pause();
            break;

        case 4:
            system("cls");
            int pos;
            cout<<"-------INSERT AT END-------"<<endl;
            cout<<"Insert name: "<<endl;
            cin>>data.name;
            cout<<"Insert age: "<<endl;
            cin>>data.age;
            cout<<"Insert code: "<<endl;
            cin>>data.code;
            cout<<"Which position do you want to insert it?(Starting with 0) "<<endl;
            cin>>pos;
            lis->insertAtPosition(data,pos);
            pause();
            break;

        case 5:
            system("cls");
            int num1;
            cout<<"-------REMOVE-------"<<endl;
            cout<<"Enter the code of the student you want to remove: "<<endl;
            cin>>num1;
            lis->Remove(num1);
            pause();
            break;

        case 6:
            system("cls");
            int rmv;
            cout<<"-------REMOVE ALL-------"<<endl;
            cout<<"Are you sure you want to delete everything? "<<endl;
            cout<<"1.Yes "<<endl;
            cout<<"2.No"<<endl;
            cin>>rmv;
            if(rmv==1)
            {
                cout<<"Ereasing..."<<endl;
                lis->removeAll();
            }else
            {
                cout<<"Returning..."<<endl;
            }
            pause();
            break;

        case 7:
            system("cls");
            cout<<"-------SEARCH STUDENT-------"<<endl;
            Node *stud;
            int code;
            cout<<"Please enter the code of the student you want to search: "<<endl;
            cin>>code;
            stud=(lis->Search(code));
            if(stud == nullptr)
            {
                cout<<"Not founded"<<endl;
            }
            else if(stud->data.code == code)
            {
                cout<<"\nThe student you are looking for is: "<<endl;
                cout<<stud->data.name<<endl;
                cout<<stud->data.age<<endl;
                cout<<stud->data.code<<endl;
            }
            pause();
            break;

        case 8:
            system("cls");
            cout<<"-------IS EMPTY?-------"<<endl;
            lis->isEmpty();
            pause();
            break;

        case 9:
            system("cls");
            Node *firstStud;
            cout<<"-------FIRTS STUDENT-------"<<endl;
            firstStud=(lis->first());
            cout<<firstStud->data.name<<endl;
            cout<<firstStud->data.age<<endl;
            pause();
            break;

        case 10:
            system("cls");
            Node *lastStud;
            cout<<"-------LAST STUDENT-------"<<endl;
            lastStud=(lis->last());
            cout<<lastStud->data.name<<endl;
            cout<<lastStud->data.age<<endl;
            pause();
            break;

        case 11:
            system("cls");
            int i;
            cout<<"-------SIZE-------"<<endl;
            i=(lis->Size());
            cout<<"The total size of the list is: "<<i<<endl;
            pause();
            break;

        case 12:
            system("cls");
            int code2;
            Node *nextOne;
            cout << "-------NEXT-------" << endl;
            cout << "Please enter the code of the student you want to know who is next to: ";
            cin >> code2;

            nextOne = lis->next(code2);

            if (nextOne != nullptr) {
                cout << "Next student:" << endl;
                cout << "Name: " << nextOne->data.name << endl;
                cout << "Age: " << nextOne->data.age << endl;
                cout << "Code: " << nextOne->data.code << endl;
            } else {
                cout << "Student with code " << code << " not found or is the last in the list." << endl;
            }

            pause();
            break;

        case 13:
            system("cls");
            int code3;
            Node *prevStud;
            cout << "-------PREVIOUS-------" << endl;
            cout << "Please enter the code of the student you want to know who is previous to: ";
            cin >> code3;

            prevStud = lis->previous(code3);

            if (prevStud != nullptr) {
                cout << "Previous student:" << endl;
                cout << "Name: " << prevStud->data.name << endl;
                cout << "Age: " << prevStud->data.age << endl;
                cout << "Code: " << prevStud->data.code << endl;
            } else {
                cout << "Student with code " << code3 << " not found or is the first in the list." << endl;
            }

            pause();
            break;

        case 14:
            system("cls");
            cout<<"-------DISPLAY EVERYTHING-------"<<endl;
            lis->display();
            pause();
            break;

        case 15:
            system("cls");
            cout<<"Quitting..."<<endl;
            break;

        default:
            system("cls");
            cout<<"Not a valid option"<<endl;
            pause();
            break;
        }

    }while(opt!=15);

    return 0;
}

void pause()
{
    cout<<"Press any key to continue..."<<endl;
    getwchar();
    getwchar();
}
