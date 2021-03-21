#ifndef VERTICE_H_
#define VERTICE_H_

#include <string>
using namespace std;

class Vertice
{
public:
    string name;
    int id;
    int heuristica; //Distância em linha reta para Bucharest

    public:
    Vertice(string name, int id, int heuristica);

    string getName();   
    int getId();
    int getHeuristica();
};

Vertice::Vertice(string name, int id, int heuristica)
{
    this->name = name;
    this->id = id;
    this->heuristica = heuristica;
}

string Vertice::getName()
{
    return this->name;
}

int Vertice::getId()
{
    return this->id;
}

int Vertice::getHeuristica()
{
    return this->heuristica;
}

#endif