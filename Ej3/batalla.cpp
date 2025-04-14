    #include "/home/rodrigo/TP1-RosinCaruso/Ej1/PersonajesMagicos.hpp"
    #include "/home/rodrigo/TP1-RosinCaruso/Ej1/PersonajesGuerreros.hpp"
    #include "/home/rodrigo/TP1-RosinCaruso/Ej1/ItemsMagicos.hpp"
    #include "/home/rodrigo/TP1-RosinCaruso/Ej1/ItemsCombate.hpp"
    #include "/home/rodrigo/TP1-RosinCaruso/Ej2/PersonajeFactory.hpp"

    using namespace std;

    /*
    . En este ejercicio se programarán la batalla entre sólo dos personajes del ejercicio 2. 
    Las reglas de las peleas siguen un modelo de piedra-papel-tijera, en este caso “Golpe 
    Fuerte”, “Golpe Rápido” y “Defensa y Golpe”.  
    4.1. Elección de ataque: El jugador 1 debe elegir por teclado una de las tres posibles 
    opciones. La opción del jugador 2 viene dada por una variable aleatoria 
    utilizando std::rand(). 
    4.2. Daño y defensa: El “Golpe Fuerte” le gana al “Golpe Rápido” y hace 10 puntos 
    de daño a quien lanzó el “Golpe Rápido”. El “Golpe Rápido” le gana a la “Defensa 
    y Golpe” y hace 10 puntos de daño a quien lanzó “Defensa y Golpe”. Si el 
    personaje usa “Defensa y Golpe” bloquea el “Golpe Fuerte” haciendo 10 puntos 
    de daño a quien lanzó el “Golpe Fuerte”. En caso de que los dos personajes 
    realicen la misma acción, ningún personaje recibirá daño y se pasa a la siguiente 
    ronda de elección. 
    4.3. Interacción: Dado un personaje y un arma, el programa debe indicar el tipo de 
    personaje y con qué arma atacó al otro personaje. Pierde el primer jugador que 
    llega perder todos sus 100 puntos de vida (Health Points o HP). OPCIONAL: si lo 
    desea, añada puntos dependiendo del arma utilizada. 
    4.4. Para iniciar a jugar, elija un personaje y un arma (el arma no modificará la pelea 
    a no ser que implemente los puntos extra de daño), y deje que el otro personaje 
    y arma sean elegidos aleatoriamente. Para seguir la batalla, implemente un 
    menú sencillo, por ejemplo: 
    El jugador 1 tiene XXX HP y el jugador 2 tiene YYY HP. 
    Su opción: (1) Golpe Fuerte, (2) Golpe Rápido, (3) Defensa y Golpe: 1 
    El Caballero ataca con la Espada y hace 10 puntos de daño. 
    El Caballero tiene XXX HP y el Brujo tiene YYY-10 HP. 
    Su opción: (1) Golpe Fuerte, (2) Golpe Rápido, (3) Defensa y Golpe: _
    */

    enum Ataques {
        RAPIDO = 1,
        FUERTE,
        DEFENSA_Y_GOLPE
    };

    int main(){
        int ataqueElegido, ataqueEnemigo, vidaPersonaje1, vidaPersonaje2;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Creando personajes..." << endl;
        PersonajeFactory::inicializarSemilla();
        // Crear personajes
        auto personajes = PersonajeFactory::crearPersonajes();
        cout << "Personajes creados!" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        int randomIndex = rand() % personajes.size();

        auto userPersonaje = personajes[randomIndex];
        cout << "Tu personaje seleccionado es: " << userPersonaje->getNombre() << endl;
        cout << "Tipo: " << userPersonaje->getTipo() << endl;
        cout << "HP: " << userPersonaje->getHP() << endl;
        if (!userPersonaje->getArmas().empty()){
            cout << "Armas: " << endl;
            for (auto& arma : userPersonaje->getArmas()) {
                cout << "- " << arma->getNombreItem() << " (Tipo: " 
                    << arma->getTipo() << ", Daño: " << arma->getDamTotal() 
                    << ")" << endl;
            }
        } 
        else {
            cout << "No tienes armas." << endl;
        }

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        int randomIndex2 = rand() % personajes.size();
        while (randomIndex2 == randomIndex) {
            randomIndex2 = rand() % personajes.size();
        }

        auto enemyPersonaje = personajes[randomIndex2];
        cout << "El enemigo es: " << enemyPersonaje->getNombre() << endl;
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
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Comienza la batalla!" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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

            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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

            if (ataqueElegido == FUERTE && ataqueEnemigo == RAPIDO) {
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
            } else if (ataqueElegido == DEFENSA_Y_GOLPE && ataqueEnemigo == FUERTE) {
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
            } else if (ataqueElegido == RAPIDO && ataqueEnemigo == DEFENSA_Y_GOLPE) {
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
            } else {
                cout << "Ambos personajes han elegido la misma accion. No hay daño." << endl;
            }
            cout << endl;
            vidaPersonaje1 = userPersonaje->getHP();
            vidaPersonaje2 = enemyPersonaje->getHP();
            if (vidaPersonaje1 < 0) {
                vidaPersonaje1 = 0;
            }
            if (vidaPersonaje2 < 0) {
                vidaPersonaje2 = 0;
            }
            cout << "Tu personaje tiene " << vidaPersonaje1 << " HP." << endl;
            cout << "El enemigo tiene " << vidaPersonaje2 << " HP." << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
        if (userPersonaje->getHP() <= 0 && enemyPersonaje->getHP() <= 0) {
            cout << "Empate! Ambos personajes cayeron al mismo tiempo." << endl;
        } else if (userPersonaje->getHP() <= 0) {
            cout << "Has sido derrotado! El enemigo gana la batalla." << endl;
        } else {
            cout << "¡Victoria! Has derrotado al enemigo." << endl;
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        return 0;
    }