#ifndef NO_H_
#define NO_H_
using namespace std;

class No
{
    public:
        Vertice *vCurrent;
        No *nFather;
    public:
        No(Vertice *vCurrent, No *nFather);
        Vertice* getCurrent();
        No* getFather();
};

No::No(Vertice *vCurrent, No *nFather)
{
    this->vCurrent = vCurrent;
    this->nFather = nFather;
}

Vertice* No::getCurrent(){
    return this->vCurrent;
}

No* No::getFather(){
    return this->nFather;
}

#endif