#include "PersonajeFactory.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/PersonajesMagicos.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/PersonajesGuerreros.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/ItemsMagicos.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/ItemsCombate.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>

using namespace std;

int main() {
    cout << "Creando personajes..." << endl;
    PersonajeFactory::inicializarSemilla();

    
    auto personajes = PersonajeFactory::crearPersonajes();
    for (auto& p : personajes) {
        cout << p->getNombre() << " (" << p->getTipo() << ") - HP: " 
             << p->getHP() << " - Armas: " << p->getArmas().size() << endl;
    }
    cout << "Total de personajes creados: " << personajes.size() << endl;

    cout << "Personajes creados: " << personajes.size() << endl;
    for (const auto& p : personajes) {
        cout << p->getNombre() << " (" << p->getTipo() << ") - HP: " 
             << p->getHP() << " - Armas: " << p->getArmas().size() << endl;
    }
    
    return 0;
}