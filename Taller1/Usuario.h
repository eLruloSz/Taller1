#ifndef USUARIO_H
#define USUARIO_H

#include "MaterialBibliografico.h"
#include <string>

class Usuario{
    protected:
        std::string nombre,id;
        MaterialBibliografico* materialesPrestados[5];
        int numPrestados;
    public:
        Usuario(std::string nombre,std::string id);

        //---------------------------------------------------------------
        void prestarMaterial(MaterialBibliografico* material);
        void devolverMaterial(MaterialBibliografico* material);
        void mostrarMaterialesPrestados() const;
};
#endif // USUARIO_H