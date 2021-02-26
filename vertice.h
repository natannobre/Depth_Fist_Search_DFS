#ifndef VERTICE_H
#define VERTICE_H

#include <string>

using namespace std;

class Vertice
{
    string nome;
    int id;

    public:
    Vertice(string nome, int id);

    string getNome();   
    int getId();
};

#endif