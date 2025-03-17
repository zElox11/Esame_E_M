#ifndef Transazione_h
#define Transazione_h

#include <string>

class Transazione {
public:
    std::string tipo; // "Entrata" o "Uscita"
    double importo;

    // Costruttore
    Transazione(std::string t, double i);
};

#endif // Transazione_h
