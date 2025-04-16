#include "PersonajeFactory.hpp"
#include "../Ej1/PersonajesMagicos.hpp"
#include "../Ej1/PersonajesGuerreros.hpp"
#include "../Ej1/ItemsMagicos.hpp"
#include "../Ej1/ItemsCombate.hpp"

using namespace std;

enum NombreMagos {
    GANDALF, MERLIN, DUMBLEDORE, SARUMAN,
    MORGANA, ELMINSTER, RINCEWIND, RAISTLIN,
    ZATANNA, DR_STRANGE, HARRY_POTTER, HERMIONE_GRANGER,
    SAURON, BABA_YAGA, YEN_SID, GELLERT_GRINDELWALD,
    WHITE_WITCH, JARETH, PROSPERO, 
    NUM_MAGOS // Para contar el número de magos
};

enum NombreGuerreros {
    CONAN, ACHILLES, LEONIDAS, ARTUR, BEOWULF,
    LAGATHA, RED_SONJA, XENA, ARAGORN,
    BOROMIR, GUTS, THOR, HERCULES, KRATOS,
    BRIENNE_OF_TARTH, JAIME_LANNISTER,
    JON_SNOW, MAXIMUS, MULAN, 
    NUM_GUERREROS 
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

std::string chooseNombreGuerreros() {
    int randomIndex = rand() % NUM_GUERREROS;
    switch (randomIndex) {
        case CONAN: return "Conan";
        case ACHILLES: return "Achilles";
        case LEONIDAS: return "Leonidas";
        case ARTUR: return "Artur";
        case BEOWULF: return "Beowulf";
        case LAGATHA: return "Lagatha";
        case RED_SONJA: return "Red Sonja";
        case XENA: return "Xena";
        case ARAGORN: return "Aragorn";
        case BOROMIR: return "Boromir";
        case GUTS: return "Guts";
        case THOR: return "Thor";
        case HERCULES: return "Hercules";
        case KRATOS: return "Kratos";
        case BRIENNE_OF_TARTH: return "Brienne of Tarth";
        case JAIME_LANNISTER: return "Jaime Lannister";
        case JON_SNOW: return "Jon Snow";
        case MAXIMUS: return "Maximus";
        case MULAN: return "Mulan";
        default: return "Guerrero Desconocido";
    }
}

void PersonajeFactory::inicializarSemilla(){
    static bool semillaInicializada = false;
    if (semillaInicializada) {
        return; // La semilla ya fue inicializada, no hacemos nada
    }
    semillaInicializada = true;
    srand(time(nullptr));
}
int PersonajeFactory::generarNumerosRandom(int limInf, int limSup){
    return (rand() % (limSup - limInf + 1) ) + limInf;  //limSup - limInf para mover el rango. Lim inf,
                                                        //afuera sumando porq es el min valor que queremos que tome
}
shared_ptr<Magos> PersonajeFactory::crearMago(){
    int tipoMago = generarNumerosRandom(0,3); // Tipo de mago, hechicero, conjurador, nigromante o brujo
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
        armaActual = armas[0]; // Asignar la primera como arma actual, después se puede cambiar
    } else {
        armaActual = nullptr;
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
    int tipoGuerrero = generarNumerosRandom(0,4); // Tipo de guerrero, caballero, barbaro, paladin, gladiador o mercenario
    string nombre = chooseNombreGuerreros();
    int hp = rand() % 75 + 95; // HP entre 95 y 170
    vector<shared_ptr<Arma>> armas;
    int numArmas = generarNumerosRandom(0, 2);
    for (int i = 0; i < numArmas; ++i) {
        bool armaCombate = rand() % 2; 
        if (armaCombate) {
            armas.push_back(crearArmaDeCombate());
        } else {
            armas.push_back(crearItemMagico());
        }
    }
    shared_ptr<Arma> armaActual;
    if (!armas.empty()) {
        int randIndex = rand() % armas.size();
        armaActual = armas[randIndex];
    } else {
        armaActual = nullptr; 
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
    cout << "Se crearon " << numMagos << " magos" << endl;
    for (int i = 0; i < numMagos; ++i) {
        personajes.push_back(crearMago()); // Crear entre 3 y 7 magos, con entre 0 y 2 armas
    }
    cout << "Se crearon " << numGuerreros << " guerreros" << endl;
    for (int i = 0; i < numGuerreros; ++i) {
        personajes.push_back(crearGuerrero()); // Crear entre 3 y 7 guerreros, con entre 0 y 2 armas
    }
    return personajes;
}