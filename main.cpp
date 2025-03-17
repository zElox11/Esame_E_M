#include "ContoCorrente.h"
#include "Check.h"


int main() {
    ContoCorrente conto;
    conto.caricaDaFile("transazioni.txt");

    int scelta;
    do {
        // Menu di scelta per l'utente
        std::cout << "1. Aggiungi Entrata" << std::endl;
        std::cout << "2. Aggiungi Uscita" << std::endl;
        std::cout << "3. Mostra Transazioni" << std::endl;
        std::cout << "4. Mostra Saldo" << std::endl;
        std::cout << "5. Salva e Esci" << std::endl;
        std::cout << "Scegli un numero: ";
        std::cin >> scelta;

        controlloScelta(scelta);

        if (scelta == 1 || scelta == 2) {
            double importo;
            std::cout << "Inserisci importo: ";
            std::cin >> importo;
            conto.aggiungiTransazione(scelta == 1 ? "Entrata" : "Uscita", importo);  //operatore ternario
        } else if (scelta == 3) {
            conto.mostraTransazioni();
        } else if (scelta == 4) {
            conto.visualizzaSaldo();
        }
    } while (scelta != 5);

    conto.salvaSuFile("transazioni.txt");
    std::cout << "Dati salvati. Arrivederci!" << std::endl;
    return 0;
}
