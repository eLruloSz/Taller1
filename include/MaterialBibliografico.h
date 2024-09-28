#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H

#include <string>


class MaterialBibliografico
{
protected:
    std::string nombre;
    int isbn;
    std::string autor;
    bool prestado;

public:
   
    MaterialBibliografico(std::string nombre, int isbn, std::string autor, bool prestado);    
    std::string getNombre() const;
    int getIsbn() const;
    std::string getAutor() const ;
    bool estaPrestado() const;
    void setPrestado(bool prestado);
    virtual void mostrarInformacion() const;
};

#endif // MATERIALBIBLIOGRAFICO_H