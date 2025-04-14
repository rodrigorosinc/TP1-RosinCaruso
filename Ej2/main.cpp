#include "PersonajeFactory.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/PersonajesMagicos.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/PersonajesGuerreros.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/ItemsMagicos.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/ItemsCombate.hpp"
#include <iostream>
#include <vector>
#include <memory>


using namespace std;

int main() {
    cout << "Creando personajes..." << endl;
    PersonajeFactory::inicializarSemilla();

    cout << endl;
    auto personajes = PersonajeFactory::crearPersonajes();
    for (auto& p : personajes) {
        cout << p->getNombre() << " (" << p->getTipo() << ") - HP: " 
             << p->getHP() << " - Armas: " << p->getArmas().size() << endl;
    }
    cout << "Total de personajes creados: " << personajes.size() << endl;
    cout << endl;
    cout << "------------------------------" << endl;
    cout << endl;

    // Imprimir armas de cada personaje
    for (const auto& personaje : personajes) {
        cout << "Armas de " << personaje->getNombre() << ":" << endl;
        if (personaje->getArmas().size() == 0) {
            cout << "No tiene armas." << endl;
        }
        for (const auto& arma : personaje->getArmas()) {
            cout << "- " << arma->getNombreItem() << " (Tipo: " 
                 << arma->getTipo() << ", Daño: " << arma->getDamage() 
                 << ")" << endl;
        }
        cout << endl;
    }

    return 0;
}