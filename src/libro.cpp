#include "../include/Libro.h"

Libro::Libro(std::string nombre, std::string isbn, std::string autor, bool prestado, std::string fechadePublicacion, std::string resumen)
    : MaterialBibliografico(nombre, isbn, autor, prestado) {
    this->fechadePublicacion = fechadePublicacion;
    this->resumen = resumen;
}

std::string Libro::getFechadePublicacion() const {  // Marcar como const
    return this->fechadePublicacion;
}

std::string Libro::getResumen() const {  // Marcar como const
    return this->resumen;
}

std::string Libro::mostrarInformacion() {
    return "Nombre: " + this->nombre +
           "\nIsbn: " + this->isbn +
           "\nAutor: " + this->autor +
           "\nPrestado: " + (this->prestado ? "Sí" : "No") +
           "\nFecha de Publicacion: " + this->fechadePublicacion +
           "\nResumen: " + this->resumen;
}
