#include "MaterialBibliografico.h"
#include <string>

class libro : public MaterialBibliografico{
    protected:
        std::string fechaPublicacion;
        std::string resumen;
    public:
        ~libro();
        libro(std:: string nombre, int isbn, std::string autor, bool prestado, std::string fechaPublicacion,std::string resumen);
        void mostrarInformacion() const;

        std::string getFechaPublicacion();
        std::string getResumen();
};