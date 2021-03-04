#ifndef DFS_H_
#define DFS_H_

#include <iostream>
#include "vertice.h"
#include "grafo.h"
#include "no.h"
#include "aresta.h"
#include <vector>
#include <list>
#include <stack>

using namespace std;

class DFS
{
public:
    stack <No*> borda;
    stack <No*> explorados;
    Vertice* origem;
    Vertice* destino;
    Grafo* mapa;
    int custoSolucao;
    list <Vertice*> caminhoEncontrado;
    bool answer = false;
    int stepStatus = 0;


public:
    DFS(Vertice * origem, Vertice * destino, Grafo * mapa);

    bool start(Vertice * origem, Vertice * destino, Grafo * mapa);
    void status();
    void buscarCaminho(No *no);

};

DFS::DFS(Vertice * origem, Vertice * destino, Grafo * mapa)
{
    this->origem = origem;
    this->destino = destino;
    this->mapa = mapa;
    answer = start(this->origem, this->destino, this->mapa);
    if(answer)
    {
        cout << endl;
        cout << "SOLUCAO ENCONTRADA!!! - " + this->destino->getName() << endl;
        
        cout << endl << "Caminho Encontrado:" << endl << endl;
        for (auto const&vertice : this->caminhoEncontrado)
        {
            cout << vertice->getName() << " - ";
        }
        cout << endl;
        cout << endl << "Custo da Solução: ";
        cout << this->custoSolucao << endl;
        status();
    }
    else
    {
        cout << "ERRO!" << endl;
    }
}

bool DFS::start(Vertice * origem, Vertice * destino, Grafo * mapa)
{
    No* nOrigem = new No(origem, NULL);
    No* node;
    list<Vertice*> children;
    borda.push(nOrigem); // Coloca o nó de origem na borda.
    while(!explorados.empty()) // Garante que explorados sempre comece vazio.
    {
        explorados.pop();
    }
    while (!borda.empty()){ // se a borda estiver vazia termina.
        node = borda.top();
        borda.pop();
        explorados.push(node);
        children = mapa->findChildren(node->getCurrent()); // Gera os filhos daquele nó.
        status();
        for (auto const&newChildNode : children)
        {
            stack <No*> copyBorda = borda;
            while (!copyBorda.empty()) // checa se o filho está na borda.
            {
                if (copyBorda.top()->getCurrent()->getId() == newChildNode->getId())
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

            stack <No*> copyExplorados = explorados;
            while (!copyExplorados.empty()) // checa se o filho está em explorados.
            {
                if (copyExplorados.top()->getCurrent()->getId() == newChildNode->getId())
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
                buscarCaminho(new No(newChildNode, node));
                return true;
            }

            borda.push(new No(newChildNode, node)); // Se o nó filho não é o objetivo ele é colocado na borda;
            status();
        }
    }
    return false;
}

void DFS::status()
{
    this->stepStatus += 1;
    cout << endl;
    cout << stepStatus;
    cout << " - ";
    cout << "BORDA: {-";
    stack <No*> copyBorda = borda;
    while (!copyBorda.empty())
    {
        cout << copyBorda.top()->getCurrent()->getName() + "-";
        copyBorda.pop();
    }
    cout << "}" << endl;

    cout << stepStatus;
    cout << " - ";
    cout << "EXPLORADOS: {-";
    stack <No*> copyExplorados = explorados;
    while (!copyExplorados.empty())
    {
        cout << copyExplorados.top()->getCurrent()->getName() + "-";
        copyExplorados.pop();
    }
    cout << "}" << endl;
    cout << endl;
}

void DFS::buscarCaminho(No* no)
{
    int custoTotal = 0;
    No* node = no;
    Aresta *aresta;
    list<Vertice*> caminho;
    while(node != NULL)
    {
        caminho.push_front(node->getCurrent());
        if(node->getFather() != NULL){
            aresta = this->mapa->isThereAresta2(node->getCurrent(), node->getFather()->getCurrent());
            custoTotal += aresta->getWeight();
        }
        node = node->getFather();
    }
    
    this->caminhoEncontrado = caminho;
    this->custoSolucao = custoTotal;
}

#endif