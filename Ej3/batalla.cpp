#include "/home/rodrigo/TP1-RosinCaruso/Ej1/PersonajesMagicos.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/PersonajesGuerreros.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/ItemsMagicos.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/ItemsCombate.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej2/PersonajeFactory.hpp"

using namespace std;

enum Ataques {
    RAPIDO = 1,
    FUERTE,
    DEFENSA_Y_GOLPE
};

int main(){
    int ataqueElegido, ataqueEnemigo, vidaPersonaje1, vidaPersonaje2;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Creando personajes..." << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    PersonajeFactory::inicializarSemilla();
    // Crear personajes
    auto personajes = PersonajeFactory::crearPersonajes();
    cout << "Personajes creados!" << endl;
    cout << "Elija uno: " << endl;
    int personajeElegido;
    for (int i = 0; i < (int) personajes.size(); ++i) {
        cout << "(" << i + 1 << ") " << personajes[i]->getNombre()
            << " (" << personajes[i]->getTipo() << ")" << endl;
    }
    cout << "->";
    cin >> personajeElegido;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    // Validar la entrada del usuario
    while (personajeElegido < 1 || personajeElegido > (int)personajes.size()) {
        cout << "Opcion invalida. Elija uno: ";
        cin >> personajeElegido;
    }
    cout << endl;
    auto userPersonaje = personajes[personajeElegido - 1];   
    cout << "Tu personaje seleccionado es: " << userPersonaje->getNombre() << endl;
    cout << "Tipo: " << userPersonaje->getTipo() << endl;
    cout << "HP: " << userPersonaje->getHP() << endl;
    // Mostrar armas del personaje si tiene. Se le solicita seleccionar una.
    if (!userPersonaje->getArmas().empty()){
        cout << "+ Armas: " << endl;
        for (auto& arma : userPersonaje->getArmas()) {
            cout << "   - " << arma->getNombreItem() << " (Tipo: " 
                << arma->getTipo() << ", Daño: " << arma->getDamTotal() 
                << ")" << endl;
        }
        if (userPersonaje->getArmas().size() > 1) { // Si tiene más de una arma, se le pide elegir
            cout << "Seleccione una: " << endl;
            int armaElegida;
            cin >> armaElegida;
            while (armaElegida < 1 || armaElegida > (int) userPersonaje->getArmas().size()) {
                cout << "Opcion invalida. Seleccione una: ";
                cin >> armaElegida;
            }
            userPersonaje->setArmaActual(userPersonaje->getArmas()[armaElegida - 1]);
            cout << "Arma seleccionada: " << userPersonaje->getArmas()[armaElegida - 1]->getNombreItem() << endl;
        } else { // Si solo tiene una arma, se selecciona automaticamente
            userPersonaje->setArmaActual(userPersonaje->getArmas()[0]);
            cout << "Tu arma es: " << userPersonaje->getArmas()[0]->getNombreItem() << endl;
        }
    } else {
        cout << "No tienes armas." << endl;
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    // Elegir enemigo al azar
    cout << "Tu enemigo sera: " << endl;
    int randomIndex2 = rand() % (int) personajes.size();
    while (randomIndex2 == personajeElegido - 1) {
        randomIndex2 = rand() % (int) personajes.size();
    }
    auto enemyPersonaje = personajes[randomIndex2];
    cout << enemyPersonaje->getNombre() << endl;
    cout << "Tipo: " << enemyPersonaje->getTipo() << endl;
    cout << "HP: " << enemyPersonaje->getHP() << endl;
    if (!enemyPersonaje->getArmas().empty()){
        cout << "Armas: " << endl;
        for (auto& arma : enemyPersonaje->getArmas()) {
            cout << "- " << arma->getNombreItem() << " (Tipo: " 
                << arma->getTipo() << ", Daño: " << arma->getDamTotal() 
                << ")" << endl;
        }
    } 
    else {
        cout << "No tiene armas." << endl;
    }
    cout << endl;

    // Batalla
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Comienza la batalla!" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    while (userPersonaje->getHP() > 0 && enemyPersonaje->getHP() > 0) {
        cout << "Elige un ataque: " << endl;
        cout << "(1) Golpe Rapido" << endl;
        cout << "(2) Golpe Fuerte" << endl;
        cout << "(3) Defensa y Golpe" << endl;
        cout << "->";
        cin >> ataqueElegido;
        while (ataqueElegido < 1 || ataqueElegido > 3) {
            cout << "Opcion invalida. Elige un ataque: ";
            cin >> ataqueElegido;
        }
        cout << endl;

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Tu eligiste: ";
        if (ataqueElegido == RAPIDO) {
            cout << "Golpe Rapido" << endl;
        } else if (ataqueElegido == FUERTE) {
            cout << "Golpe Fuerte" << endl;
        } else if (ataqueElegido == DEFENSA_Y_GOLPE) {
            cout << "Defensa y Golpe" << endl;
        }
        ataqueEnemigo = rand() % 3 + 1;
        cout << "El enemigo elige: ";
        if (ataqueEnemigo == RAPIDO) {
            cout << "Golpe Rapido" << endl;
        } else if (ataqueEnemigo == FUERTE) {
            cout << "Golpe Fuerte" << endl;
        } else if (ataqueEnemigo == DEFENSA_Y_GOLPE) {
            cout << "Defensa y Golpe" << endl;
        }
        cout << endl;

        if (ataqueElegido == FUERTE && ataqueEnemigo == RAPIDO) { // Fuerte le gana a Rapido
            cout << "Ganaste el ataque!" << endl;
            cout << "El ataque fuerte le gana al ataque rapido!" << endl;
            if (userPersonaje->getArmas().size() > 0) {
                cout << "El enemigo recibe ";
                userPersonaje->ataqueFuerte(enemyPersonaje);
                cout << " de daño." << endl;
            } else {
                enemyPersonaje->setHP(enemyPersonaje->getHP() - 10);
                cout << "El enemigo recibe 10 puntos de daño." << endl;
            }
        } else if (ataqueElegido == RAPIDO && ataqueEnemigo == FUERTE) {
            cout << "Perdiste el ataque!" << endl;
            cout << "El ataque fuerte le gana al rápido!" << endl;
            if (enemyPersonaje->getArmas().size() > 0) {
                cout << "Tu personaje recibe ";
                enemyPersonaje->ataqueFuerte(userPersonaje);
                cout << " de daño." << endl;
            } else {
                userPersonaje->setHP(userPersonaje->getHP() - 10);
                cout << "Recibes 10 puntos de daño." << endl;
            }
        } else if (ataqueElegido == DEFENSA_Y_GOLPE && ataqueEnemigo == FUERTE) { // Defensa y Golpe le gana a Fuerte
            cout << "Ganaste el ataque!" << endl;
            cout << "El ataque defensa y golpe le gana al ataque fuerte!" << endl;
            if (userPersonaje->getArmas().size() > 0) {
                cout << "El enemigo recibe ";
                userPersonaje->defensaYGolpe(enemyPersonaje);
                cout << " de daño." << endl;
            } else {
                enemyPersonaje->setHP(enemyPersonaje->getHP() - 10);
                cout << "El enemigo recibe 10 puntos de daño." << endl;
            }
        } else if (ataqueElegido == FUERTE && ataqueEnemigo == DEFENSA_Y_GOLPE) {
            cout << "Perdiste el ataque!" << endl;
            cout << "El ataque defensa y golpe le gana al ataque fuerte!" << endl;
            if (enemyPersonaje->getArmas().size() > 0) {
                cout << "Tu personaje recibe ";
                enemyPersonaje->defensaYGolpe(userPersonaje);
                cout << " de daño." << endl;
            } else {
            userPersonaje->setHP(userPersonaje->getHP() - 10);
            cout << "Tu personaje recibe 10 puntos de daño." << endl;
            }
        } else if (ataqueElegido == RAPIDO && ataqueEnemigo == DEFENSA_Y_GOLPE) { // Rapido le gana a Defensa y Golpe
            cout << "Ganaste el ataque!" << endl;
            cout << "El ataque rapido le gana a defensa y golpe!" << endl;
            if (userPersonaje->getArmas().size() > 0) {
                cout << "El enemigo recibe ";
                userPersonaje->ataqueRapido(enemyPersonaje);
                cout << " de daño." << endl;
            } else {
                enemyPersonaje->setHP(enemyPersonaje->getHP() - 10);
                cout << "El enemigo recibe 10 puntos de daño." << endl;
            }
        } else if (ataqueElegido == DEFENSA_Y_GOLPE && ataqueEnemigo == RAPIDO) {
            cout << "Perdiste el ataque!" << endl;
            cout << "El ataque defensa y golpe le gana al ataque rapido!" << endl;
            if (enemyPersonaje->getArmas().size() > 0) {
                cout << "Tu personaje recibe ";
                enemyPersonaje->ataqueRapido(userPersonaje);
                cout << " de daño." << endl;

            } else {
                userPersonaje->setHP(userPersonaje->getHP() - 10);
                cout << "Tu personaje recibe 10 puntos de daño." << endl;
            }
        } else { // Empate
            cout << "Ambos personajes han elegido la misma accion. No hay daño." << endl;
        }
        cout << endl;
        // Mostrar HP de ambos personajes
        vidaPersonaje1 = userPersonaje->getHP();
        vidaPersonaje2 = enemyPersonaje->getHP();
        if (vidaPersonaje1 < 0) {
            vidaPersonaje1 = 0;
        }
        if (vidaPersonaje2 < 0) {
            vidaPersonaje2 = 0;
        }
        cout << "Tu HP: " << vidaPersonaje1 << endl;
        cout << "Vida del Enemigo: " << vidaPersonaje2 << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
    // Mostrar resultado de la batalla
    if (userPersonaje->getHP() <= 0 && enemyPersonaje->getHP() <= 0) {
        cout << "Empate! Ambos personajes cayeron al mismo tiempo." << endl;
    } else if (userPersonaje->getHP() <= 0) {
        cout << "Has sido derrotado! El enemigo gana la batalla." << endl;
    } else {
        cout << "¡Victoria! Has derrotado al enemigo." << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    return 0;
}