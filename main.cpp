#include <iostream>
#include <string>
#include "vertice.h"
#include "aresta.h"
#include "grafo.h"

using namespace std;

int main()
{
    Vertice *Arad = new Vertice("Arad", 0);
    Vertice *Sibiu = new Vertice("Sibiu", 1);
    Vertice *Fagaras = new Vertice("Fagaras", 2);
    Aresta *Arad_Sibiu = new Aresta(Arad, Sibiu, 140);
    Aresta *Sibiu_Arad = new Aresta(Sibiu, Arad, 680);
    // Vertice *teste = Arad_Sibiu->getV1();

    Grafo * grafo = new Grafo();
    grafo->addVertice(Arad);
    grafo->addVertice(Sibiu);
    grafo->addAresta(Arad_Sibiu);
    grafo->addAresta(Sibiu_Arad);

    cout << grafo->isThereAresta(Sibiu, Arad) << endl;

    // cout << teste->getName() << endl;
}