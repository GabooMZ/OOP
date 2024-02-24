#ifndef VIDEO_H
#define VIDEO_H
#include <string>
#include <iostream>
using namespace std;

class Video{
    protected:
        string id;
        string nombre;
        int duracion;
        string genero;

        int sumacalis;
        int numcalis;
        double calificacion;

    public:
        Video();
        Video(string, string, int, string);
        ~Video();

        void calificar(int);
        void calcCali();
        virtual string imprimir()=0;
        string imprimirCalif();
        string imprimirGenero();
        string calSC();

        string getId();
        double getCalificacion();
        string getGenero();
    
    friend ostream& operator<< (ostream& os, Video& vid){
        os << vid.imprimir() ;
        return os;
        }
    
};
#endif