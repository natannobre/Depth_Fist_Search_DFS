#ifndef ARESTA_H_
#define ARESTA_H_

#include "vertice.h"
using namespace std;

class Aresta
{
public:
    Vertice *v1;
    Vertice *v2; 
    int weight;

public:
    Aresta(Vertice *v1, Vertice *v2, int weight);

    Vertice* getV1();   
    Vertice* getV2();
    int getWeight();
};

Aresta::Aresta(Vertice *v1, Vertice *v2, int weight)
{
    this->v1 = v1;
    this->v2 = v2;
    this->weight = weight;
}

Vertice* Aresta::getV1()
{
    return this->v1;
}

Vertice* Aresta::getV2()
{
    return this->v2;
}

int Aresta::getWeight()
{
    return this->weight;
}

#endif