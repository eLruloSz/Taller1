#include "MaterialBibliografico.h"
#include <string>

class libro : MaterialBibliografico{
    protected:
        std::string fechaPublicacion;
        std::string resumen;
    public:
        ~libro();
        libro(std::string fechaPublicacion,std::string resumen);
        void mostrarInformacion() const;

        std::string getFechaPublicacion();
        std::string getResumen();
};