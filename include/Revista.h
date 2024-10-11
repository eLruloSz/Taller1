#ifndef REVISTA_H
#define REVISTA_H
#include "MaterialBibliografico.h"


class Revista: public MaterialBibliografico{
protected:
    std::string numeroedicion,mespublicacion;
public:
    Revista(std::string nombre, std::string isbn, std::string autor, bool prestado, std::string numeroedicion,  std::string mespublicacion);
    std::string getNumeroEdicion()const;
    std::string getMesPublicacion()const;
    std::string mostrarInformacion() override;

    ~Revista();

};



#endif //REVISTA_H
