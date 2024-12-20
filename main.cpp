#include <iostream>
#include <string>
#include "Grafo.cpp"
using namespace std;
int main() {
    Grafo<std::string> grafo;

    //Aggiungi nodo (città) 
    grafo.aggiungiNodo("Taranto");
    grafo.aggiungiNodo("Bari");
    grafo.aggiungiNodo("Brindisi");
    grafo.aggiungiNodo("Lecce");
    grafo.aggiungiNodo("Foggia");

    // Aggiungi arco (città di partenza, città di arrivo, peso)
    grafo.aggiungiArco("Taranto", "Bari", 100); 
    grafo.aggiungiArco("Bari", "Brindisi", 90); 
    grafo.aggiungiArco("Brindisi", "Lecce", 80); 
    grafo.aggiungiArco("Lecce", "Foggia", 200); 
    grafo.aggiungiArco("Taranto", "Lecce", 150); 
    grafo.aggiungiArco("Foggia", "Bari", 170); 

    //Stampa della matriceAdiacenza
    grafo.stampa();
    
    //Verifica se esiste un nodo nel grafo
    cout << "Esiste il nodo Lecce? " 
    << (grafo.esisteNodo("Lecce") ? "Sì" : "No") << endl;
    
    //Visualizzazione dei nodiAdiacenti
    grafo.nodiAdiacenti("Taranto");
    grafo.nodiAdiacenti("Bari");

   // Verificare se un arco esiste tra due nodi
    std::cout << "Esiste arco tra Taranto e Bari? " 
              << (grafo.verificaArco("Taranto", "Bari") ? "Sì" : "No");
    
    // Rimozione nodo 
    grafo.rimuoviNodo("Lecce");
    grafo.stampa();

    // Rimozione arco specifico
    grafo.rimuoviArco("Taranto", "Bari");
    grafo.stampa();
    
    // Aggiungere un nuovo nodo e arco
    grafo.aggiungiNodo("SanVito");
    grafo.aggiungiArco("Foggia", "SanVito", 15);
    std::cout << "Matrice di Adiacenza dopo l'aggiunta del nodo SanVito e dell'arco tra Foggia e SanVito:" << std::endl;
    grafo.stampa();

    // Verificare la connessione tra due nodi
    std::cout << "Il nodo Taranto è connesso al nodo Foggia? " << (grafo.verificaArco("Taranto", "Foggia") ? "Sì" : "No") << std::endl;

    // Trovare l'arco con peso minore per un nodo
    int arcoMinimo = grafo.arcoConPesoMinore("Foggia");
    if (arcoMinimo != -1) {
        std::cout << "L'arco con il peso minimo da Foggia ha peso: " << arcoMinimo << std::endl;
    } else {
        std::cout << "Non ci sono archi uscenti da Foggia." << std::endl;
    }
    return 0;
}
