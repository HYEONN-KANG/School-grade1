#pragma once
class StudentNode
{
public:
    StudentNode(const char *, int); // two type initializer
    // set() get() 생략
    StudentNode *getNext();
    void setNext(StudentNode *next);
    const char *getName();

private:
    const char *name;
    int id;
    StudentNode *next;
};
