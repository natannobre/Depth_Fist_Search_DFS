#include <iostream>
#include <string>
#include "vertice.h"
#include "aresta.h"
#include "grafo.h"
#include "dfs.h"
#include <list>

using namespace std;


int main()
{
    Vertice *Oradea = new Vertice("Oradea", 0);
    Vertice *Zerind = new Vertice("Zerind", 1);
    Vertice *Arad = new Vertice("Arad", 2);
    Vertice *Sibiu = new Vertice("Sibiu", 3);
    Vertice *Timisoara = new Vertice("Timisoara", 4);
    Vertice *Lugoj = new Vertice("Lugoj", 5);
    Vertice *Mehadia = new Vertice("Mehadia", 6);
    Vertice *Drobeta = new Vertice("Drobeta", 7);
    Vertice *Craiova = new Vertice("Craiova", 8);
    Vertice *RimnicuVilcea = new Vertice("RimnicuVilcea", 9);
    Vertice *Pitesti = new Vertice("Pitesti", 10);
    Vertice *Fagaras = new Vertice("Fagaras", 11);
    Vertice *Bucharest = new Vertice("Bucharest", 12);
    Vertice *Giurgiu = new Vertice("Giurgiu", 13);
    Vertice *Urziceni = new Vertice("Urziceni", 14);
    Vertice *Hirsova = new Vertice("Hirsova", 15);
    Vertice *Eforie = new Vertice("Eforie", 16);
    Vertice *Vaslui = new Vertice("Vaslui", 17);
    Vertice *Iasi = new Vertice("Iasi", 18);
    Vertice *Neamt = new Vertice("Neamt", 19);
    
    Aresta *Oradea_Sibiu = new Aresta(Oradea, Sibiu, 151);
    Aresta *Oradea_Zerind = new Aresta(Oradea, Zerind, 71);
    Aresta *Zerind_Arad = new Aresta(Zerind, Arad, 75);
    Aresta *Arad_Sibiu = new Aresta(Arad, Sibiu, 140);
    Aresta *Arad_Timisoara = new Aresta(Arad, Timisoara, 118);
    Aresta *Timisoara_Lugoj = new Aresta(Timisoara, Lugoj, 111);
    Aresta *Lugoj_Mehadia = new Aresta(Lugoj, Mehadia, 70);
    Aresta *Mehadia_Drobeta = new Aresta(Mehadia, Drobeta, 75);
    Aresta *Drobeta_Craiova = new Aresta(Drobeta, Craiova, 120);
    Aresta *Craiova_RimnicuVilcea = new Aresta(Craiova, RimnicuVilcea, 146);
    Aresta *Craiova_Pitesti = new Aresta(Craiova, Pitesti, 138);
    Aresta *RimnicuVilcea_Sibiu = new Aresta(RimnicuVilcea, Sibiu, 80);
    Aresta *Sibiu_Fagaras = new Aresta(Sibiu, Fagaras, 99);
    Aresta *RimnicuVilcea_Pitesti = new Aresta(RimnicuVilcea, Pitesti, 97);
    Aresta *Fagaras_Bucharest = new Aresta(Fagaras, Bucharest, 211);
    Aresta *Pitesti_Bucharest = new Aresta(Pitesti, Bucharest, 101);
    Aresta *Bucharest_Giurgiu = new Aresta(Bucharest, Giurgiu, 90);
    Aresta *Bucharest_Urziceni = new Aresta(Bucharest, Urziceni, 85);
    Aresta *Urziceni_Hirsova = new Aresta(Urziceni, Hirsova, 98);
    Aresta *Hirsova_Eforie = new Aresta(Hirsova, Eforie, 86);
    Aresta *Urziceni_Vaslui = new Aresta(Urziceni, Vaslui, 142);
    Aresta *Vaslui_Iasi = new Aresta(Vaslui, Iasi, 92);
    Aresta *Iasi_Neamt = new Aresta(Iasi, Neamt, 87);
    
    Grafo * mapaDaRomenia = new Grafo();
    mapaDaRomenia->addVertice(Oradea); 
    mapaDaRomenia->addVertice(Zerind); 
    mapaDaRomenia->addVertice(Arad);
    mapaDaRomenia->addVertice(Sibiu);
    mapaDaRomenia->addVertice(Timisoara);
    mapaDaRomenia->addVertice(Lugoj);
    mapaDaRomenia->addVertice(Mehadia);
    mapaDaRomenia->addVertice(Drobeta);
    mapaDaRomenia->addVertice(Craiova);
    mapaDaRomenia->addVertice(RimnicuVilcea);
    mapaDaRomenia->addVertice(Pitesti);
    mapaDaRomenia->addVertice(Fagaras);
    mapaDaRomenia->addVertice(Bucharest);
    mapaDaRomenia->addVertice(Giurgiu);
    mapaDaRomenia->addVertice(Urziceni);
    mapaDaRomenia->addVertice(Hirsova);
    mapaDaRomenia->addVertice(Eforie); 
    mapaDaRomenia->addVertice(Vaslui); 
    mapaDaRomenia->addVertice(Iasi);
    mapaDaRomenia->addVertice(Neamt);

    mapaDaRomenia->addAresta(Oradea_Sibiu);
    mapaDaRomenia->addAresta(Oradea_Zerind);
    mapaDaRomenia->addAresta(Zerind_Arad);
    mapaDaRomenia->addAresta(Arad_Sibiu);
    mapaDaRomenia->addAresta(Arad_Timisoara); 
    mapaDaRomenia->addAresta(Timisoara_Lugoj);
    mapaDaRomenia->addAresta(Lugoj_Mehadia);
    mapaDaRomenia->addAresta(Mehadia_Drobeta);
    mapaDaRomenia->addAresta(Drobeta_Craiova);
    mapaDaRomenia->addAresta(Craiova_RimnicuVilcea);
    mapaDaRomenia->addAresta(Craiova_Pitesti);
    mapaDaRomenia->addAresta(RimnicuVilcea_Sibiu);
    mapaDaRomenia->addAresta(Sibiu_Fagaras);
    mapaDaRomenia->addAresta(RimnicuVilcea_Pitesti);
    mapaDaRomenia->addAresta(Fagaras_Bucharest);
    mapaDaRomenia->addAresta(Pitesti_Bucharest);
    mapaDaRomenia->addAresta(Bucharest_Giurgiu);
    mapaDaRomenia->addAresta(Bucharest_Urziceni);
    mapaDaRomenia->addAresta(Urziceni_Hirsova);
    mapaDaRomenia->addAresta(Hirsova_Eforie); 
    mapaDaRomenia->addAresta(Urziceni_Vaslui);
    mapaDaRomenia->addAresta(Vaslui_Iasi); 
    mapaDaRomenia->addAresta(Iasi_Neamt);

    // list<Vertice*> adjacentes = mapaDaRomenia->findChildren(Pitesti);
    
    // for (auto const&it : adjacentes)
    // {
    //     cout << it->getName() << endl;    
    // }

    DFS *dfs = new DFS(Timisoara, Sibiu, mapaDaRomenia); // Caminho não otimo
    
}

