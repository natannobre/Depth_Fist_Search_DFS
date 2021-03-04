#ifndef VERTICE_H_
#define VERTICE_H_

#include <string>
using namespace std;

class Vertice
{
public:
    string name;
    int id;

    public:
    Vertice(string name, int id);

    string getName();   
    int getId();
};

Vertice::Vertice(string name, int id)
{
    this->name = name;
    this->id = id;
}

string Vertice::getName()
{
    return this->name;
}

int Vertice::getId()
{
    return this->id;
}

#endif