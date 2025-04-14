#include "PersonajesGuerreros.hpp"
#include "ItemsCombate.hpp"
#include "ItemsMagicos.hpp"

using namespace std;

Guerreros::Guerreros(string myNombre, int myHp, vector<shared_ptr<Arma>> myArmas, shared_ptr<Arma> myArmaActual)
    : nombre(myNombre), hp(myHp), armas(myArmas), armaActual(myArmaActual), tipo("Guerrero") {}
Guerreros::~Guerreros() = default;

void damagePorTurno(Personaje& personaje, shared_ptr<Personaje> enemigo, int damage) {
    if (!enemigo) {
        cerr << "Error: Enemigo no válido." << endl;
        return;
    }

    if (personaje.getTurno()) {
        cout << personaje.getNombre() << " ataca a " << enemigo->getNombre() << " con " 
             << personaje.getArmaActual()->getNombreItem() << endl;
        cout << "Daño infligido: " << damage << endl;
    } else {
        cout << enemigo->getNombre() << " te ha atacado!" << endl;
    }

    int nuevoHP = enemigo->getHP() - damage;
    cout << "HP reducido a: " << nuevoHP << endl;
    enemigo->setHP(nuevoHP);  // Solo se resta el daño una vez
}


void Guerreros::ataqueRapido(shared_ptr<Personaje> enemigo) {
    if (!enemigo) {
        cerr << "Error: Enemigo no válido." << endl;
        return;
    }

    if (!armaActual) {
        cout << "No tienes arma equipada" << endl;
        cout << "Haces 10 de daño a " << enemigo->getNombre() << endl;
        enemigo->setHP(enemigo->getHP() - 10);
        return;
    }

    int damage = armaActual->damAtaqueRapido();
    if (armaActual->getTipo() == "Arma Combate") {
        damage += damage / 3;
    }
    if (this->isLegendario()) {
        damage += damage / 2 + fuerzaDelRey / 3;
    }
    damagePorTurno(*this, enemigo, damage);
    cout << "---------------------------------------------" << endl;
}

void Guerreros::ataqueFuerte(shared_ptr<Personaje> enemigo) {
    if (!enemigo) {
        cerr << "Error: Enemigo no válido." << endl;
        return;
    }

    if (!armaActual) {
        cout << "No tienes arma equipada" << endl;
        cout << "Haces 10 de daño a " << enemigo->getNombre() << endl;
        enemigo->setHP(enemigo->getHP() - 10);
        return;
    }

    int damage = armaActual->damAtaqueFuerte();
    if (armaActual->getTipo() == "Arma Combate") {
        damage += damage / 3;
    }
    if (this->isLegendario()) {
        damage += damage / 2 + fuerzaDelRey / 3;
    }
    damagePorTurno(*this, enemigo, damage);
    cout << "---------------------------------------------" << endl;
}

void Guerreros::defensaYGolpe(shared_ptr<Personaje> enemigo) {
    if (!enemigo) {
        cerr << "Error: Enemigo no válido." << endl;
        return;
    }
    if (!armaActual) {
        cout << "No tienes arma equipada" << endl;
        cout << "Haces 10 de daño a " << enemigo->getNombre() << endl;
        enemigo->setHP(enemigo->getHP() - 10);
        return;
    }
    int damage = armaActual->damDefensaYGolpe();
    if (armaActual->getTipo() == "Arma Combate") {
        damage += damage / 3;
    }
    if (this->isLegendario()) {
        damage += damage / 2 + fuerzaDelRey / 3;
    }
    damagePorTurno(*this, enemigo, damage);
    cout << "---------------------------------------------" << endl;
}
void Guerreros::setHP(int newHp) {
    hp = newHp;
}
int Guerreros::getHP() const {
    return hp;
}
vector<shared_ptr<Arma>> Guerreros::getArmas() const {
    return armas;
}
string Guerreros::getNombre() const {
    return nombre;
}
string Guerreros::getTipo() const {
    return tipo;
}
int Guerreros::getFuerzaDelRey() const {
    return fuerzaDelRey;
}
void Guerreros::setFuerzaDelRey(int newFDR) {
    fuerzaDelRey = newFDR;
}
void Guerreros::setTurno(bool turno) {
    miTurno = turno;
}
void Guerreros::setArmaActual(shared_ptr<Arma> arma) {
    armaActual = arma;
}
bool Guerreros::isLegendario() const {
    return legendario;
}   
void Guerreros::setLegendario(bool makeLegendario) {
    legendario = makeLegendario;
}
void Guerreros::removerArma(int index) {
    if (index >= 0 && index < (int) armas.size()) {
        armas.erase(armas.begin() + index);
    } else {
        cout << "Index out of range" << endl;
    }
}
bool Guerreros::getTurno() const {
    return miTurno;
}
shared_ptr<Arma> Guerreros::getArmaActual() const {
    return armaActual;
}



// ======================= Barbaro ========================

Barbaro::Barbaro(string nombre, int hp, vector<shared_ptr<Arma>> armas, shared_ptr<Arma> armaActual)
    : Guerreros(nombre, hp, armas, armaActual) {
        int randomNum = rand(); 
        peso = randomNum % 100 + 1;
        fuerza = randomNum % 100;
        resistencia = randomNum % 100 + 1;
        lider = randomNum % 5 == 0;
        berserker = randomNum % 7 == 0;
        fuerzaDelRey = 11;
        int randomNum2 = rand();
        if (randomNum2 % 5 == 0) {
            setLegendario(true);
        } else {
            setLegendario(false);
        }
}
Barbaro::~Barbaro() = default;
void Barbaro::gritar(shared_ptr<Personaje> enemigo) {
    if (lider) {
        cout << "AAAAAAAAAAAAAAAAAAAAAAAA!!!!!!" << endl;
        enemigo->setHP(enemigo->getHP() - 10);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No eres lider" << endl;
    }
}

void Barbaro::embestir(shared_ptr<Personaje> enemigo) {
    if (peso > 50) {
        cout << "Embestiendo enemigo" << endl;
        enemigo->setHP(enemigo->getHP() - 20);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes suficiente peso" << endl;
    }
}
void Barbaro::gritarFuria(shared_ptr<Personaje> enemigo) {
    if (berserker) {
        cout << "AAAAAAAAAAAAAAAAAAAAAAAA!!!!!!" << endl;
        enemigo->setHP(enemigo->getHP() - 30);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No eres berserker" << endl;
    }
}
void Barbaro::resistir() {
    setHP(getHP() + resistencia/2);
    cout << "Nuevo HP: " << getHP() << endl;
}
void Barbaro::poderBerserker(shared_ptr<Personaje> enemigo) {
    if (berserker) {
        cout << "Usando poder berserker" << endl;
        berserker = false;
        enemigo->setHP(enemigo->getHP() - 50);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No eres berserker" << endl;
    }
}

// ======================== Paladin ========================

Paladin::Paladin(string nombre, int hp, vector<shared_ptr<Arma>> armas, shared_ptr<Arma> armaActual)
    : Guerreros(nombre, hp, armas, armaActual) {
        int randomNum = rand();
        espadaDeLaVerdad = true;
        yelmoDeLaEsperanza = randomNum % 2 == 0;
        inteligencia = randomNum % 100+1;
        nivelDeFe = randomNum % 100+1;
        justicia = 60;
        fuerzaDelRey = 13;
        int randomNum2 = rand();
        if (randomNum2 % 5 == 0) {
            setLegendario(true);
        } else {
            setLegendario(false);
        }
}
Paladin::~Paladin() = default;
void Paladin::espadazo(shared_ptr<Personaje> enemigo) {
    if (espadaDeLaVerdad) {
        cout << "Usando espada de la verdad" << endl;
        enemigo->setHP(enemigo->getHP() - 30);
        espadaDeLaVerdad = false;
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes espada de la verdad" << endl;
    }
}
void Paladin::ponerYelmo() {
    if (yelmoDeLaEsperanza) {
        cout << "Usando yelmo de la esperanza" << endl;
        yelmoDeLaEsperanza = false;
        setHP(getHP() + 35 + inteligencia/2);
        cout << "Nuevo HP: " << getHP() << endl;
    } else {
        cout << "No tienes yelmo de la esperanza" << endl;
    }
}
void Paladin::ajusticiar(shared_ptr<Personaje> enemigo) {
    if (justicia > 50) {
        cout << "Ajusticiando enemigo" << endl;
        enemigo->setHP(enemigo->getHP() - 20 - nivelDeFe/2);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes suficiente justicia" << endl;
    }
}
void Paladin::fe() {
    setHP(getHP() + nivelDeFe/2);
    cout << "Nuevo HP: " << getHP() << endl;
}
void Paladin::poderDivino(shared_ptr<Personaje> enemigo) {
    if (nivelDeFe > 50) {
        cout << "Usando poder divino" << endl;
        nivelDeFe = 0;
        enemigo->setHP(enemigo->getHP() - 20 - nivelDeFe/2 - inteligencia/2);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes suficiente nivel de fe" << endl;
    }
}

// ======================== Caballero ========================

enum Unidad {
    UNIDAD_DE_FUEGO = 1,
    UNIDAD_DE_AGUA,
    UNIDAD_DE_TIERRA,
    UNIDAD_DE_AIRE
};

Caballero::Caballero(string nombre, int hp, vector<shared_ptr<Arma>> armas, shared_ptr<Arma> armaActual)
    : Guerreros(nombre, hp, armas, armaActual) {
        int randomNum = rand();
        switch (randomNum % 4) {
        case UNIDAD_DE_FUEGO:
            unidad = "Fuego";
            break;
        case UNIDAD_DE_AGUA:
            unidad = "Agua";
            break;
        case UNIDAD_DE_TIERRA:
            unidad = "Tierra";
            break;
        case UNIDAD_DE_AIRE:
            unidad = "Aire";
            break;
        }
        armaduraDeHierro = randomNum % 2 == 0;
        escudoTemplario = randomNum % 2 == 0;
        fuerza = randomNum % 100 + 1;
        curacion = randomNum % 35 + 10;
        fuerzaDelRey = 15;
        int randomNum2 = rand();
        if (randomNum2 % 5 == 0) {
            setLegendario(true);
        } else {
            setLegendario(false);
        }
}
Caballero::~Caballero() = default;

void Caballero::curarse() {
    if (curacion > 0) {
        cout << "Usando curacion" << endl;
        setHP(getHP() + curacion);
        curacion = 0;
        cout << "Nuevo HP: " << getHP() << endl;
    } else {
        cout << "No tienes curacion" << endl;
    }
}
void Caballero::usarArmadura() {
    if (armaduraDeHierro) {
        cout << "Usando armadura de hierro" << endl;
        armaduraDeHierro = false;
        setHP(getHP() + 40);
        cout << "Nuevo HP: " << getHP() << endl;
    } else {
        cout << "No tienes armadura de hierro" << endl;
    }
}
void Caballero::usarEscudo() {
    if (escudoTemplario) {
        cout << "Usando escudo templario" << endl;
        escudoTemplario = false;
        setHP(getHP() + 20);
        cout << "Nuevo HP: " << getHP() << endl;
    } else {
        cout << "No tienes escudo templario" << endl;
    }
}
void Caballero::ataqueEspecial(shared_ptr<Personaje> enemigo) {
    if (unidad == "Fuego") {
        cout << "Usando ataque especial de fuego" << endl;
        enemigo->setHP(enemigo->getHP() - 12 - fuerza/2);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else if (unidad == "Agua") {
        cout << "Usando ataque especial de agua" << endl;
        enemigo->setHP(enemigo->getHP() - 13 - fuerza/2);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else if (unidad == "Tierra") {
        cout << "Usando ataque especial de tierra" << endl;
        enemigo->setHP(enemigo->getHP() - 11 - fuerza/2);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else if (unidad == "Aire") {
        cout << "Usando ataque especial de aire" << endl;
        enemigo->setHP(enemigo->getHP() - 12 - fuerza/2);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    }
}
void Caballero::cambiarUnidad(string nuevaUnidad) {
    unidad = nuevaUnidad;
    cout << "Unidad cambiada a: " << unidad << endl;
}

// ======================== Mercenario ========================

Mercenario::Mercenario(string nombre, int hp, vector<shared_ptr<Arma>> armas, shared_ptr<Arma> armaActual)
    : Guerreros(nombre, hp, armas, armaActual) {
        int randomNum = rand();
        fuerzaDelRey = 15;
        inteligencia = randomNum % 100 + 1;
        apetitoDeDinero = randomNum % 100 + 1;
        vengador = randomNum % 2 == 0;
        justiciero = randomNum % 2 == 0;
        jinete = randomNum % 2 == 0;
        int randomNum2 = rand();
        if (randomNum2 % 5 == 0) {
            setLegendario(true);
        } else {
            setLegendario(false);
        }
}
Mercenario::~Mercenario() = default;

void Mercenario::robar(shared_ptr<Personaje> enemigo) {
    if (apetitoDeDinero > 50) {
        cout << "Robando enemigo" << endl;
        auto armas = enemigo->getArmas();
        if (!armas.empty()) {
            int randomIndex = rand() % (int)armas.size();
            shared_ptr<Arma> armaRobada = armas[randomIndex];
            cout << "Robando arma: " << armaRobada->getNombreItem() << endl;
            enemigo->removerArma(randomIndex);
            setArmaActual(armaRobada);
            cout << "Arma robada: " << armaRobada->getNombreItem() << endl;
        } else {
            cout << "No hay armas para robar" << endl;
            enemigo->setHP(enemigo->getHP() - 10);
        }
    } else {
        cout << "No tienes suficiente avaricia" << endl;
    }
}
void Mercenario::atacarPorDinero(shared_ptr<Personaje> enemigo) {
    if (apetitoDeDinero > 50) {
        cout << "Atacando por dinero" << endl;
        enemigo->setHP(enemigo->getHP() - 9);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes suficiente avaricia" << endl;
    }
}
void Mercenario::atacarPorJusticia(shared_ptr<Personaje> enemigo) {
    if (justiciero) {
        cout << "Atacando por justicia" << endl;
        enemigo->setHP(enemigo->getHP() - 11);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No eres justiciero" << endl;
    }
}
void Mercenario::atacarPorVenganza(shared_ptr<Personaje> enemigo) {
    if (vengador) {
        cout << "Atacando por venganza" << endl;
        enemigo->setHP(enemigo->getHP() - 21);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No eres vengador" << endl;
    }
}
void Mercenario::montarJinete() {
    if (jinete) {
        cout << "Montando jinete" << endl;
        jinete = false;
        setHP(getHP() + 20);
        cout << "Nuevo HP: " << getHP() << endl;
    } else {
        cout << "No eres jinete" << endl;
    }
}

// ======================== Gladiador ========================

Gladiador::Gladiador(string nombre, int hp, vector<shared_ptr<Arma>> armas, shared_ptr<Arma> armaActual)
    : Guerreros(nombre, hp, armas, armaActual) {
        int randomNum = rand();
        fuerzaDelRey = 20;
        espartano = randomNum % 2 == 0;
        fuerzaEspartana = randomNum % 100 + 1;
        resistenciaEspartana = randomNum % 100 + 1;
        sangreEspartana = randomNum % 2 == 0;
        voluntadEspartana = randomNum % 2 == 0;
        int randomNum2 = rand();
        if (randomNum2 % 5 == 0) {
            setLegendario(true);
        } else {
            setLegendario(false);
        }
}
Gladiador::~Gladiador() = default;
void Gladiador::gritar(shared_ptr<Personaje> enemigo) {
    if (espartano) {
        cout << "ESPARTANOOOS AUU AUU AUUUUU!!!!!!" << endl;
        enemigo->setHP(enemigo->getHP() - 9 - fuerzaEspartana/2);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No eres espartano" << endl;
    }
}
void Gladiador::chocarCabeza(shared_ptr<Personaje> enemigo) {
    if (sangreEspartana) {
        cout << "Chocando cabeza" << endl;
        enemigo->setHP(enemigo->getHP() - 20 - resistenciaEspartana/2);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes sangre espartana" << endl;
    }
}
void Gladiador::cerrarHerida() {
    if (voluntadEspartana) {
        cout << "Cerrando herida" << endl;
        setHP(getHP() + 30);
        if (sangreEspartana) {
            setHP(getHP() + 20);
        }
        cout << "Nuevo HP: " << getHP() << endl;
    } else {
        cout << "No tienes voluntad espartana" << endl;
    }
}
void Gladiador::xerxes(shared_ptr<Personaje> enemigo) {
    if (sangreEspartana) {
        cout << "Usando poder Xerxes" << endl;
        enemigo->setHP(enemigo->getHP() - 10 - resistenciaEspartana/2 - fuerzaEspartana/2);
        sangreEspartana = false;
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes sangre espartana" << endl;
    }
}
void Gladiador::pasarPorElFuego(shared_ptr<Personaje> enemigo) {
    if (voluntadEspartana && sangreEspartana && espartano) {
        cout << "Pasando por el fuego" << endl;
        enemigo->setHP(enemigo->getHP() - 30 - resistenciaEspartana/2);
        voluntadEspartana = false;
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes voluntad espartana" << endl;
    }
}

