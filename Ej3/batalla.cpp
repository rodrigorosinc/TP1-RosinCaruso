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
    cout << "Creando personajes..." << endl;
    PersonajeFactory::inicializarSemilla();
    
    // Crear personajes
    auto personajes = PersonajeFactory::crearPersonajes();

    int randomIndex = rand() % personajes.size();

    auto userPersonaje = personajes[randomIndex];
    cout << "El personaje seleccionado es: " << userPersonaje->getNombre() << endl;
    cout << "Tipo: " << userPersonaje->getTipo() << endl;
    cout << "HP: " << userPersonaje->getHP() << endl;
    cout << "Armas: " << endl;
    for (const auto& arma : userPersonaje->getArmas()) {
        cout << "- " << arma->getNombreItem() << " (Tipo: " 
             << arma->getTipo() << ", Daño: " << arma->getDamage() 
             << ")" << endl;
    }
    cout << endl;

    int randomIndex2 = rand() % personajes.size();
    while (randomIndex2 == randomIndex) {
        randomIndex2 = rand() % personajes.size();
    }

    auto enemyPersonaje = personajes[randomIndex2];
    cout << "El enemigo es: " << enemyPersonaje->getNombre() << endl;
    cout << "Tipo: " << enemyPersonaje->getTipo() << endl;
    cout << "HP: " << enemyPersonaje->getHP() << endl;
    cout << "Armas: " << endl;
    for (const auto& arma : enemyPersonaje->getArmas()) {
        cout << "- " << arma->getNombreItem() << " (Tipo: " 
             << arma->getTipo() << ", Daño: " << arma->getDamage() 
             << ")" << endl;
    }
    cout << endl;

    cout << "Comienza la batalla!" << endl;

    bool empiezo = rand() % 2 == 0;
    if (empiezo) {
        cout << userPersonaje->getNombre() << " empieza!" << endl;
        userPersonaje->setTurno(true);
        enemyPersonaje->setTurno(false);
    } else {
        cout << enemyPersonaje->getNombre() << " empieza!" << endl;
        userPersonaje->setTurno(false);
        enemyPersonaje->setTurno(true);
    }
    cout << endl;

    int ataqueElegido;
    
    while (userPersonaje->getHP() > 0 && enemyPersonaje->getHP() > 0){
        if (userPersonaje->getTurno()) {
            cout << userPersonaje->getNombre() << ", elige tu ataque:" << endl;
            cout << "1. Ataque Rápido" << endl;
            cout << "2. Ataque Fuerte" << endl;
            cout << "3. Defensa y Golpe" << endl;
            cout << "-> ";
            cin >> ataqueElegido;
            while (ataqueElegido < 1 || ataqueElegido > 3) {
                cout << "Opción inválida. Elige nuevamente: ";
                cin >> ataqueElegido;
            }
            cout << endl;
            switch (ataqueElegido) {
                case RAPIDO:
                    cout << userPersonaje->getNombre() << " ataca!" << endl;
                    userPersonaje->ataqueRapido(enemyPersonaje);
                    cout << enemyPersonaje->getNombre() << " HP: " << enemyPersonaje->getHP() << endl;
                    break;
                case FUERTE:
                    cout << userPersonaje->getNombre() << " ataca!" << endl;
                    userPersonaje->ataqueFuerte(enemyPersonaje);
                    cout << enemyPersonaje->getNombre() << " HP: " << enemyPersonaje->getHP() << endl;
                    break;
                case DEFENSA_Y_GOLPE:
                    cout << userPersonaje->getNombre() << " ataca!" << endl;
                    userPersonaje->defensaYGolpe(enemyPersonaje);
                    cout << enemyPersonaje->getNombre() << " HP: " << enemyPersonaje->getHP() << endl;
                    break;
                default:
                    cout << "Opción inválida." << endl;
                    continue; // Volver a pedir la opción
            }
            userPersonaje->setTurno(false);
            enemyPersonaje->setTurno(true);
        } else {
            cout << enemyPersonaje->getNombre() << " ataca!" << endl;
            int ataqueAleatorio = rand() % 3 + 1; // Genera un número entre 1 y 3
            switch (ataqueAleatorio) {
                case RAPIDO:
                    enemyPersonaje->ataqueRapido(userPersonaje);
                    break;
                case FUERTE:
                    enemyPersonaje->ataqueFuerte(userPersonaje);
                    break;
                case DEFENSA_Y_GOLPE:
                    enemyPersonaje->defensaYGolpe(userPersonaje);
                    break;
                default:
                    cout << "Opción inválida." << endl;
                    continue; // Volver a pedir la opción
            }
            cout << userPersonaje->getNombre() << " HP: " << userPersonaje->getHP() << endl;
            userPersonaje->setTurno(true);
            enemyPersonaje->setTurno(false);
        }
    }
    return 0;
}