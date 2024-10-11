#include "../include/Usuario.h"
#include <algorithm>
#include <iostream>
#include <ostream>

Usuario::Usuario(std::string nombre, std::string id) {
    this->nombre=nombre;
    this->id=id;
}

std::string Usuario::getNombre() {
    return this->nombre;
}

std::string Usuario::getID() {
    return this -> id;
}

void Usuario::prestarMaterial(MaterialBibliografico* material) {
    if(material->getPrestado()==false){
        if(contador<5) {
        material->cambiarEstado(true);
        materialesPrestrado[contador++] = material;
        }
        else {
            std::cout<<"Invalido\n";
        }
    }
    else{
        std::cout<<"El material ya se encuentra prestado";
    }
}

void Usuario::devolverMaterial(std::string materialDevolver) {

    for (int i = 0; i < 5; i++) {
        if (materialesPrestrado[i] != nullptr && (materialesPrestrado[i]->getAutor() == materialDevolver ||materialesPrestrado[i]->getNombre() == materialDevolver)) {
            materialesPrestrado[i]->cambiarEstado(false);
            materialesPrestrado[i] = nullptr;
            contador--;
            break;
        }
    }
}


std::string Usuario::mostrarMaterialesPrestados() {
    std::string a = "";
    for (int i = 0; i < 5; i++) {
        if (materialesPrestrado[i] != nullptr) {
            a += materialesPrestrado[i]->mostrarInformacion() + "\r";
        }
    }
    return a;
}

Usuario::~Usuario() {
    std::cout << "Usuario eliminado"<<std::endl;
}

std::string Usuario::informacion(){
    return "Nombre: "+this-nombre+"\n Id: "+this->id+"\n";
}