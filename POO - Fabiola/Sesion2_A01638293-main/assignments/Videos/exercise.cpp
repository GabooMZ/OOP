#include "Serie.hpp"
#include "Pelicula.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

void mostrarVideos(vector<Video*> videos){
    for(Video* video : videos){
            cout<< *video << endl;
    }
}

void mostrarVideosPorGenero(vector<Video*> videos,string genero){
    for(Video* video : videos){
        if( video->getGenero() == genero){
            if(Serie* s = dynamic_cast<Serie*>(video)){
                cout<< *s << endl;
            }
            else if (Pelicula* p = dynamic_cast<Pelicula*>(video)){
                cout<< *p << endl;
            }
        }
    }
}

void mostrarVideosPorMaxCapitulos(vector<Video*> videos,int maxCap){
    for(Video* video : videos){
        if(Serie* s = dynamic_cast<Serie*>(video)){
            if (s->getCapitulo() <= maxCap)
            {
                cout<< *s << endl;
            }
        }
    }
}

void mostrarVideosPorAnio(vector<Video*> videos,int anio){
    for(Video* video : videos){
        if( video->getAnioLanzamiento() == anio){
            if(Serie* s = dynamic_cast<Serie*>(video)){
                cout<< *s << endl;
            }
            else if (Pelicula* p = dynamic_cast<Pelicula*>(video)){
                cout<< *p << endl;
            }
        }
    }
}

void mostrarVideosCalMin(vector<Video*> videos,int minCal){
    for(Video* video : videos){
        if( video->getPromedio() >= minCal){
            if(Serie* s = dynamic_cast<Serie*>(video)){
                cout<< *s << endl;
            }
            else if (Pelicula* p = dynamic_cast<Pelicula*>(video)){
                cout<< *p << endl;
            }
        }
    }
}

void calificarVideoPorTitulo(vector<Video*> videos, string nombre,int Calificacion){
    for(Video* video : videos){
        if( video->getNombreVideo() == nombre){
            video->calificar(Calificacion);
            video->setPromedio();
            std::cout << *video << std::endl;
        }
    }
}

int validarCalificacion() {
    int calificacionMin;
    while (true) {
        try {
            std::cout << "Ingrese un número entre 0 y 100: ";
            std::cin >> calificacionMin;

            if (calificacionMin < 0 || calificacionMin > 100) {
            throw std::invalid_argument("El número ingresado debe estar entre 0 y 100");
        }
        else if (calificacionMin >= 0 || calificacionMin <= 100)
        {
            return calificacionMin;;
        }
        
        
    } catch (const std::invalid_argument& ia) {
        std::cerr << ia.what() << std::endl;
    }
    }
}

int main()
{
    vector<Video*> videos;
    ifstream archivo;
    archivo.open("datos.txt");
    
    string tipoVideo;

    if (archivo.is_open()) {
        while (archivo >> tipoVideo) {

            if (tipoVideo == "s") {
                string nombreVideo, genero;
                int duracion ,numTemporada , numCapitulo , anioLanzamiento;

                archivo >> nombreVideo >> genero >> anioLanzamiento >> duracion >> numTemporada >> numCapitulo ;

                videos.push_back(new Serie(tipoVideo, nombreVideo, genero, anioLanzamiento, duracion, numTemporada,numCapitulo));
            }
            else if (tipoVideo == "p") {
                string nombreVideo, genero,director,rating;
                int duracion, anioLanzamiento ;

                archivo >> nombreVideo >> genero >> anioLanzamiento >> duracion >> director >> rating ;

                videos.push_back(new Pelicula(tipoVideo, nombreVideo, genero, anioLanzamiento, duracion, director, rating));
            }   
        }
    }
    else {
    cout << "No se pudo abrir el archivo." << endl;
    }
    
    int opcion;
    do {
        system("clear");
        std::cout << "1. Mostrar videos por género\n";
        std::cout << "2. Mostrar series por cantidad de capítulos\n";
        std::cout << "3. Mostrar películas por calificación\n";
        std::cout << "4. Calificar un video\n";
        std::cout << "5. Mostrar videos y series por año\n";
        std::cout << "6. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            system("clear");
            std::string genero;
            std::cout << "Ingrese el género: ";
            std::cin >> genero;
            mostrarVideosPorGenero(videos,genero);
            break;
        }
        case 2: {
            system("clear");
            int capMax;
            std::cout << "Ingrese la cantidad máxima de capítulos: ";
            std::cin >> capMax;
            mostrarVideosPorMaxCapitulos(videos,capMax);
            break;
        }
        case 3: {
            system("clear");
            int calificacionMin = validarCalificacion();
          
            mostrarVideosCalMin(videos,calificacionMin);
            break;
        }
        case 4: {
            system("clear");
            std::string titulo;
            int calificacion;
            std::cout << "Ingrese el título del video: ";
            std::cin >> titulo;
            std::cout << "Ingrese la calificación: ";
            std::cin >> calificacion;
            calificarVideoPorTitulo(videos,titulo,calificacion);
            break;
        }
        case 5: {
            system("clear");
            int anio;
            std::cout << "Ingrese el año: ";
            std::cin >> anio;
            mostrarVideosPorAnio(videos,anio);
            break;
        }
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
        }
        cout << "Enter para continuar...";
        cin.ignore();
        cin.get();
    } while (opcion != 6);
    return 0;
}