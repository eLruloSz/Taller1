#include <iostream>
#include "MaterialBibliografico.h"
#include "libro.h"
#include "Revista.h"
#include "Usuario.h"

void menu();

int main(int argc, char const *argv[])
{
    MaterialBibliografico* biblioteca[100];
    Usuario* usuarios[100];
    int contbiblio = 0;
    int contusuarios = 0;
    bool ciclo = true;

    while(ciclo) {
        menu();
        int opcion;
        std::cin >> opcion;

        switch(opcion) {
            case 1:
                std::cout << "Tipo de MaterialBibliografico (1. Libro / 2. Revista): ";
                int opcion1;
                std::cin >> opcion1;
                if(opcion1 == 1) {
                    std::cout << "Se seleccionó Libro" << std::endl;
                   // biblioteca[contbiblio++]* = new libro("juan",0, "a", true," "," ");
                } else if(opcion1 == 2) {
                    std::cout << "Se seleccionó Revista" << std::endl;
                  
                } else {
                    std::cout << "Opción inválida" << std::endl;
                };
                break;

            case 2:
                std::cout << "Mostrar información de los materiales" << std::endl;
               
                break;

            case 3:
                std::cout << "Buscar material" << std::endl;
               
                break;

            case 4:
                std::cout << "Prestar o devolver material" << std::endl;
             
                break;

            case 5:
                std::cout << "Gestión de usuarios" << std::endl;
               
                break;
            case 6:
                std::cout<< "Hasta luego!";
                ciclo = false;
            
            default:
                std::cout << "Opción inválida" << std::endl;
                break;
        }
    }

    return 0;
};

void menu() {
    std::cout << "Bienvenidos" << std::endl;
    std::cout << "1. Agregar Material a la Biblioteca" << std::endl;
    std::cout << "2. Mostrar Informacion de los Materiales" << std::endl;
    std::cout << "3. Buscar Material" << std::endl;
    std::cout << "4. Prestar y Devolver Material" << std::endl;
    std::cout << "5. Gestion de Usuarios" << std::endl;
    std::cout << "6. SALIR" << std::endl;
    std::cout << "Ingrese una opcion: ";
};
