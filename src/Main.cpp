#include <iostream>
#include "../include/MaterialBibliografico.h"
#include "../include/libro.h"
#include "../include/Revista.h"
#include "../include/Usuario.h"

void menu();
void buscarMaterial(MaterialBibliografico *biblioteca[100]);
void prestarODevolver();
void agregarMaterial();
Usuario* buscarUsuario(std::string id);
MaterialBibliografico* buscarMaterial(std::string nombre);

MaterialBibliografico* biblioteca[100];
Usuario* usuarios[100];
int contbiblio = 0;

int main(int argc, char const *argv[])
{
    bool ciclo = true;

    while(ciclo) {
        menu();
        int opcion=0;
        std::cin >> opcion;



        switch(opcion) {
            case 1:
                agregarMaterial();
                break;

            case 2:
                std::cout << "Mostrar información de los materiales" << std::endl;
                for (MaterialBibliografico* biblio : biblioteca) {
                    if(biblio != nullptr){
                        biblio -> mostrarInformacion();
                    }                    
                }

                break;

            case 3:
                std::cout << "Buscar material" << std::endl;
                buscarMaterial(biblioteca);
                break;

            case 4:
                prestarODevolver();
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
}
void prestarODevolver()
{
    std::cout << "Prestar o devolver material (p/d): ";
    std::string opcion1;
    std::cin >> opcion1;
    std::cout << "Ingrese el id del usuario: ";
    std::string id;
    std::cin >> id;
    Usuario* usuario = buscarUsuario(id);
    std::cout << "Ingrese el nombre del Material a buscar: ";
    std::string nombre;
    std::cin >> nombre;
    MaterialBibliografico* material = buscarMaterial(nombre);
    if (opcion1 == "p")
    {
        usuario -> prestarMaterial(material);
    }else{
        usuario -> devolverMaterial(material);
    }
}
void buscarMaterial(MaterialBibliografico *biblioteca[100])
{
    std::cout << "Ingrese nombre o autor del material: " << std::endl;
    std::string articulo;
    std::cin >> articulo;

    for (int i = 0; i < contbiblio-1; i++)
    {
        if (biblioteca[i] != nullptr)
        {
            if (biblioteca[i]->getNombre() == articulo || biblioteca[i]->getAutor() == articulo)
            {
                std::cout << "El material es el siguiente: " << std::endl;
                std::cout << "Nombre: " << biblioteca[i]->getNombre() << "ISBN: " << biblioteca[i]->getIsbn() << "Autor: " << biblioteca[i]->getAutor() << std::endl;
            }
        }
        else
        {
            std::cout << "Artículo no encontrado";
        }
    }
}
MaterialBibliografico* buscarMaterial(std::string nombre){
    for (int i = 0; i < 100; i++) {
        if (biblioteca[i] != nullptr && biblioteca[i] -> getNombre() == nombre) {           
            return biblioteca[i];
        }
    }
    return nullptr;
}
Usuario* buscarUsuario(std::string id) {
    for (int i = 0; i < 100; i++) {
        if (usuarios[i] != nullptr && usuarios[i] -> getId() == id) {           
            return usuarios[i];
        }
    }
    return nullptr;
}
void agregarMaterial()
{
    std::cout << "Tipo de MaterialBibliografico (1. Libro / 2. Revista): " << std::endl;
    int opcion1=0;
    
    std::cout << "Ingrese nombre: "<<std::endl;
    std::string nombre;
    std::cin >> nombre;
    std::cout << "Ingrese ISBN: "<<std::endl;
    int isbn;
    std::cin >> isbn;
    std::cout << "Ingrese autor: "<<std::endl;
    std::string autor;
    std::cin >> autor;

    std::cin >> opcion1;
    if (opcion1 == 1)
    {
        std::cout << "Ingrese fecha de publicación: " << std::endl;
        std::string fechaPublicacion;
        std::cin >> fechaPublicacion;
        std::cout << "Ingrese resunen" << std::endl;
        std::string resumen;
        std::cin >> resumen;
        biblioteca[contbiblio++] = new libro(nombre,isbn, autor, false,fechaPublicacion,resumen);
    }
    else if (opcion1 == 2)
    {
        std::cout<<"Ingrese numero de edicion: "<<std::endl;
        int numero;
        std::cin>>numero;
        std::cout<<"Ingrese mes de Publicacion: "<<std::endl;
        std::string mes;
        std::getline(std::cin, mes);
        biblioteca[contbiblio++] = new Revista(nombre, isbn,autor, false, numero,mes);
    }
    else
    {
        std::cout << "Opción inválida" << std::endl;
    };
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
