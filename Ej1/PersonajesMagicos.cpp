#include "PersonajesMagicos.hpp"
#include "ItemsMagicos.hpp"
#include "ItemsCombate.hpp"

using namespace std;

Magos::Magos(string myNombre, int myHp, vector<shared_ptr<Arma>> myArmas, shared_ptr<Arma> myArmaActual)
    : tipo("Mago"), nombre(myNombre), hp(myHp), armas(myArmas), armaActual(myArmaActual) {}
Magos::~Magos() = default;

void damagePorTurnoMago(Personaje& personaje, shared_ptr<Personaje> enemigo, int damage) {
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
    enemigo->setHP(nuevoHP);
}

void Magos::ataqueRapido(shared_ptr<Personaje> enemigo) {
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
    if (armaActual->getTipo() == "Item Magico") {
        damage += damage/3;
    }
    if (this->isLegendario()) {
        damage += damage/2;
    }
    damagePorTurnoMago(*this, enemigo, damage);
    cout << "---------------------------------------------" << endl;
}
void Magos::ataqueFuerte(shared_ptr<Personaje> enemigo) {
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
    if (armaActual->getTipo() == "Item Magico") {
        damage += damage/3;
    }
    if (this->isLegendario()) {
        damage += damage/2;
    }
    damagePorTurnoMago(*this, enemigo, damage);
    cout << "---------------------------------------------" << endl;
}

void Magos::defensaYGolpe(shared_ptr<Personaje> enemigo) {
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
    if (armaActual->getTipo() == "Item Magico") {
        damage += damage/3;
    }
    if (this->isLegendario()) {
        damage += damage/2;
    }
    damagePorTurnoMago(*this, enemigo, damage);
    cout << "---------------------------------------------" << endl;    
}
void Magos::setHP(int newHp) {
    hp = newHp;
}
int Magos::getHP() const {
    return hp;
}
bool Magos::isLegendario() const {
    return legendario;
}
vector<shared_ptr<Arma>> Magos::getArmas() const {
    return armas;
}
string Magos::getTipo() const {
    return tipo;
}
void Magos::setArmaActual(shared_ptr<Arma> arma) {
    armaActual = arma;
}
void Magos::setMana(int newMana) {
    mana = newMana;
}
void Magos::setTurno(bool turno) {
    miTurno = turno;
}
string Magos::getNombre() const {
    return nombre;
}
int Magos::getMana() const {
    return mana;
}
void Magos::setLegendario(bool makeLegendario) {
    legendario = makeLegendario;
}
void Magos::removerArma(int index) {
    if (index >= 0 && index < (int) armas.size()) {
        armas.erase(armas.begin() + index);
    } else {
        cout << "Index out of range" << endl;
    }
}
shared_ptr<Arma> Magos::getArmaActual() const {
    return armaActual;
}
bool Magos::getTurno() const {
    return miTurno;
}

// ======================== Hechicero ========================

Hechicero::Hechicero(string myNombre, int myHp, vector<shared_ptr<Arma>> myArmas, shared_ptr<Arma> myArmaActual)
    : Magos(myNombre, myHp, myArmas, myArmaActual) {
        int randomNum = rand();
        tienePocionEscudo = randomNum % 2 == 0;
        tienePocionRecuperacion = randomNum % 2 == 0;
        tienePocionMana = randomNum % 2 == 0;
        tienePocionFuria = randomNum % 2 == 0;
        tienePocionX2 = randomNum % 2 == 0;
        mana = 100;
        int randomNum2 = rand();
        legendario = randomNum2 % 10 == 0;
        miTurno = false;
}
Hechicero::~Hechicero() = default;

void Hechicero::pocionEscudo() {
    if (tienePocionEscudo) {
        cout << "Usando pocion de escudo" << endl;
        tienePocionEscudo = false;
        setHP(getHP() + 30 + getHP()*3/mana);
        cout << "HP aumentado a: " << getHP() << endl;
        cout << "Pocion de escudo usada" << endl;
    } else {
        cout << "No tienes pocion de escudo" << endl;
    }
}
void Hechicero::pocionRecuperacion() {
    if (tienePocionRecuperacion) {
        cout << "Usando pocion de recuperacion" << endl;
        tienePocionRecuperacion = false;
        setHP(getHP() + 32 + getHP()*3/mana);
        cout << "HP aumentado a: " << getHP() << endl;
        cout << "Pocion de recuperacion usada" << endl;
    } else {
        cout << "No tienes pocion de recuperacion" << endl;
    }
}
void Hechicero::pocionMana() {
    if (tienePocionMana) {
        cout << "Usando pocion de mana" << endl;
        tienePocionMana = false;
        setMana(getMana() + 30);
        cout << "HP aumentado a: " << getHP() << endl;
        cout << "Pocion de mana usada" << endl;
    } else {
        cout << "No tienes pocion de mana" << endl;
    }
}
void Hechicero::pocionFuria() {
    if (tienePocionFuria) {
        cout << "Usando pocion de furia" << endl;
        tienePocionFuria = false;
        armaActual->setDamage(armaActual->getDamage() + 5);
        cout << "HP aumentado a: " << getHP() << endl;
        cout << "Pocion de furia usada" << endl;
    } else {
        cout << "No tienes pocion de furia" << endl;
    }
}

void Hechicero::pocionX2() {
    if (tienePocionX2) {
        cout << "Usando pocion de x2" << endl;
        tienePocionX2 = false;
        setMana(getMana() + 20);
        setHP(getHP() + 20);
        cout << "HP aumentado a: " << getHP() << endl;
        cout << "Pocion de x2 usada" << endl;
    } else {
        cout << "No tienes pocion de x2" << endl;
    }
}

// ======================== Conjurador ========================

Conjurador::Conjurador(string myNombre, int myHp, vector<shared_ptr<Arma>> myArmas, shared_ptr<Arma> myArmaActual)
    : Magos(myNombre, myHp, myArmas, myArmaActual) {
        int randomNum = rand();
        conjuroOscuro = randomNum % 2 == 0;
        conjuroLuminoso = randomNum % 2 == 0;
        conjuroElemental = randomNum % 2 == 0;
        maldijo = false;
        purificado = false;
        mana = 90;
        int randomNum2 = rand();
        legendario = randomNum2 % 10 == 0;
        miTurno = false;
}
Conjurador::~Conjurador() = default;
void Conjurador::conjurarOscuro(shared_ptr<Personaje> enemigo) {
    if (conjuroOscuro) {
        cout << "Conjurando conjuro oscuro" << endl;
        conjuroOscuro = false;
        enemigo->setHP(enemigo->getHP() - 10 - mana/10);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes conjuro oscuro" << endl;
    }
}
void Conjurador::conjurarLuminoso(shared_ptr<Personaje> enemigo) {
    if (conjuroLuminoso) {
        cout << "Conjurando conjuro luminoso" << endl;
        conjuroLuminoso = false;
        enemigo->setHP(enemigo->getHP() - 9 - mana/10);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes conjuro luminoso" << endl;
    }
}
void Conjurador::conjurarElemental(shared_ptr<Personaje> enemigo) {
    if (conjuroElemental) {
        cout << "Conjurando conjuro elemental" << endl;
        conjuroElemental = false;
        enemigo->setHP(enemigo->getHP() - 20);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes conjuro elemental" << endl;
    }
}
void Conjurador::maldecir(shared_ptr<Personaje> enemigo) {
    if (!maldijo) {
        cout << "Conjurando maldicion" << endl;
        maldijo = true;
        armas = enemigo->getArmas();
        int randomNum = rand() % armas.size();
        shared_ptr<Arma> armaMaldecida = armas[randomNum];
        armaMaldecida->setMaldito(true);        
    } else {
        cout << "Ya has maldecido a un enemigo" << endl;
    }
}

void Conjurador::purificar(shared_ptr<Personaje> enemigo) {
    if (!purificado) {
        cout << "Purificando arma" << endl;
        purificado = true;
        armas = enemigo->getArmas();
        int randomNum = rand() % armas.size();
        shared_ptr<Arma> arma = armas[randomNum];
        if (arma->isMaldito()) {
            arma->setMaldito(false);
            cout << "Arma purificada" << endl;
        } else {
            cout << "El arma no estaba maldecida" << endl;
        }
    } else {
        cout << "Ya has purificado un arma" << endl;
    }
}

// ======================= Brujo ========================

Brujo::Brujo(string myNombre, int myHp, vector<shared_ptr<Arma>> myArmas, shared_ptr<Arma> myArmaActual)
    : Magos(myNombre, myHp, myArmas, myArmaActual) {
        int randomNum = rand();
        embrujado = randomNum % 3 == 0;
        abracadabra = randomNum % 5 == 0;
        metamorfosis = randomNum % 7 == 0;
        hiperMetamorfosis = randomNum % 11 == 0;
        yinYang = randomNum % 13 == 0;
        mana = 110;
        int randomNum2 = rand();
        legendario = randomNum2 % 10 == 0;
        miTurno = false;
}
Brujo::~Brujo() = default;
void Brujo::embrujar(shared_ptr<Personaje> enemigo) {
    if (embrujado) {
        cout << "Embrujando enemigo" << endl;
        embrujado = false;
        enemigo->setHP(enemigo->getHP() - 10 - mana/10);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes embrujo" << endl;
    }
}
void Brujo::hacerAbracadabra(shared_ptr<Personaje> enemigo) {
    if (abracadabra) {
        cout << "Haciendo abracadabra" << endl;
        abracadabra = false;
        enemigo->setHP(enemigo->getHP() - 20 - mana/10);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes abracadabra" << endl;
    }
}
void Brujo::hacerMetamorfosis(shared_ptr<Personaje> enemigo) {
    if (metamorfosis) {
        cout << "Haciendo metamorfosis" << endl;
        metamorfosis = false;
        enemigo->setHP(enemigo->getHP() - 30 - mana/10);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes metamorfosis" << endl;
    }
}
void Brujo::hacerHiperMetamorfosis(shared_ptr<Personaje> enemigo) {
    if (hiperMetamorfosis) {
        cout << "Haciendo hiper metamorfosis" << endl;
        hiperMetamorfosis = false;
        enemigo->setHP(enemigo->getHP() - 40 - mana/10);
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes hiper metamorfosis" << endl;
    }
}
void Brujo::recuperse() {
    if (yinYang) {
        cout << "Recuperando HP" << endl;
        yinYang = false;
        setHP(getHP() + 50 + mana/5);
        cout << "HP aumentado a: " << getHP() << endl;
    } else {
        cout << "No tienes yin yang" << endl;
    }
}

// ==================== Nigromante ===================

Nigromante::Nigromante(string myNombre, int myHp, vector<shared_ptr<Arma>> myArmas, shared_ptr<Arma> myArmaActual)
    : Magos(myNombre, myHp, myArmas, myArmaActual) {
        int randomNum = rand();
        invocoEspectro = randomNum % 2 == 0;
        invocoFantasma = randomNum % 3 == 0;
        invocoZombie = randomNum % 5 == 0;
        invocoEsqueleto = randomNum % 7 == 0;
        invocoVampiro = randomNum % 11 == 0;
        mana = 95;
        int randomNum2 = rand();
        legendario = randomNum2 % 10 == 0;
        miTurno = false;
}
Nigromante::~Nigromante() = default;
void Nigromante::invocarEspectro(shared_ptr<Personaje> enemigo) {
    if (invocoEspectro) {
        cout << "Invocando espectro" << endl;
        invocoEspectro = false;
        enemigo->setHP(enemigo->getHP() - 11 - mana/10);
        cout << "El espectro golpea al enemigo" << endl;
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes espectro" << endl;
    }
}
void Nigromante::invocarFantasma(shared_ptr<Personaje> enemigo) {
    if (invocoFantasma) {
        cout << "Invocando fantasma" << endl;
        invocoFantasma = false;
        enemigo->setHP(enemigo->getHP() - 12 - mana/10);
        cout << "El fantasma golpea al enemigo" << endl;
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes fantasma" << endl;
    }
}
void Nigromante::invocarZombie(shared_ptr<Personaje> enemigo) {
    if (invocoZombie) {
        cout << "Invocando zombie" << endl;
        invocoZombie = false;
        enemigo->setHP(enemigo->getHP() - 13 - mana/10);
        cout << "El zombie golpea al enemigo" << endl;
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes zombie" << endl;
    }
}
void Nigromante::invocarEsqueleto(shared_ptr<Personaje> enemigo) {
    if (invocoEsqueleto) {
        cout << "Invocando esqueleto" << endl;
        invocoEsqueleto = false;
        enemigo->setHP(enemigo->getHP() - 14 - mana/10);
        cout << "El esqueleto golpea al enemigo" << endl;
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes esqueleto" << endl;
    }
}
void Nigromante::invocarVampiro(shared_ptr<Personaje> enemigo) {
    if (invocoVampiro) {
        cout << "Invocando vampiro" << endl;
        invocoVampiro = false;
        enemigo->setHP(enemigo->getHP() - 15 - mana/10);
        cout << "El vampiro golpea al enemigo" << endl;
        cout << "HP enemigo reducido a: " << enemigo->getHP() << endl;
    } else {
        cout << "No tienes vampiro" << endl;
    }
}
