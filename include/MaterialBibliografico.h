// MaterialBibliografico.h
#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H

#include <string>

class MaterialBibliografico {
protected:
    std::string nombre;
    std::string isbn;
    std::string autor;
    bool prestado;

public:
    MaterialBibliografico(std::string nombre, std::string isbn, std::string autor, bool prestado);

    std::string getNombre();
    std::string getIsbn();
    std::string getAutor();
    bool getPrestado();
    void cambiarEstado(bool estado);
    virtual std::string mostrarInformacion();
    virtual ~MaterialBibliografico();
};

#endif // MATERIALBIBLIOGRAFICO_H
