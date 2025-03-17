#include "ContoCorrente.h"
#include <fstream>
#include <iomanip>

// Costruttore
ContoCorrente::ContoCorrente() : saldo(0) {}

// Aggiunge una transazione e aggiorna il saldo
void ContoCorrente::aggiungiTransazione(const std::string& tipo, double importo) {
    if (tipo == "Uscita" && importo > saldo) {
        std::cout << "Saldo insufficiente!" << std::endl;
        return;
    }
    transazioni.emplace_back(tipo, importo);
    saldo += (tipo == "Entrata" ? importo : -importo);  //operatore ternario
}

// Salva le transazioni su file
void ContoCorrente::salvaSuFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Errore nell'apertura del file." << std::endl;
        return;
    }
    file << saldo << std::endl;
    for (const auto& t : transazioni) {
        file << t.tipo << " " << t.importo << std::endl;
    }
    file.close();
}

// Carica le transazioni da file
void ContoCorrente::caricaDaFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Errore nell'apertura del file." << std::endl;
        return;
    }
    transazioni.clear();
    file >> saldo;
    std::string tipo;
    double importo;
    while (file >> tipo >> importo) {
        transazioni.emplace_back(tipo, importo);
    }
    file.close();
}

// Mostra le transazioni e il saldo attuale
void ContoCorrente::mostraTransazioni() const {
    std::cout << "\nLista transazioni:" << std::endl;
    for (const auto& t : transazioni) {
        std::cout << t.tipo << " : " << std::fixed << std::setprecision(2) << t.importo << " EUR" << std::endl;
    }
    std::cout << "Saldo attuale: " << saldo << " EUR" << std::endl;
}

// Mostra solo il saldo
void ContoCorrente::visualizzaSaldo() {
    std::cout << "Il tuo saldo attuale e' di: " << saldo << " EUR" << std::endl;
}
