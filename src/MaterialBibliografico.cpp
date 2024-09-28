#include "../include/MaterialBibliografico.h"

MaterialBibliografico :: MaterialBibliografico(std::string nombre, int isbn, std::string autor, bool prestado){
    this -> nombre = nombre;
    this -> isbn = isbn;
    this -> autor = autor;
    this -> prestado = prestado;
};

std::string MaterialBibliografico :: getNombre()const {
    return nombre;
};
int MaterialBibliografico :: getIsbn() const{
    return isbn;
};
std::string MaterialBibliografico :: getAutor() const{
    return autor;
};
bool MaterialBibliografico :: estaPrestado() const{
    return prestado;
};
void MaterialBibliografico::setPrestado(bool prestado)
{
    this -> prestado = prestado;
};
