#ifndef SERIES_HPP
#define SERIE_HPP
#include "Video.hpp"

#include <string>
#include <vector>

class Serie : public Video {
    
private:
    std::string tipoVideo,nombreVideo,genero;
    int anioLanzamiento, totalCalificacion, duracion, temporada, capitulo;
    std::vector<float> calificaciones;
    double promedio;

public:

    Serie();
    Serie(const std::string& tipoVideo, const std::string& nombreVideo, const std::string& genero, 
    int anioLanzamiento, int duracion, int temporada, int capitulo);

    int getTemporada() const;
    int getCapitulo() const;

    friend std::ostream& operator<<(std::ostream& os, const Serie& serie);

};

#endif
