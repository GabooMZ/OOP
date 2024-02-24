#ifndef PELICULA_HPP
#define PELICULA_HPP
#include "Video.hpp"

#include <string>
#include <vector>

class Pelicula : public Video {
    
private:
    std::string tipoVideo,nombreVideo,genero,director,rating;
    int anioLanzamiento, totalCalificacion, duracion;
    std::vector<float> calificaciones;
    double promedio;

public:

    Pelicula();
    Pelicula(const std::string& tipoVideo, const std::string& nombreVideo, const std::string& genero, 
    int anioLanzamiento, int duracion, const std::string& director,const std::string& rating);

    std::string getDirector() const;
    std::string getRating() const;

    friend std::ostream& operator<<(std::ostream& os, const Pelicula& pelicula);

};

#endif
