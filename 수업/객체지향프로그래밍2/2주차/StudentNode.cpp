#include "StudentNode.h"
#include <iostream>

StudentNode::StudentNode(const char *name, int id)
{
    this->name = name;
    this->id = id;
    this->next = NULL;
}

const char *StudentNode::getName()
{
    return this->name;
}

void StudentNode::setNext(StudentNode *next)
{
    this->next = next;
}

StudentNode *StudentNode::getNext()
{
    return next;
}
