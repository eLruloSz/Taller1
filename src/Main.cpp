#include <iostream>
#include "../include/Libro.h"
#include "../include/MaterialBibliografico.h"
#include "../include/Revista.h"
#include "../include/Usuario.h"
#include "Libro.cpp"
#include "MaterialBibliografico.cpp"
#include "Revista.cpp"
#include "Usuario.cpp"

static MaterialBibliografico* biblioteca[100];
static int contBi = 0;
static Usuario* usuarios[100];
static int contUsu = 0;

void mostrarMenu() {
    std::cout << "Bienvenido\n" <<
                 "1. Agregar Material a la Biblioteca\n" <<
                 "2. Mostrar informacion de la biblioteca\n" <<
                 "3. Buscar en la Biblioteca\n" <<
                 "4. Prestar o Devolver\n" <<
                 "5. Gestion de Usuarios\n" <<
                 "Ingresar opcion: ";
}

void opcion1() {
    std::cout << "Tipo (libro/revista): ";
    std::string tipo;
    std::cin >> tipo;

    std::cout << "Nombre: ";
    std::string nombre;
    std::cin >> nombre;

    std::cout << "ISBN: ";
    std::string isbn;
    std::cin >> isbn;

    std::cout << "Autor: ";
    std::string autor;
    std::cin >> autor;

    if ("libro" == tipo) {
        std::cout << "Fecha de Publicacion: ";
        std::string fecha;
        std::cin >> fecha;
        std::cout << "Resumen: ";
        std::string resumen;
        std::cin >> resumen;
        biblioteca[contBi++] = new Libro(nombre, isbn, autor, false, fecha, resumen);
    } else if ("revista" == tipo) {
        std::cout << "Numero de Edicion: ";
        std::string edicion;
        std::cin >> edicion;
        std::cout << "Mes de Publicacion: ";
        std::string mes;
        std::cin >> mes;
        biblioteca[contBi++] = new Revista(nombre, isbn, autor, false, edicion, mes);
    } else {
        std::cout << "Tipo no válido. Intente de nuevo.\n";
    }
}

void opcion2() {
    for (MaterialBibliografico* biblio: biblioteca) {
        if(biblio!=nullptr) {
            std::cout<<biblio->mostrarInformacion()<<"\n------------------\n"<<std::endl;
        }
    }
}

void opcion3() {
    std::cout << "Titulo/Autor: ";
    std::string buscar;
    std::cin >> buscar;
    for (MaterialBibliografico* biblio: biblioteca) {
        if(biblio->getNombre() == buscar||biblio->getAutor() == buscar) {
            std::cout<<biblio->mostrarInformacion()<<"\n------------------\n"<<std::endl;
            break;
        }
    }
}

Usuario* buscarUsuario(const std::string & string) {
    for (Usuario* usuario: usuarios) {
            if(usuario != nullptr &&usuario->getNombre()==string) {
                return usuario;
            }
    }
    return nullptr;
}

MaterialBibliografico * buscarMaterial(const std::string & string) {
    for (MaterialBibliografico* biblio: biblioteca) {
            if(biblio != nullptr &&(biblio->getNombre()==string||biblio->getAutor()==string)) {
                return biblio;
            }
    }
    return nullptr;
}

void opcion4() {
    std::cout << "prestar/devolver: ";
    std::string prebus;std::cin >> prebus;
    std::cout << "Nombre del usuario: ";
    std::string nombre;std::cin >> nombre;
    Usuario* usuario = buscarUsuario(nombre);
    std::cout << "Titulo/Autor: ";
    std::string buscar;std::cin >> buscar;
    MaterialBibliografico* material = buscarMaterial(buscar);
    if("prestar"==prebus) {
        usuario->prestarMaterial(material);
    }
    if("devolver"==prebus) {
        usuario->devolverMaterial(buscar);
    }
}

int main() {
    bool activo = true;

    while (activo) {
        mostrarMenu();
        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                opcion1();
                break;
            }
            case 2: {
                // Lógica para mostrar información de la biblioteca
                opcion2();
                break;
            }
            case 3: {
                // Lógica para buscar en la biblioteca
                opcion3();
                break;
            }
            case 4: {
                // Lógica para prestar o devolver
                opcion4();
                break;
            }
            case 5: {
                // Lógica para gestión de usuarios
                std::cout<<"Gestion de Usuario:\n"
                         <<"1. Crear Usuario\n"
                         <<"2. Buscar un Usuario\n"
                         <<"3. Eliminar un Usuario\n"
                         <<"Ingrese una opcion: ";
                int opcionusuario;std::cin>>opcionusuario;
                if(opcionusuario == 1) {
                    std::cout<<"Nombre: ";
                    std::string nombre;std::cin>>nombre;
                    std::cout<<"ID: ";
                    std::string id;std::cin>>id;
                    usuarios[contUsu++] = new Usuario(nombre,id);
                }
                else if(opcionusuario==2) {

                }
                else if(opcionusuario==3) {

                }
                break;
            }
            default:
                activo = false;
                break;
        }
    }

    // Liberar memoria si es necesario (por ejemplo, liberar biblioteca y usuarios)
    return 0;
}
