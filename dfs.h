#ifndef DFS_H_
#define DFS_H_

#include <iostream>
#include "vertice.h"
#include "grafo.h"
#include <vector>
#include <list>
#include <stack>

using namespace std;

class DFS
{
public:
    stack <Vertice*> borda;
    stack <Vertice*> explorados;
    Vertice* origem;
    Vertice* destino;
    Grafo* mapa;
    bool answer = false;
    int stepStatus = 0;


public:
    DFS(Vertice * origem, Vertice * destino, Grafo * mapa);

    bool start(Vertice * origem, Vertice * destino, Grafo * mapa);
    void status();   

};

DFS::DFS(Vertice * origem, Vertice * destino, Grafo * mapa)
{
    this->origem = origem;
    this->destino = destino;
    this->mapa = mapa;
    answer = start(this->origem, this->destino, this->mapa);
    if(answer)
    {
        cout << "SOLUCAO ENCONTRADA!!! - " + this->destino->getName() << endl;
        status();
    }
    else
    {
        cout << "ERRO!" << endl;
    }
}

bool DFS::start(Vertice * origem, Vertice * destino, Grafo * mapa)
{
    Vertice* node;
    list<Vertice*> children;
    borda.push(origem); // Coloca o nó de origem na borda.
    while(!explorados.empty()) // Garante que explorados sempre comece vazio.
    {
        explorados.pop();
    }
    while (!borda.empty()){ // se a borda estiver vazia termina.
        node = borda.top();
        borda.pop();
        explorados.push(node);
        children = mapa->findChildren(node); // Gera os filhos daquele nó.
        status();
        for (auto const&newChildNode : children)
        {
            stack <Vertice*> copyBorda = borda;
            while (!copyBorda.empty()) // checa se o filho está na borda.
            {
                if (copyBorda.top()->getId() == newChildNode->getId())
                {
                    break;
                }else
                {
                    copyBorda.pop();
                }
            }

            if(!copyBorda.empty()) // Se encontrou o nó filho na borda então volta para checar o próximo filho.
            {
                continue;
            }

            stack <Vertice*> copyExplorados = explorados;
            while (!copyExplorados.empty()) // checa se o filho está em explorados.
            {
                if (copyExplorados.top()->getId() == newChildNode->getId())
                {
                    break;
                }else
                {
                    copyExplorados.pop();
                }
            }

            if(!copyExplorados.empty()) // Se encontrou o nó filho em explorados então volta para checar o próximo filho.
            {
                continue;
            }
        
            if(newChildNode->getId() == this->destino->getId()) // Como o nó filho não foi encontrado nem na borda nem em explorado, checo se é o objetivo.
            {
                return true;
            }

            borda.push(newChildNode); // Se o nó filho não é o objetivo ele é colocado na borda;
            status();
        }
    }
    return false;
}

void DFS::status()
{
    this->stepStatus += 1;
    cout << stepStatus;
    cout << " - ";
    cout << "BORDA: {-";
    stack <Vertice*> copyBorda = borda;
    while (!copyBorda.empty())
    {
        cout << copyBorda.top()->getName() + "-";
        copyBorda.pop();
    }
    cout << "}" << endl;

    cout << stepStatus;
    cout << " - ";
    cout << "EXPLORADOS: {-";
    stack <Vertice*> copyExplorados = explorados;
    while (!copyExplorados.empty())
    {
        cout << copyExplorados.top()->getName() + "-";
        copyExplorados.pop();
    }
    cout << "}" << endl;
}

#endif