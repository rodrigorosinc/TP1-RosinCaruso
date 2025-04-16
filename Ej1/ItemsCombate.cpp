#include "ItemsCombate.hpp"

using namespace std;

ArmaCombate::ArmaCombate(string arma_, int damage_, int sharpness_, int letalidad_, string tipo_)
: letalidad(letalidad_), damage(damage_), sharpness(sharpness_), 
  arma(arma_), tipo(tipo_) {}
ArmaCombate::~ArmaCombate() = default;

int ArmaCombate::calcularDamTotal() const {
    return calcularDamage() + calcularAddedDamage();
}
int ArmaCombate::damAtaqueRapido() const {
    return 10 + calcularDamTotal();
}
int ArmaCombate::damAtaqueFuerte() const {
    return 10 + calcularDamTotal();
}
int ArmaCombate::damDefensaYGolpe() const {
    return 10 + calcularDamTotal();
}
string ArmaCombate::getNombreItem() const {
    return arma;
}
int ArmaCombate::getDamTotal() const {
    return calcularDamTotal();
}
int ArmaCombate::getDamage() const {
    return damage;
}
string ArmaCombate::getTipo() const {
    return tipo;
}
bool ArmaCombate::isMaldito() const {
    return maldita;
}
void ArmaCombate::setDamage(int myDamage) {
    damage = myDamage;
}
void ArmaCombate::setMaldito(bool maldecir) {
    maldita = maldecir;
}

// ==================== HachaSimple =================================================================

HachaSimple::HachaSimple()
    : ArmaCombate("Hacha Simple", 10, 5, 2, "Arma Combate") {
        int randomMaterial = rand() % 4;
        switch (randomMaterial) {
            case 0:
                material = "Madera";
                longitudHoja = 3;
                peso = 5;
                legendaria = false;
                break;
            case 1:
                material = "Hierro";
                longitudHoja = 4;
                peso = 6;
                legendaria = false;
                break;
            case 2:
                material = "Acero";
                longitudHoja = 5;
                peso = 7;
                legendaria = false;
                break;
            case 3:
                material = "Oro";
                longitudHoja = 6;
                peso = 5;
                legendaria = true;
                addedDamage = 10;
                return;
        }
        addedDamage = rand() % 4 + 1;
        quebrada = false;
        legendaria = rand() % 3 == 0;
        maldita = rand() % 3 == 0;             
    }

HachaSimple::~HachaSimple() = default;

int HachaSimple::calcularDamage() const {
    int damTotal = damage;
    if (quebrada) {
        damTotal -= 8;
    }
    return damTotal;    
}
int HachaSimple::calcularAddedDamage() const {
    int addDamTotal = addedDamage;
    if (quebrada) {
        addDamTotal -= 3;
    }
    addDamTotal += (letalidad*sharpness)/peso + damage/longitudHoja;
    return addDamTotal;
}
void HachaSimple::restaurar() {
    quebrada = false;
    addedDamage -= 4;
}
void HachaSimple::afilar() {
    if (quebrada) {
        return;
    }
    addedDamage += longitudHoja/peso;
    if (longitudHoja >= 1){
        longitudHoja--;
    }
}
void HachaSimple::rehacer() {
    int randomMaterial = rand() % 3;
    switch (randomMaterial) {
        case 0:
            material = "Madera";
            longitudHoja = 3;
            peso = 5;
            legendaria = false;
            break;
        case 1:
            material = "Hierro";
            longitudHoja = 4;
            peso = 6;
            legendaria = false;
            break;
        case 2:
            material = "Acero";
            longitudHoja = 5;
            peso = 7;
            legendaria = false;
            break;
    }
}

// ==================== HachaDoble ==================================================================

HachaDoble::HachaDoble() : 
    ArmaCombate("Hacha Doble", 11, 2, 5, "Arma Combate") {
    int randomMaterial = rand() % 4;
    switch (randomMaterial) {
        case 0:
            material = "Madera";
            addSharpness = 3;
            anchoMango = 5;
            tieneLanza = false;
            break;
        case 1:
            material = "Hierro";
            addSharpness = 4;
            anchoMango = 6;
            tieneLanza = false;
            break;
        case 2:
            material = "Acero";
            addSharpness = 5;
            anchoMango = 7;
            tieneLanza = true;
            break;
        case 3:
            material = "Oro";
            addSharpness = 6;
            anchoMango = 5;
            tieneLanza = true;
            break;
    }
    int randomQuebrada = rand() % 6;
    if (randomQuebrada == 0) {
        quebrada = true;
    } else {
        quebrada = false;
    }
    legendaria = rand() % 3 == 0;
    maldita = rand() % 3 == 0;
}
HachaDoble::~HachaDoble() = default;

int HachaDoble::calcularDamage() const {
    int damTotal = damage;
    if (quebrada) {
        damTotal -= 8;
    }
    if (tieneLanza) {
        damTotal += 2;
    }
    return damTotal;    
}
int HachaDoble::calcularAddedDamage() const {
    int addDamTotal = addSharpness;
    if (quebrada) {
        addDamTotal -= 3;
    }
    addDamTotal += (letalidad*sharpness)/anchoMango + damage/addSharpness;
    return addDamTotal;
}
void HachaDoble::afilar() {
    if (quebrada) {
        return;
    }
    addSharpness += 1 + (anchoMango/2);
    if (anchoMango >= 1){
        anchoMango--;
    }
}
void HachaDoble::pulir() {
    quebrada = false;
    addSharpness -= 2;
    if (addSharpness < 0) {
        addSharpness = 0;
    }
    if (anchoMango >= 1){
        anchoMango--;
    }
}
void HachaDoble::lanzar(shared_ptr<Personaje> enemigo) {
    if (tieneLanza) {
        enemigo->setHP(enemigo->getHP() - calcularDamage());
        quebrada = true;
        cout << "El hacha doble ha sido lanzada!" << endl;
    }
}

// ==================== Espada ==================================================================

enum MaterialEspada {
    HIERRO,
    ACERO,
    ORO,
    DIAMANTE
};

Espada::Espada() : ArmaCombate("Espada", 12, 5, 2, "Arma Combate") {
    int randomMaterial = rand() % 4;
    switch (randomMaterial) {
        case HIERRO:
            material = "Hierro";
            longitudHoja = 4;
            peso = 6;
            doblada = false;
            addLetalidad = 1;
            aura = 0;
            break;
        case ACERO:
            material = "Acero";
            longitudHoja = 5;
            peso = 7;
            doblada = false;
            addLetalidad = 2;
            aura = 8;
            break;
        case ORO:
            material = "Oro";
            longitudHoja = 6;
            peso = 5;
            addLetalidad = 5;
            doblada = false;
            aura = 20;
            break;
        case DIAMANTE:
            material = "Diamante";
            longitudHoja = 7;
            addLetalidad = 10;
            peso = 4;
            doblada = false;
            aura = 50;
            break;
    }
    int randomDoblada = rand() % 7;
    if (randomDoblada == 0) {
        doblada = true;
    } else {
        doblada = false;
    }
    legendaria = rand() % 3 == 0;
    maldita = rand() % 3 == 0;
}
Espada::~Espada() = default;

int Espada::calcularDamage() const {
    int damTotal = damage;
    if (doblada) {
        damTotal -= 9;
    }
    return damTotal;    
}
int Espada::calcularAddedDamage() const {
    int addDamTotal = addLetalidad;
    if (doblada) {
        addDamTotal -= 3;
    }
    addDamTotal += (letalidad*sharpness)/peso + damage/longitudHoja;
    return addDamTotal;
}
void Espada::relucir() {
    if (doblada) {
        return;
    }
    addLetalidad += 2 + (longitudHoja/peso);
    longitudHoja--;
}
void Espada::desdoblar() {
    doblada = false;
    addLetalidad -= 2;
    if (addLetalidad < 1) {
        addLetalidad = 1;
    }
    longitudHoja--;
    if (longitudHoja < 1) {
        longitudHoja = 1;
    }
}
void Espada::canjearAura(shared_ptr<Personaje> enemigo) {
    if (aura > 0) {
        enemigo->setHP(enemigo->getHP() - aura);
        aura = 0;
        cout << "Se ha canjeado el aura!" << endl;
    }
}

// ==================== Lanza ===========================================================

Lanza::Lanza() : 
    ArmaCombate("Lanza", 7, 3, 3, "Arma Combate") {
    int random = rand() % 3;
    if (random == 0){
        envenenada = true;
    } else {
        envenenada = false;
    }
    random = rand() % 6;
    if (random == 5){
        headshot = true;
    } else {
        headshot = false;
    }
    longitud = 7;
    peso = 3;
    addletalidad = 2;
}
Lanza::~Lanza() = default;

int Lanza::calcularDamage() const {
    int damTotal = damage;
    if (headshot) {
        damTotal += 5;
    }
    return damTotal;    
}
int Lanza::calcularAddedDamage() const {
    int addDamTotal = addletalidad;
    if (envenenada) {
        addDamTotal += 3;
    }
    addDamTotal += (letalidad*sharpness)/peso + damage/longitud;
    return addDamTotal;
}
void Lanza::lanzar(shared_ptr<Personaje> enemigo) {
    if (envenenada) {
        enemigo->setHP(enemigo->getHP() - calcularDamage());
        cout << "La lanza ha sido lanzada!" << endl;
    }
}
void Lanza::envenenar() {
    envenenada = true;
    addletalidad += 2;
}
void Lanza::deshacerEnvenenamiento() {
    envenenada = false;
    addletalidad -= 2;
    if (addletalidad < 1) {
        addletalidad = 1;
    }
}

// ==================== Garrote =================================================================

Garrote::Garrote() : ArmaCombate("Garrote", 8, 4, 4, "Arma Combate") {
    int random = rand() % 3;
    if (random == 0){
        envenenada = true;
    } else {
        envenenada = false;
    }
    cantidadPinchos = 9;
    peso = 7;
    addletalidad = 2;
    largoPinchos = 3;
    legendaria = rand() % 3 == 0;
    maldita = rand() % 3 == 0;
}
Garrote::~Garrote() = default;

int Garrote::calcularDamage() const {
    int damTotal = damage;
    if (envenenada) {
        damTotal += 3;
    }
    return damTotal;    
}
int Garrote::calcularAddedDamage() const {
    int addDamTotal = addletalidad;
    if (envenenada) {
        addDamTotal += 3;
    }
    addDamTotal += (cantidadPinchos*largoPinchos)/peso + damage/cantidadPinchos;
    return addDamTotal;
}
void Garrote::addPinchos(int cantidad) {
    cantidadPinchos += cantidad;
}
void Garrote::envenenar() {
    envenenada = true;
    addletalidad += 2;
}
void Garrote::envenenarPinchos() {
    envenenada = true;
    addletalidad += 2;
}