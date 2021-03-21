#ifndef GULOSO_H_
#define GULOSO_H_

#include <iostream>
#include "vertice.h"
#include "grafo.h"
#include "no.h"
#include "aresta.h"
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Guloso
{
public:
    list <No*> borda;
    list <No*> explorados;
    Vertice* origem;
    Vertice* destino;
    Grafo* mapa;
    int custoSolucao;
    list <Vertice*> caminhoEncontrado;
    bool answer = false;
    int stepStatus = 0;


public:
    Guloso(Vertice * origem, Vertice * destino, Grafo * mapa);

    bool start(Vertice * origem, Vertice * destino, Grafo * mapa);
    void status();
    void buscarCaminho(No *no);
    list<No*> ordenar(list<No*> borda);

};

Guloso::Guloso(Vertice * origem, Vertice * destino, Grafo * mapa)
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
        cout << endl << "Custo da Solucao: ";
        cout << this->custoSolucao << endl;
        status();
    }
    else
    {
        cout << "ERRO!" << endl;
    }
}

bool Guloso::start(Vertice * origem, Vertice * destino, Grafo * mapa)
{
    No* nOrigem = new No(origem, NULL);
    No* node;
    list<Vertice*> children;
    borda.push_back(nOrigem); // Coloca o nó de origem na borda.
    explorados.clear(); // Garante que explorados sempre comece vazio.

    while (!borda.empty()){ // se a borda estiver vazia termina.
        borda = ordenar(borda);
        status();
        node = borda.front();
        borda.pop_front();
        if (node->getCurrent()->getId() == destino->getId())
        {
            buscarCaminho(node);
            return true;
        }
        explorados.push_back(node);
        children = mapa->findChildren(node->getCurrent()); // Gera os filhos daquele nó.
        status();
        for (auto const&newChildNode : children)
        {
            list <No*> copyExplorados = explorados;
            while (!copyExplorados.empty()) // checa se o filho está em explorados.
            {
                if (copyExplorados.front()->getCurrent()->getId() == newChildNode->getId())
                {
                    break;
                }else
                {
                    copyExplorados.pop_front();
                }
            }

            if(!copyExplorados.empty()) // Se encontrou o nó filho em explorados então volta para checar o próximo filho.
            {
                continue;
            }
            
            list <No*> copyBorda = borda;
            while (!copyBorda.empty()) // checa se o filho está na borda.
            {
                if (copyBorda.front()->getCurrent()->getId() == newChildNode->getId())
                {
                    break;
                }else
                {
                    copyBorda.pop_front();
                }
            }

            if(!copyBorda.empty()) // Se encontrou o nó filho na borda então volta para checar o próximo filho.
            {
                if (newChildNode->getHeuristica() < copyBorda.front()->getCurrent()->getHeuristica()) //Se o nó na  borda possui um valor maior do que o nó atual
                {

                    while (true)
                    {
                        if(node->getCurrent()->getId() == borda.front()->getCurrent()->getId())
                        {
                            borda.pop_front();
                            borda.push_back(node);
                        }else
                        {
                            borda.push_back(borda.front());
                            borda.pop_front();
                        }
                    }
                }
                continue;
            }
        
            // if(newChildNode->getId() == this->destino->getId()) // Como o nó filho não foi encontrado nem na borda nem em explorado, checo se é o objetivo.
            // {
            //     buscarCaminho(new No(newChildNode, node));
            //     return true;
            // }

            borda.push_back(new No(newChildNode, node)); // Se o nó filho não é o objetivo ele é colocado na borda;
            status();
        }
    }
    return false;
}

void Guloso::status()
{
    this->stepStatus += 1;
    cout << endl;
    cout << stepStatus;
    cout << " - ";
    cout << "BORDA: {-";
    list <No*> copyBorda = borda;
    while (!copyBorda.empty())
    {
        cout << copyBorda.front()->getCurrent()->getName() + "-";
        copyBorda.pop_front();
    }
    cout << "}" << endl;

    cout << stepStatus;
    cout << " - ";
    cout << "EXPLORADOS: {-";
    list <No*> copyExplorados = explorados;
    while (!copyExplorados.empty())
    {
        cout << copyExplorados.front()->getCurrent()->getName() + "-";
        copyExplorados.pop_front();
    }
    cout << "}" << endl;
    cout << endl;
}

void Guloso::buscarCaminho(No* no)
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

list<No*> Guloso::ordenar(list<No*> borda)
{
    list<No*> copyBorda;
    list<No*> novaBorda;
    No *menor;
    int iMenor = 0;
    int it = 0;
    while(!borda.empty())
    {
        menor = borda.front();
        copyBorda = borda;
        it = 0;
        iMenor = 0;
        while(!copyBorda.empty())
        {
            if(copyBorda.front()->getCurrent()->getHeuristica() < menor->getCurrent()->getHeuristica())
            {
                menor = copyBorda.front();
                iMenor = it;
            }
            it++;
            copyBorda.pop_front();
        }
        for( int i = 0; i < iMenor; i++ )
        {
            borda.push_back(borda.front());
            borda.pop_front();
        }
        borda.pop_front();
        novaBorda.push_back(menor);
    }
    return novaBorda;
}

#endif