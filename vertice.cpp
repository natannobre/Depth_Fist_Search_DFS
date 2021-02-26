#include "vertice.h"

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
