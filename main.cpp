#include <iostream>
#include <chrono>

// Eine optimierte Funktion, um zu prüfen, ob eine Zahl eine Primzahl ist
bool istPrimzahl(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // Wir prüfen nur bis zur Quadratwurzel von n – das spart enorm viel Rechenzeit!
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    
    int zaehler = 0;
    // Wir testen alle Zahlen bis 1 Million
    for (int i = 1; i <= 1000000; ++i) {
        if (istPrimzahl(i)) {
            zaehler++;
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> dauer = end - start;
    
    std::cout << "Gefundene Primzahlen: " << zaehler << std::endl;
    std::cout << "Dauer der Berechnung: " << dauer.count() << " Sekunden." << std::endl;
    
    return 0;
}
