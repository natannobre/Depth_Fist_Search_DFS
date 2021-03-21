#include <iostream>
#include <string>
#include "include/vertice.h"
#include "include/aresta.h"
#include "include/grafo.h"
#include "include/dfs.h"
#include "include/guloso.h"
#include <list>

using namespace std;

// argv[1] = <algoritmo>
// argv[2] = <origem>
// argv[3] = <destino>

int main( int argc,      // Number of strings in array argv
          char *argv[])   // Array of command-line argument strings
{
    string algoritmo = argv[1];
    cout << algoritmo << endl;
    string sOrigem = argv[2];
    cout << sOrigem << endl;
    string sDestino = argv[3];
    cout << sDestino << endl;
    Vertice* vOrigem;
    Vertice* vDestino;

    Vertice *Oradea = new Vertice("Oradea", 0, 380);
    Vertice *Zerind = new Vertice("Zerind", 1, 374);
    Vertice *Arad = new Vertice("Arad", 2, 366);
    Vertice *Sibiu = new Vertice("Sibiu", 3, 253);
    Vertice *Timisoara = new Vertice("Timisoara", 4, 329);
    Vertice *Lugoj = new Vertice("Lugoj", 5, 244);
    Vertice *Mehadia = new Vertice("Mehadia", 6, 241);
    Vertice *Drobeta = new Vertice("Drobeta", 7, 242);
    Vertice *Craiova = new Vertice("Craiova", 8, 160);
    Vertice *RimnicuVilcea = new Vertice("RimnicuVilcea", 9, 193);
    Vertice *Pitesti = new Vertice("Pitesti", 10, 100);
    Vertice *Fagaras = new Vertice("Fagaras", 11, 176);
    Vertice *Bucharest = new Vertice("Bucharest", 12, 0);
    Vertice *Giurgiu = new Vertice("Giurgiu", 13, 77);
    Vertice *Urziceni = new Vertice("Urziceni", 14, 80);
    Vertice *Hirsova = new Vertice("Hirsova", 15, 151);
    Vertice *Eforie = new Vertice("Eforie", 16, 161);
    Vertice *Vaslui = new Vertice("Vaslui", 17, 199);
    Vertice *Iasi = new Vertice("Iasi", 18, 226);
    Vertice *Neamt = new Vertice("Neamt", 19, 234);
    
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

    vector<Vertice*> listVertices = mapaDaRomenia->ListVertices;
    
    for (auto const&vertice : listVertices)
    {
        if (vertice->getName() == sOrigem)
        {
            vOrigem = vertice;
        }
        if (vertice->getName() == sDestino)
        {
            vDestino = vertice;
        }
        
    }


    if (algoritmo == "dfs")
    {
        cout << endl;
        cout << "Algoritmo de Busca em Profundidade:" << endl;
        DFS *dfs = new DFS(vOrigem, vDestino, mapaDaRomenia);
    } else if (algoritmo == "guloso")
    {
        cout << endl;
        cout << "Algoritmo de Busca Gulosa de Melhor Escolha:" << endl;
        Guloso *guloso = new Guloso(vOrigem, vDestino, mapaDaRomenia);
    }
    
}

