
#include "Revista.h"
#include <string>
#include <iostream>

Revista::Revista(std::string nombre, int isbn, std::string autor, bool prestado, int numEdicion, std::string mesPublicacion) : MaterialBibliografico(nombre,isbn,autor,prestado){
    this -> numEdicion = numEdicion;
    this -> mesPublicacion = mesPublicacion;
};
int Revista::getNumEdicion(){
     return numEdicion;
};

std::string Revista::getMesPublicacion(){
    return mesPublicacion;
};

void Revista::mostrarInformacion() const{
std::cout <<"Revista: " << nombre << "ISBN: " << isbn << "Autor: " << autor << "Número de edición: " << numEdicion << " Mes de publicación: " << mesPublicacion << (prestado ? "Si" : "No");

};