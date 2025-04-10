#include "ItemsMagicos.hpp"
#include "ItemsCombate.hpp"
#include "Personajes.hpp"

enum NombreCreador {
    RAGNAR_LOTHBROK, //mistico
    GANDALF, 
    PEDRO, // mistico
    DR_STRANGE 
};

string asignarNombreCreador(ItemMagico& item) {
    // Asigno creador al azar
    srand(time(0)); // Inicializar la semilla del generador de números aleatorios
    int random = rand() % 4;  
    string nombreCreador;
    switch (random) {
        case 0:
            nombreCreador = "Ragnar Lothbrok";
            item.setMistico(true);
            break;
        case 1:
            nombreCreador = "Gandalf";
            break;
        case 2:
            nombreCreador = "Pedro";
            item.setMistico(true);
            break;
        case 3:
            nombreCreador = "Dr. Strange";
            break;
    }
    return nombreCreador;
}

bool asignarMaldecido(ItemMagico& item) {
    // Asigno maldición al azar
    srand(time(0)); // Inicializar la semilla del generador de números aleatorios
    int random = rand() % 5;  
    if (random == 0) {
        item.maldicir();
        return true;
    }
    return false; 
}  

ItemMagico::~ItemMagico() = default;

ItemMagico::ItemMagico(int damage, int critico, int poderMagico,
    bool consumible, string nombreCreador)
    : damage(damage), critico(critico), poderMagico(poderMagico),
    consumible(consumible), mistico(false), maldecido(asignarMaldecido(*this)),
    nombreCreador(asignarNombreCreador(*this)) {}


int ItemMagico::getDamage() const {
    return damage;
}
bool ItemMagico::isMaldecido() const {
    return maldecido;
}
void ItemMagico::maldicir() {
    maldecido = true;
}
string ItemMagico::getCreador() const {
    return nombreCreador;
}
void ItemMagico::setMistico(bool mistico) {
    this->mistico = mistico;
}
bool ItemMagico::isMistico() const {
    return mistico;
}
bool ItemMagico::isConsumible() const {
    return consumible;
}
bool ItemMagico::isMaldecido() const {
    return maldecido;
}
tipoAtaque ItemMagico::getAtaque() const {
    return tAtaque;
}
void ItemMagico::setAtaque(tipoAtaque tipoAtaque) {
    this->tAtaque = tipoAtaque;
}
void ItemMagico::setDamage(int dam) {
    this->damage = dam;
}
string ItemMagico::getArma() const {
    return arma;
}
int ItemMagico::calcularDamTotal() const {
    return hacerDamCritico() + ataqueMistico();
}

int ItemMagico::damAtaqueRapido(bool special) const {
    return 10 + calcularDamTotal();
}
int ItemMagico::damAtaqueFuerte(bool special) const {
    return 10 + calcularDamTotal();
}
int ItemMagico::damDefensaYGolpe(bool special) const {
    return 10 + calcularDamTotal();
}

// ====================== BASTON ==========================

enum Elemento {
    ABETO,
    ROBLE,
    METAL
};

string asignarElemento(Baston& baston) {
    // Asigno elemento al azar
    srand(time(0)); // Inicializar la semilla del generador de números aleatorios
    int random = rand() % 3;  
    string element;
    switch (random) {
        case 0:
            element = "Abeto";
            baston.setDamage(baston.getDamage() + 2);
            break;
        case 1:
            element = "Roble";
            baston.setDamage(baston.getDamage() + 3);
            break;
        case 2:
            element = "Metal";
            baston.setDamage(baston.getDamage() + 5);
            break;
    }
    return element;
}
Baston::Baston()
    : ItemMagico(10, 5, 0, false, asignarNombreCreador(*this)),
      element(asignarElemento(*this)) {}

void Baston::consumir(Personaje& personaje) {
    cout << "El baston no se puede consumir." << endl;
}
void Baston::desMaldicir(Personaje& personaje) {
    // poner que depende quien sea se puede desmaldecir o no
}
int Baston::hacerDamCritico() const {
    srand(time(0)); // Inicializar la semilla del generador de números aleatorios
    int random = rand() % 100;
    int critChance = critico + poderMagico/5;
    if (random < critChance) {
        return damage * 2;
    }
    return damage;
}
int Baston::ataqueMistico() const {
   if (mistico) {
        return 20;
    }
    return 0;
}

Baston::~Baston() = default;

// ====================== LIBRO DE HECHIZOS ==========================
