#include "Usuario.h"
#include <string>
#include <iostream>

Usuario::~Usuario(){};

Usuario::Usuario(std::string nombre,std::string id) : numPrestados(0){
    this->nombre = nombre;
    this->id = id;

    for(int i = 0; i < 5 ; i++){
        materialesPrestados[i] = nullptr;
    }
};

void Usuario::prestarMaterial(MaterialBibliografico* material){
    if(numPrestados < 5 && !material -> estaPrestado()){
        materialesPrestados[numPrestados++] = material;
        material -> setPrestado(true);
        std::cout << "Ayuda";
    }else{
        std::cout << "No se puede prestar el material";
    }
};

void Usuario::devolverMaterial(MaterialBibliografico* material){
    for(int i = 0; i < numPrestados; i++){
        if(materialesPrestados[i] == material){
            materialesPrestados[i] -> setPrestado(false);
            std::cout <<"Material devuelto con éxito";
            materialesPrestados[i] = nullptr;

            for(int j = i; j < numPrestados - 1; ++j){
                materialesPrestados[j] = materialesPrestados[j+1];
            }
            materialesPrestados[--numPrestados] = nullptr;
            
        }else{
            std::cout << "Material no encontrado";
        }
    }
};

void Usuario::mostrarMaterialesPrestados() const{
    std::cout << "Materiales prestados por: " << nombre;
    for(int i = 0; i < numPrestados; i++){
        if(materialesPrestados[i] != nullptr){
            materialesPrestados[i] -> mostrarInformacion();
        }
    }
};