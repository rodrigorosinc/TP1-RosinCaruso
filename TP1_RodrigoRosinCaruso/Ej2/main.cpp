#include "PersonajeFactory.hpp"
#include "../Ej1/PersonajesMagicos.hpp"
#include "../Ej1/PersonajesGuerreros.hpp"
#include "../Ej1/ItemsMagicos.hpp"
#include "../Ej1/ItemsCombate.hpp"
#include <iostream>
#include <vector>
#include <memory>


using namespace std;

int main() {
    cout << "Creando personajes..." << endl;
    PersonajeFactory::inicializarSemilla();
    auto personajes = PersonajeFactory::crearPersonajes();
    cout << "==============================" << endl;
    cout << "      Personajes creados:" << endl;
    cout << "==============================" << endl;
    for (int i = 0; i < (int)personajes.size(); ++i) {
        cout << "Personaje " << i + 1 << ": " << personajes[i]->getNombre() << endl;
        cout << "   - Tipo: " << personajes[i]->getTipo() << endl;
        cout << "   - HP: " << personajes[i]->getHP() << endl;
        cout << "-------------------------------" << endl;
    }
    cout << endl;
    cout << "Total de personajes creados: " << personajes.size() << endl;
    cout << endl;

    // Imprimir armas de cada personaje
    for (int i = 0; i < (int)personajes.size(); ++i) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        auto personaje = personajes[i];
        cout << i + 1 << ") " << personaje->getNombre() << endl;
        if (personaje->getArmas().empty()) {
            cout << "   No tiene armas." << endl;
        } else {
            cout << "   Armas:" << endl;
        }
        for (int j = 0; j < (int)personaje->getArmas().size(); ++j) {
            cout << "    " << j + 1 << "- " << personaje->getArmas()[j]->getNombreItem() << endl;
            cout << "      + Tipo: " << personaje->getArmas()[j]->getTipo() << endl;
            cout << "      + Damage: " << personaje->getArmas()[j]->getDamage() << endl;
            cout << "      + Total Damage: " << personaje->getArmas()[j]->getDamTotal() << endl;
        }
    }
    // Los daños de las armas que se muestran son los daños base, es decir, en combate puede hacer más o menos daño
    // dependiendo de la situación. Por ejemplo, si el personaje tiene un arma maldita, el daño se reduce. Si el 
    // personaje tiene un arma legendaria, el daño se aumenta. 
    cout << "==============================" << endl;
    cout << "            Fin." << endl;
    cout << "==============================" << endl;
    return 0;
}