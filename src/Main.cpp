#include <iostream>
#include <fstream>
#include "../include/Libro.h"
#include "../include/MaterialBibliografico.h"
#include "../include/Revista.h"
#include "../include/Usuario.h"
#include "Libro.cpp"
#include "MaterialBibliografico.cpp"
#include "Revista.cpp"
#include "Usuario.cpp"
#include <typeinfo> 

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
                 "6. SALIR \n" <<
                 "Ingresar opcion: ";
}
//Agregara Material Libro o Revista a la lista biblioteca
void agregarMaterial() {
    if(contBi<100){
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
}
//Muestra la informacion de la Biblioteca
void mostrarInformacion() {
    for (MaterialBibliografico* biblio: biblioteca) {
        if(biblio!=nullptr) {
            
            std::cout<<biblio->mostrarInformacion()<<"\n------------------\n"<<std::endl;
        }
    }
}
//Busca la biblioteca y muesttra su informacion
void buscarBiblio() {
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
/*
    Busca Usuario deseado
    @param string
    @return usuario
 */
Usuario* buscarUsuario(const std::string & string) {
    for (Usuario* usuario: usuarios) {
            if(usuario != nullptr &&usuario->getNombre()==string) {
                return usuario;
            }
    }
    return nullptr;
}
/*
    Busca Material deseado
    @param string
    @return biblio
 */
MaterialBibliografico * buscarMaterial(const std::string & string) {
    for (MaterialBibliografico* biblio: biblioteca) {
            if(biblio != nullptr &&(biblio->getNombre()==string||biblio->getAutor()==string)) {
                return biblio;
            }
    }
    return nullptr;
}
//Segun la opcion escogida prestara al usuario o devolvera el materal
void prestarODevolver() {
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
/*
    Gestion de los Usuarios ya sea
    Crear un Usuaio
    Buscar un usuario y mostrar su informacion
    Eliminar un usuario
 */
void gestionUsuario()
{
    std::cout << "Gestion de Usuario:\n"
              << "1. Crear Usuario\n"
              << "2. Buscar un Usuario\n"
              << "3. Eliminar un Usuario\n"
              << "Ingrese una opcion: ";
    int opcionusuario;
    std::cin >> opcionusuario;
    if (opcionusuario == 1)
    {
        if(contUsu<100){
            std::cout << "Nombre: ";
            std::string nombre;
            std::cin >> nombre;
            std::cout << "ID: ";
            std::string id;
            std::cin >> id;
            usuarios[contUsu++] = new Usuario(nombre, id);
        }
    }
    else if (opcionusuario == 2)
    {
        std::cout << "Nombre: ";
        std::string nombre;
        std::cin >> nombre;
        Usuario *usuariobuscado = buscarUsuario(nombre);
        std::cout << usuariobuscado->informacion();
        std::cout << usuariobuscado->mostrarMaterialesPrestados();
    }
    else if (opcionusuario == 3) {
    std::cout << "Nombre: ";
    std::string nombre;
    std::cin >> nombre;
    Usuario *usuariobuscado = buscarUsuario(nombre);
    if (usuariobuscado != nullptr) {
        for (int i = 0; i < contUsu; i++) {
            if (usuarios[i] == usuariobuscado) {
                delete usuarios[i];
                usuarios[i] = usuarios[--contUsu];
                break;
            }
        }
    } else {
        std::cout << "Usuario no encontrado.\n";
    }
}

    {
        
        return;
    };
}
int main() {
    bool activo = true;
    while (activo) {
        mostrarMenu();
        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                //Logica para agregar material a la biblioteca
                agregarMaterial();
                break;
            }
            case 2: {
                // Lógica para mostrar información de la biblioteca
                mostrarInformacion();
                break;
            }
            case 3: {
                // Lógica para buscar en la biblioteca
                buscarBiblio();
                break;
            }
            case 4: {
                // Lógica para prestar o devolver
                prestarODevolver();
                break;
            }
            case 5: {
                // Lógica para gestión de usuarios
                gestionUsuario();
            }case 6:{
                //Guarda la informacion de la biblioteca a un archivo txt y detener el programa
                std::ofstream archivo("biblioteca.txt", std::ios::app);
                if (archivo.is_open()) {
                    for(MaterialBibliografico* biblio : biblioteca){
                        if(dynamic_cast<Revista*>(biblio)){
                            Revista* revistaPtr = dynamic_cast<Revista*>(biblio);
                             archivo<<"Revista" << "," << revistaPtr->getNombre()<< "," << revistaPtr->getIsbn() << "," << revistaPtr->getAutor() << "," <<revistaPtr->getPrestado() << "," << revistaPtr->getNumeroEdicion() << "," << revistaPtr->getMesPublicacion() <<  std::endl;
                        }else{
                            Libro* libroPtr = dynamic_cast<Libro*>(biblio);
                            archivo<<"Libro" << "," <<  libroPtr->getNombre()<< "," << libroPtr->getIsbn() << "," << libroPtr->getAutor() << "," <<libroPtr->getPrestado() << "," << libroPtr->getFechadePublicacion() << "," << libroPtr->getResumen() <<  std::endl;
                        }
                        
                    }
                    archivo.close();
                }else{
                    std::cout << "Error al abrir el archivo" <<std::endl;
                }

                std::cout << "Salida exitosa";
                activo = false;
                break;
            }
            default:
                std::cout << "Ingrese opción válida";
                break;
        }
    }

    return 0;
}


