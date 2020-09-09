#include <iostream>
#include "StudentNode.h"

int main()
{
    const char *name[3] = {"kim", "lee", "park"};
    StudentNode studentA(name[0], 001);
    StudentNode studentB(name[1], 002);
    StudentNode studentC(name[2], 003);

    // A -> B -> C
    studentA.setNext(&studentB);
    studentB.setNext(&studentC);

    // print all the student info using only first student
    using namespace std;

    cout << studentA.getName() << endl;
    cout << studentA.getNext()->getName() << endl;
    cout << studentA.getNext()->getNext()->getName() << endl;
    cout << endl;
    //Print the all the student info using While statement.
    StudentNode *temp = &studentA;
    while (true)
    {
        cout << temp->getName() << endl;
        if (temp->getNext() == NULL)
        {
            break;
        }
        else
        {
            temp = temp->getNext();
        }
    }
}