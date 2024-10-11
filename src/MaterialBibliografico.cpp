// MaterialBibliografico.cpp
#include "../include/MaterialBibliografico.h"

MaterialBibliografico::MaterialBibliografico(std::string nombre, std::string isbn, std::string autor, bool prestado) {
    this->nombre = nombre;
    this->isbn = isbn;
    this->autor = autor;
    this->prestado = prestado;
}

std::string MaterialBibliografico::getNombre() {
    return this->nombre;
}

std::string MaterialBibliografico::getIsbn() {
    return this->isbn;
}

std::string MaterialBibliografico::getAutor() {
    return this->autor;
}

bool MaterialBibliografico::getPrestado() {
    return this->prestado;
}

void MaterialBibliografico::cambiarEstado(bool estado) {
    this->prestado=estado;
}

std::string MaterialBibliografico::mostrarInformacion(){
return "Nombre: " + this->nombre + " Isbn: " + this->isbn + " Autor: " + this->autor + " Prestado: " + (this->prestado ? "Sí" : "No");
}

MaterialBibliografico::~MaterialBibliografico() {

}
