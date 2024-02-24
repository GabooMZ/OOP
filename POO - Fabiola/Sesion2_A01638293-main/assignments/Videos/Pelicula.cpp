#include "Pelicula.hpp"
#include <iostream>
#include <numeric>

Pelicula::Pelicula() {
    tipoVideo = "";
    nombreVideo = "";
    genero = "";
    anioLanzamiento = 0;
    duracion = 0;
    director = "";
    rating = "";
}

Pelicula::Pelicula(const std::string& tipoVideo, const std::string& nombreVideo, const std::string& genero, int anioLanzamiento, int duracion, const std::string& director,const std::string& rating)
        : Video(tipoVideo, nombreVideo, genero, anioLanzamiento, duracion) {
    this->director = director;
    this->rating = rating;
    totalCalificacion=0;
}

std::string Pelicula::getDirector() const {
        return director;
    }

std::string Pelicula::getRating() const {
        return rating;
    }

std::ostream& operator<<(std::ostream& os, const Pelicula& pelicula) {
    os << "Titulo: " << pelicula.getNombreVideo() << std::endl;
    os << "Genero: " << pelicula.getGenero() << std::endl;
    os << "Duracion: " << pelicula.getDuracion() << " minutos" << std::endl;
    os << "Director: " << pelicula.getDirector() << std::endl;
    os << "Rating: " << pelicula.getRating() << std::endl;
    os << "Calificacion promedio: " << pelicula.getPromedio() << std::endl;
    return os;
}
