#ifndef CAPITULO_H
#define CAPITULO_H
#include <string>
#include "Video.h"
using namespace std;

class Capitulo:public Video{
    private:
        int episodio;
        string serie;
    public:
        Capitulo();
        Capitulo(string, string, int, string, string, int);
        ~Capitulo();

        string imprimir();

};
#endif