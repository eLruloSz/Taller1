#ifndef REVISTA_H
#define REVISTA_H
#include "MaterialBibliografico.h"
#include <string>

class Revista : public MaterialBibliografico
{
private:
    int numEdicion;
    std::string mesPublicacion;

public:
    Revista(std::string nombre, int isbn, std::string autor, bool prestado, int numEdicion, std::string mesPublicacion);
    void mostrarInformacion() const override;
    int getNumEdicion();
    std::string getMesPublicacion();
    
};
#endif // REVISTA_H