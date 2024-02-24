#include "Video.h"
#include <string>
using namespace std;

Video::Video():Video("","",0,""){}

Video::Video(string id, string nombre, int duracion, string genero){
    this->id = id;
    this->nombre = nombre;
    this->duracion = duracion;
    this->genero = genero;

    sumacalis = 0;
    numcalis = 0;
    calificacion = 0;
}

Video::~Video(){}

void Video::calificar(int cali){
    this->sumacalis += cali;
    this->numcalis++;
    this->calcCali();
}

void Video::calcCali(){
    if (this->numcalis !=0){
        this->calificacion = (double)this->sumacalis/this->numcalis;
    }
}

string Video::getId(){
    return this->id;
}

double Video::getCalificacion(){
    return this->calificacion;
}

string Video::getGenero(){
    return this->genero;
}

string Video::calSC(){
    if (this->sumacalis != 0)
    {
        return to_string(this->calificacion);
    }else{
        return "SC";
    }
}

string Video::imprimirCalif(){
    return   this->id + ", " + this->nombre + ", " + calSC();
}

string Video::imprimirGenero(){
    return   this->id + ", " + this->nombre + ", " + this->genero + ", " + calSC();
}
