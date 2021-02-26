#ifndef VERTICE_H_
#define VERTICE_H_

#include <string>
using namespace std;

class Vertice
{
public:
    string nome;
    int id;

    public:
    Vertice(string nome, int id);

    string getNome();   
    int getId();
};

Vertice::Vertice(string nome, int id)
{
    this->nome = nome;
    this->id = id;
}

string Vertice::getNome()
{
    return this->nome;
}

int Vertice::getId()
{
    return this->id;
}

#endif