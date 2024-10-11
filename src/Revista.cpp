
#include "../include/Revista.h"

Revista::Revista(std::string nombre, std::string isbn, std::string autor, bool prestado,
                 std::string numeroedicion, std::string mespublicacion)
    : MaterialBibliografico(nombre, isbn, autor, prestado) {
    this->numeroedicion=numeroedicion;
    this->mespublicacion=mespublicacion;
}

std::string Revista::getNumeroEdicion()const {
    return this->numeroedicion;
}

std::string Revista::getMesPublicacion()const {
    return this->mespublicacion;
}

std::string Revista::mostrarInformacion() {
    return "Nombre: " + this->nombre + "\n Isbn: " + this->isbn + "\n Autor: " + this->autor + "\n Prestado: " + (this->prestado ? "Sí" : "No") +
           "\n Numero de Edicion: " + this->getNumeroEdicion() + "\n Mes de Publicacion: " + this->getMesPublicacion();
}

Revista::~Revista() {
    // Destructor body if needed
}
