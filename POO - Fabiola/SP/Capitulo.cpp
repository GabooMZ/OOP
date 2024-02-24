#include "Capitulo.h"
#include <string>
using namespace std;

Capitulo::Capitulo():Video(){
    episodio = 0;
    serie = "";
}

Capitulo::Capitulo(string id, string nombre, int duracion, string genero, string serie, int episodio):Video(id, nombre, duracion, genero){
    this->episodio = episodio;
    this->serie = serie;
}

Capitulo::~Capitulo(){}

string Capitulo::imprimir(){
    return  this->id + ", " + this->nombre + ", " + to_string(this->duracion) + ", " + this->genero + ", " + this->serie + ", " + to_string(this->episodio) + ", " + calSC();
}
