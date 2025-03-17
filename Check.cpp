#include "Check.h"
#include <iostream>

void controlloScelta(int NumeroTransizione) {
    if (NumeroTransizione > 5 || NumeroTransizione < 1) {
        std::cout << "ERRORE: scegli un numero tra quelli indicati" << std::endl;
    }
}
