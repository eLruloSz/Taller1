#ifndef LIBRO_H
#define LIBRO_H
#include "MaterialBibliografico.h"


class Libro : public MaterialBibliografico {
public:

    Libro(std::string nombre, std::string isbn, std::string autor, bool prestado, std::string fechadePublicacion,
          std::string resumen);

    std::string getFechadePublicacion() const;
    std::string getResumen()const;
    std::string mostrarInformacion() override;
protected:
    std::string fechadePublicacion;
    std::string resumen;
};




#endif //LIBRO_H