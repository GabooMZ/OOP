#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <string>
#include <vector>

class Video {
private:
    std::string tipoVideo,nombreVideo,genero;
    int anioLanzamiento, totalCalificacion, duracion;
    double promedio;
    std::vector<float> calificaciones;
public:

    Video();
    Video(const std::string& tipoVideo, const std::string& nombreVideo, const std::string& genero, int anioLanzamiento, int duracion);
    
    virtual void calificar(float);
    friend std::ostream& operator<<(std::ostream& os, const Video& video);

    /*void calcularPromedio() ;*/
    void setPromedio();

    // Método para mostrar la información del video
    /*void muestraDatos() const;*/
    std::string getTipoVideo() const;
    std::string getNombreVideo() const;
    std::string getGenero() const;
    int getAnioLanzamiento() const;
    int getDuracion() const;
    int getTotalCalificacion() const;
    double getPromedio() const;

};

#endif
