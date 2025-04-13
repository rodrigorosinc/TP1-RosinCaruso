#include "PersonajeFactory.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/PersonajesMagicos.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/PersonajesGuerreros.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/ItemsMagicos.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/ItemsCombate.hpp"

using namespace std;

enum NombreMagos {
    GANDALF,
    MERLIN,
    DUMBLEDORE,
    SARUMAN,
    MORGANA,
    ELMINSTER,
    RINCEWIND,
    RAISTLIN,
    ZATANNA,
    DR_STRANGE,
    HARRY_POTTER,
    HERMIONE_GRANGER,
    SAURON,
    BABA_YAGA,
    YEN_SID,
    GELLERT_GRINDELWALD,
    WHITE_WITCH,
    JARETH,
    PROSPERO,
    NUM_MAGOS // Para contar el número de magos
};


std::string chooseNombreMagos() {
    int randomIndex = rand() % NUM_MAGOS;
    switch (randomIndex){
        case GANDALF: return "Gandalf";
        case MERLIN: return "Merlin";
        case DUMBLEDORE: return "Dumbledore";
        case SARUMAN: return "Saruman";
        case MORGANA: return "Morgana";
        case ELMINSTER: return "Elminster";
        case RINCEWIND: return "Rincewind";
        case RAISTLIN: return "Raistlin";
        case ZATANNA: return "Zatanna";
        case DR_STRANGE: return "Dr. Strange";
        case HARRY_POTTER: return "Harry Potter";
        case HERMIONE_GRANGER: return "Hermione Granger";
        case SAURON: return "Sauron";
        case BABA_YAGA: return "Baba Yaga";
        case YEN_SID: return "Yen Sid";
        case GELLERT_GRINDELWALD: return "Gellert Grindelwald";
        case WHITE_WITCH: return "White Witch";
        case JARETH: return "Jareth";
        case PROSPERO: return "Prospero";
        default: return "Mago Desconocido"; // En caso de que no se haya elegido un nombre válido
    }
}

void PersonajeFactory::inicializarSemilla(){
    srand(time(nullptr));
}

int PersonajeFactory::generarNumerosRandom(int limInf, int limSup){
    return (rand() % (limSup - limInf + 1) ) + limInf;  //limSup - limInf para mover el rango. Lim inf,
                                                        //afuera sumando porq es el min valor que queremos que tome
}

shared_ptr<Magos> PersonajeFactory::crearMago(){
    int tipoMago = generarNumerosRandom(0,3);
    string nombre = chooseNombreMagos();

    int hp = rand() % 60 + 90; // HP entre 90 y 150
    vector<shared_ptr<Arma>> armas;
    int numArmas = generarNumerosRandom(0, 2); // Número de armas entre 0 y 2
    for (int i = 0; i < numArmas; ++i) {
        bool armaCombate = rand() % 2; // 50% de probabilidad de ser un arma de combate
        if (armaCombate) {
            armas.push_back(crearArmaDeCombate());
        } else {
            armas.push_back(crearItemMagico());
        }
    }

    
    shared_ptr<Arma> armaActual;
    if (!armas.empty()) {
        armaActual = armas[0]; // Asignar la primera arma como arma actual
    } else {
        armaActual = nullptr; // No hay armas, así que no hay arma actual
    }

    switch (tipoMago) {
        case 0: return make_shared<Hechicero>(nombre, hp, armas, armaActual);
        case 1: return make_shared<Conjurador>(nombre, hp, armas, armaActual);
        case 2: return make_shared<Nigromante>(nombre, hp, armas, armaActual);
        case 3: return make_shared<Brujo>(nombre, hp, armas, armaActual);
    }
    return nullptr; // En caso de que no se haya creado un personaje

}

shared_ptr<Guerreros> PersonajeFactory::crearGuerrero(){
    int tipoGuerrero = generarNumerosRandom(0,4);
    string nombre = chooseNombreMagos();

    int hp = rand() % 75 + 95; // HP entre 95 y 170
    vector<shared_ptr<Arma>> armas;
    int numArmas = generarNumerosRandom(0, 2); // Número de armas entre 0 y 2
    for (int i = 0; i < numArmas; ++i) {
        bool armaCombate = rand() % 2; // 50% de probabilidad de ser un arma de combate
        if (armaCombate) {
            armas.push_back(crearArmaDeCombate());
        } else {
            armas.push_back(crearItemMagico());
        }
    }
    
    shared_ptr<Arma> armaActual;
    if (!armas.empty()) {
        armaActual = armas[0]; // Asignar la primera arma como arma actual
    } else {
        armaActual = nullptr; // No hay armas, así que no hay arma actual
    }
    
    switch (tipoGuerrero){
        case 0: return make_shared<Caballero>(nombre, hp, armas, armaActual);
        case 1: return make_shared<Barbaro>(nombre, hp, armas, armaActual);
        case 2: return make_shared<Paladin>(nombre, hp, armas, armaActual);
        case 3: return make_shared<Gladiador>(nombre, hp, armas, armaActual);
        case 4: return make_shared<Mercenario>(nombre, hp, armas, armaActual);
    }
    return nullptr; // En caso de que no se haya creado un personaje
}

shared_ptr<ItemMagico> PersonajeFactory::crearItemMagico(){
    int tipoItem = generarNumerosRandom(0, 3);

    switch (tipoItem) {
        case 0: return make_shared<Pocion>();
        case 1: return make_shared<LibroDeHechizos>();
        case 2: return make_shared<Baston>();
        case 3: return make_shared<Amuleto>();
    }
    return nullptr; // En caso de que no se haya creado un item magico
}

shared_ptr<ArmaCombate> PersonajeFactory::crearArmaDeCombate(){
    int tipoArma = generarNumerosRandom(0, 4);

    switch (tipoArma) {
        case 0: return make_shared<HachaSimple>();
        case 1: return make_shared<HachaDoble>();
        case 2: return make_shared<Espada>();
        case 3: return make_shared<Lanza>();
        case 4: return make_shared<Garrote>();
    }
    return nullptr; // En caso de que no se haya creado un arma de combate
}

vector<shared_ptr<Personaje>> PersonajeFactory::crearPersonajes(){
    vector<shared_ptr<Personaje>> personajes;
    int numMagos = generarNumerosRandom(3, 7);
    int numGuerreros = generarNumerosRandom(3, 7);
    
    for (int i = 0; i < numMagos; ++i) {
        personajes.push_back(crearMago());
    }
    
    for (int i = 0; i < numGuerreros; ++i) {
        personajes.push_back(crearGuerrero());
    }
    
    return personajes;
}
