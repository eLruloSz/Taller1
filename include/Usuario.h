#ifndef USUARIO_H
#define USUARIO_H
#include <string>

#include "MaterialBibliografico.h"


class Usuario {
protected:
    std::string nombre,id;
    int contador=0;
    MaterialBibliografico* materialesPrestrado[5];
public:
    Usuario(std::string nombre,std::string id);
    std::string getNombre();
    std::string getID();
    void prestarMaterial(MaterialBibliografico* material);
    void devolverMaterial(std::string materialDevolver);
    std::string mostrarMaterialesPrestados();
    ~Usuario();

};



#endif //USUARIO_H
