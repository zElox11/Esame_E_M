#ifndef contocorrente_h
#define contocorrente_h

#include "Transazioni.h"
#include <vector>
#include <iostream>

class ContoCorrente {
private:
    std::vector<Transazione> transazioni;
    double saldo;

public:
    ContoCorrente();
    void aggiungiTransazione(const std::string& tipo, double importo);
    void salvaSuFile(const std::string& filename);
    void caricaDaFile(const std::string& filename);
    void mostraTransazioni() const;
    void visualizzaSaldo();
};

#endif // contocorrente_h
