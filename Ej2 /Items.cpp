#include "Items.hpp"
#include "Personajes.hpp"

using namespace std;

Arma::Arma(std::string nombre, int damage, int nivel, 
           int critico, bool ataqueLetal) : 
    nombre(nombre), damage(damage), critico(critico), ataqueLetal(ataqueLetal) {}

Arma::~Arma() {}
int Arma::getCritico() const {
    return critico;
}
int Arma::getDamage() const {
    return damage;
}
void Arma::setCritico(int critico) {
    this->critico = critico;
}
void Arma::setDamage(int damage) {
    this->damage = damage;
}
void Arma::setAtaqueLetal(bool ataqueLetal) {
    this->ataqueLetal = ataqueLetal;
}
void Arma::setNombre(std::string nombre) {
    this->nombre = nombre;
}
std::string Arma::getNombre() {
    return nombre;
}

ItemMagico::ItemMagico(std::string nombre, int damage, int nivel, 
           int critico, bool AtaqueLetal, int poderMagico, bool esConsumible, 
           bool esMistico, std::string nombreCreador, bool cursed) : 
    Arma(nombre, damage, nivel, critico, AtaqueLetal), 
    poderMagico(poderMagico), esConsumible(esConsumible), 
    esMistico(esMistico), nombreCreador(nombreCreador), cursed(cursed) {
        if (nombreCreador == "Miguelangel") {
            setCritico(critico + 10); // bonificación por ser creado por Miguelangel
        } else if (nombreCreador == "Gandalf") {
            setDamage(damage + 10); // bonificación por ser creado por Gandalf
        } else if (nombreCreador == "Pedrito") {
            setAtaqueLetal(true); // bonificación por ser creado por Pedrito
        }
        if (cursed) {
            setDamage(damage - 15); // penalización por maldición
        }
        if (esMistico) {
            setDamage(damage + 20); // bonificación por ser místico
        }
        if (esConsumible) {
            setDamage(0); // se destruye al ser usado
        }
    };

int ItemMagico::calcularDamage(Personaje& personaje) {
    if (!esConsumible){
        int damTotal = sumarDamCritico();
        damTotal = damTotal + poderMagico; // daño base + poder mágico
        return damTotal;
    } else {
        // Si es consumible, se puede usar una vez y luego se destruye
        return 0;
    }
}

int ItemMagico::sumarDamCritico() {
    int critico = getCritico();
    int probCritTotal = critico + poderMagico/4; // bonificación de 10% por ser un item mágico
    if (rand() % 100 < probCritTotal) {
        return damage = damage + damage * 0.5;
    }   
    return damage + 0;
}

void ItemMagico::usarItem(Personaje& personaje) {
    if (esConsumible) {
        if (this->getNombre() == "Amuleto"){
            cout << "El personaje " << personaje.getNombre() << " ha ganado 35 de vida." << endl;
            personaje.setHP(personaje.getHP() + 35);
        } else if (this->getNombre() == "Libro de hechizos"){
            cout << "El personaje " << personaje.getNombre() << " se convierte en legendario." << endl;
            personaje.setLegendario(true);
        } else {
            cout << "El item consumible no es reconocido." << endl;
        }
    } else {
        cout << "El item no es consumible." << endl;
    }
}

void ItemMagico::usoMistico(Personaje& personaje) {
    if (esMistico) {
        cout << "El personaje " << personaje.getNombre() << " ha usado el item mistico: " << nombre << endl;
        cout << "El personaje ha ganado 50 de vida." << endl;
        personaje.setHP(personaje.getHP() + 50);
    } else {
        cout << "El item no es mistico." << endl;
    }
}

void ItemMagico::incrementarPoderMagico(int incremento) {
    if (ataqueLetal) {
        poderMagico += incremento;
        cout << "El poder mágico ha sido incrementado en " << incremento << endl;
    } else {
        cout << "El item no es ataque letal." << endl;
    }
}

