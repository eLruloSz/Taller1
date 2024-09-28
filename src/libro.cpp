#include "../include/MaterialBibliografico.h"
#include "../include/libro.h"
#include <string>
#include <iostream>

libro::libro(std:: string nombre, int isbn, std::string autor, bool prestado, std::string fechaPublicacion , std::string resumen) : MaterialBibliografico(nombre, isbn, autor, prestado){
  this -> fechaPublicacion = fechaPublicacion;
  this-> resumen = resumen;  
};
libro::~libro(){};
void libro::mostrarInformacion() const {
    std::cout << "Nombre: " << nombre << 
    "\n ISBN: "<<isbn<<"\n Autor:"<<autor<<"\n Prestado: "<<prestado<<"\n Fecha de Publicacion: "<<fechaPublicacion<<"\n Resumen: "<<resumen;
};
std::string libro::getFechaPublicacion(){
    return this->fechaPublicacion;
};
std::string libro::getResumen(){
    return this->resumen;
};
