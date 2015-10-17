#ifndef POLYGEN_H
#define POLYGEN_H
#include "windows.h"
#include <QDebug>

class Node
{
public:
    Node(){itself = NULL; next = NULL;}
    ~Node(){delete itself;}

public:
    POINT* itself;
    Node* next;
};

class Polygen
{
public:
    Polygen(){begin = NULL; next = NULL; dir = true;}
    ~Polygen()
    {
        if(begin != NULL){
            Node* p = begin->next;
            while(p != begin){
                begin->next = p->next;
                delete p;
                p = begin->next;
            }
            delete begin;
        }
    }

public:
    Node* begin;        // the beginning node of the polygen
    Polygen* next;  //
    bool dir;
};

#endif // POLYGEN_H

