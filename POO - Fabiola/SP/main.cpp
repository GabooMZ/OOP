#include "Video.h"
#include "Capitulo.h"
#include "Pelicula.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cctype>
#include <limits>



using namespace std;


int main(){

    //Vector donde voy a almacenar todos los videos como punteros
    vector<Video*> videos;
    //Abrir el archivo de txto que contiene la info, debe estar en la misma carpeta que los demas archivos
    ifstream archivo("videos.txt");
    //Abrir el archivo y cargar los datos en el vector

    //https://es.stackoverflow.com/questions/55617/c%C3%B3mo-leer-una-l%C3%ADnea-en-especifico-de-un-archivo-txt
    //https://barcelonageeks.com/getline-string-en-c/
    
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string tipo;
            getline(ss, tipo, ',');

            if (tipo == "c") {
                string id, titulo, duracion_str, genero, serie;
                int duracion, numero;
                getline(ss, id, ',');
                getline(ss, titulo, ',');
                getline(ss, duracion_str, ',');
                getline(ss, genero, ',');
                getline(ss, serie, ',');
                string numero_str;
                getline(ss, numero_str);

                duracion = stoi(duracion_str);
                numero = stoi(numero_str);

                videos.push_back(new Capitulo(id, titulo, duracion, genero, serie, numero));
            }
            else if (tipo == "p") {
                string id, titulo, duracion_str, genero;
                int duracion;
                getline(ss, id, ',');
                getline(ss, titulo, ',');
                getline(ss, duracion_str, ',');
                getline(ss, genero);

                duracion = stoi(duracion_str);

                videos.push_back(new Pelicula(id, titulo, duracion, genero));
            }
        }
        archivo.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    //Menu
    int opcion = 0;
    while (opcion != 9) {
        cout << "===== MENU =====" << endl;
        cout << "1. Mostrar todo el catálogo con calificaciones" << endl;
        cout << "2. Calificar un video" << endl;
        cout << "3. Mostrar películas o capítulos con una calificación mínima determinada" << endl;
        cout << "4. Mostrar películas o capítulos de un cierto género" << endl;
        cout << "9. Salir" << endl;

        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Mostrar todo el catálogo con calificaciones
                cout << "Id, Nombre, Duracion, Genero, (Serie, Episodio), Calificacion"<<endl;
                for(Video* video : videos){
                    cout<< *video << endl;
                    //cout << video->imprimir() << endl;
                }
                break;
            case 2:
            {
                string videoID = "";
                bool videoEncontrado = false;
                cout << "Ingrese el ID del video a calificar: ";
                cin >> videoID;

                // Buscar el video con el ID ingresado
                //https://cplusplus.com/forum/beginner/217812/
                for(Video* video : videos) {
                    if (video->getId() == videoID) {
                        videoEncontrado = true;

                        int calificacion;
                        cout << "Ingrese la calificación (1-5 numero entero): ";
                        cin >> calificacion;

                        // Validar la calificación ingresada
                        while (!cin || calificacion < 1 || calificacion > 5) {
                            cout << "Calificación inválida. Ingrese un valor entero entre 1 y 5: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cin >> calificacion;
                        }
                        // Establecer la calificación del video
                        video->calificar(calificacion);

                        cout << "Calificación agregada correctamente." << endl;
                        break;
                    }
                }

                    if (!videoEncontrado) {
                        cout << "No se encontró un video con el ID ingresado." << endl;
                    }
                break;
            }
            case 3:
                {
                //Submenu
                int subopcion = 0;
                cout << "===== Submenú =====" << endl;
                cout << "1. Ver películas" << endl;
                cout << "2. Ver capítulos" << endl;
                cout << "3. Ver películas y capítulos" << endl;
                cout << "Seleccione una opción: ";
                cin >> subopcion;
                while (!cin || subopcion < 1 || subopcion > 3) {
                    cout << "Opcion inválida. Ingrese un valor entre 1 y 3: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> subopcion;
                }


                double calificacion=0.0;
                cout << "Ingrese la calificación minima (1-5): ";
                cin >> calificacion;
                // Validar la calificación ingresada
                while (!cin || calificacion < 1 || calificacion > 5) {
                    cout << "Calificación inválida. Ingrese un valor entre 1 y 5: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> calificacion;
                }

                cout << "Id, Nombre, Calificacion"<<endl;
                // Mostrar películas o capítulos con una calificación mínima determinada
                for(Video* video : videos) { 
                    if (subopcion == 1 && dynamic_cast<Pelicula*>(video)) {
                        if (video->getCalificacion() >= calificacion) {
                            cout << video->imprimirCalif() << endl;
                        }
                    }
                    else if (subopcion == 2 && dynamic_cast<Capitulo*>(video)) {
                        if (video->getCalificacion() >= calificacion) {
                            cout << video->imprimirCalif() << endl;
                        }
                    }
                    else if (subopcion == 3) {
                        if (video->getCalificacion() >= calificacion) {
                            cout << video->imprimirCalif() << endl;
                        }
                    }
                }
                break;
            }
            case 4:
                {
                //Submenu
                int subopcion = 0;
                cout << "===== Submenú =====" << endl;
                cout << "1. Ver películas" << endl;
                cout << "2. Ver capítulos" << endl;
                cout << "3. Ver películas y capítulos" << endl;
                cout << "Seleccione una opción: ";
                cin >> subopcion;
                while (!cin || subopcion < 1 || subopcion > 3) {
                    cout << "Opcion inválida. Ingrese un valor entre 1 y 3: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> subopcion;
                }


                string genero;
                cout << "Ingrese el género (drama, accion, misterio): ";
                cin >> genero;
                while (genero != "drama" && genero != "accion" && genero != "misterio")
                {
                    cout << "Opcion inválida. Ingrese un genero valido (drama, accion, misterio): ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> genero;
                }
                
                cout << "Id, Nombre,  Genero, Calificacion"<<endl;
                // Mostrar películas o capítulos con una calificación mínima determinada
                for(Video* video : videos) { 
                    if (subopcion == 1 && dynamic_cast<Pelicula*>(video)) {
                        if (video->getGenero() == genero) {
                            cout << video->imprimirGenero() << endl;
                        }
                    }
                    else if (subopcion == 2 && dynamic_cast<Capitulo*>(video)) {
                        if (video->getGenero() == genero) {
                            cout << video->imprimirGenero() << endl;
                        }
                    }
                    else if (subopcion == 3) {
                        if (video->getGenero() == genero) {
                            cout << video->imprimirGenero() << endl;
                        }
                    }
                }
                break;
            }
            case 9:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }

        cout << endl;
    }
    
    return 0;
}