#include "Video.hpp"
#include <iostream>
#include <numeric>

Video::Video() {
    tipoVideo = "";
    nombreVideo = "";
    genero = "";
    anioLanzamiento = 0;
    duracion = 0;
}

Video::Video(const std::string& tipoVideo, const std::string& nombreVideo, const std::string& genero, int anioLanzamiento, int duracion){
    this->tipoVideo = tipoVideo;
    this->nombreVideo = nombreVideo;
    this->genero = genero;
    this->anioLanzamiento = anioLanzamiento;
    this->duracion = duracion;
    totalCalificacion = 0;
}

void Video::calificar(float calificacion) {
    if (calificacion >= 0) {
        calificaciones.push_back(calificacion);
        totalCalificacion++;
    }
}

std::string Video::getNombreVideo() const {
        return nombreVideo;
    }

std::string Video::getTipoVideo() const {
        return tipoVideo;
    }
    
std::string Video::getGenero() const {
        return genero;
    }

int Video::getAnioLanzamiento() const {
        return anioLanzamiento;
    }

int Video::getDuracion() const {
        return duracion;
    }

int Video::getTotalCalificacion() const {
        return totalCalificacion;
    }

double Video::getPromedio() const {
        return promedio;
    }

void Video::setPromedio() {
    promedio = getTotalCalificacion() > 0 ? std::accumulate(calificaciones.begin(), calificaciones.end(), 0.0) / getTotalCalificacion() : 0;
}

/*void Video::calcularPromedio() {
    double ans;
    ans = getTotalCalificacion() > 0 ? std::accumulate(calificaciones.begin(), calificaciones.end(), 0.0) / getTotalCalificacion() : 0;
    setPromedio(ans);
}*/

std::ostream& operator<<(std::ostream& os, const Video& video) {
    os << "Titulo: " << video.getNombreVideo() << std::endl;
    os << "Genero: " << video.getGenero() << std::endl;
    os << "Duracion: " << video.getDuracion() << " minutos" << std::endl;
    os << "Calificacion promedio: " << video.getPromedio() << std::endl;
    return os;
}

