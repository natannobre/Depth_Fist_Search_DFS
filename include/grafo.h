#ifndef GRAFO_H_
#define GRAFO_H_

#include "vertice.h"
#include "aresta.h"
#include <vector>
#include <list>

using namespace std;

class Grafo
{
public:
    vector <Vertice*> ListVertices;
    vector <Aresta*> ListArestas;  

public:
    Grafo();

    void addVertice(Vertice * vertice);   
    void addAresta(Aresta * aresta);
    bool isThereAresta(Vertice * v1, Vertice * v2);
    Aresta* isThereAresta2(Vertice * v1, Vertice * v2);
    list<Vertice*> findChildren(Vertice * v1);
};

Grafo::Grafo(){}

void Grafo::addVertice(Vertice * vertice)
{
    this->ListVertices.push_back(vertice);
}

void Grafo::addAresta(Aresta * aresta)
{
    this->ListArestas.push_back(aresta);
}

bool Grafo::isThereAresta(Vertice * v1, Vertice * v2)
{
    for (auto const&it : this->ListArestas)
    {
        if((it->getV1()->getId() == v1->getId()) || (it->getV1()->getId() == v2->getId()))
        {
            if((it->getV2()->getId() == v1->getId()) || (it->getV2()->getId() == v2->getId()))
            {
                return true;
            }
        }
    }

    return false;

}

Aresta* Grafo::isThereAresta2(Vertice * v1, Vertice * v2)
{
    for (auto const&it : this->ListArestas)
    {
        if((it->getV1()->getId() == v1->getId()) || (it->getV1()->getId() == v2->getId()))
        {
            if((it->getV2()->getId() == v1->getId()) || (it->getV2()->getId() == v2->getId()))
            {
                return it;
            }
        }
    }

    return NULL;

}

list<Vertice*> Grafo::findChildren(Vertice * v1)
{
    list<Vertice*> verticesAdjacentes;
    for (auto const&it : this->ListVertices)
    {
        if(isThereAresta(v1, it))
        {
            verticesAdjacentes.push_back(it);
        }
    }
    return verticesAdjacentes;
}


#endif