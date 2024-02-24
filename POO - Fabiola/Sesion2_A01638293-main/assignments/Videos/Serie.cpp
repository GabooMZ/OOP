#include "Serie.hpp"
#include <iostream>
#include <numeric>

Serie::Serie() {
    tipoVideo = "";
    nombreVideo = "";
    genero = "";
    anioLanzamiento = 0;
    duracion = 0;
    temporada = 0;
    capitulo = 0;
}

Serie::Serie(const std::string& tipoVideo, const std::string& nombreVideo, const std::string& genero, int anioLanzamiento, int duracion, int temporada,int capitulo)
        : Video(tipoVideo, nombreVideo, genero, anioLanzamiento, duracion) {
    this->temporada = temporada;
    this->capitulo = capitulo;
    totalCalificacion = 0;
}


int Serie::getTemporada() const {
        return temporada;
    }

int Serie::getCapitulo() const {
        return capitulo;
    }


std::ostream& operator<<(std::ostream& os, const Serie& serie) {
    os << "Temporada " << serie.getTemporada() << " Capitulo " << serie.getCapitulo() << std::endl;
    os << "Titulo: " << serie.getNombreVideo() << std::endl;
    os << "Genero: " << serie.getGenero() << std::endl;
    os << "Duracion: " << serie.getDuracion() << " minutos" << std::endl;
    
    os << "Calificacion promedio: " << serie.getPromedio() << std::endl;
    return os;
}
