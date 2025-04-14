#include "ItemsMagicos.hpp"

enum NombreCreador {
    RAGNAR_LOTHBROK, //mistico
    GANDALF, 
    PEDRO, // mistico
    DR_STRANGE 
};

using namespace std;

ItemMagico::~ItemMagico() = default;

ItemMagico::ItemMagico(int damage, int critico, int poderMagico,
    bool consumible, std::string arma)
    : damage(damage), poderMagico(poderMagico), critico(critico), 
    consumible(consumible), arma(arma), tipo("Item Magico"), 
    mistico(false) {
        int random = rand() % 4;
        if (random == 0) {
            this->maldito = true;
        } else {
            this->maldito = false;
        }
        int randomCreador = rand() % 4;
        switch (randomCreador) {
            case 0:
                nombreCreador = "Ragnar Lothbrok";
                break;
            case 1:
                nombreCreador = "Gandalf";
                break;
            case 2:
                nombreCreador = "Pedro";
                break;
            case 3:
                nombreCreador = "Dr. Strange";
                break;
        }
    }
    
int ItemMagico::getDamage() const {
    return damage;
}

string ItemMagico::getTipo() const {
    return tipo;
}
string ItemMagico::getNombreItem() const {
    return arma;
}
bool ItemMagico::isMaldito() const {
    return maldito;
}
void ItemMagico::maldecir() {
    maldito = true;
}
void ItemMagico::setMaldito(bool maldecir) {
    maldito = maldecir;
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
void ItemMagico::setCreador(string creador) {
    this->nombreCreador = creador;
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

int ItemMagico::damAtaqueRapido() const {
    return 10 + calcularDamTotal();
}
int ItemMagico::damAtaqueFuerte() const {
    return 10 + calcularDamTotal();
}
int ItemMagico::damDefensaYGolpe() const {
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
    int random = rand() % 3;  
    string element;
    switch (random) {
        case 0:
            element = "Abeto";
            baston.setDamage(baston.getDamage() + 2);
            baston.setLargo(1.7);
            baston.setPeso(30);
            break;
        case 1:
            element = "Roble";
            baston.setDamage(baston.getDamage() + 3);
            baston.setLargo(1.5);
            baston.setPeso(27);
            break;
        case 2:
            element = "Metal";
            baston.setDamage(baston.getDamage() + 5);
            baston.setLargo(1.2);
            baston.setPeso(50);
            break;
    }
    return element;
}

Baston::Baston()
    : ItemMagico(10, 50, 0, false, "Baston"),
      element(asignarElemento(*this)) {
        lentitud = round((largo / peso) * 10) / 10.0;
        reforjado = false;
      }

void Baston::consumir(shared_ptr<Personaje> personaje) {
    personaje->setHP(personaje->getHP() + 1);
    cout << "Se ha consumido el baston." << endl;
    if (maldito) {
        cout << "El baston es maldito. Se te resta 10 de vida." << endl;
        personaje->setHP(personaje->getHP() - 10);
    }
}
void Baston::purificar(shared_ptr<Personaje> personaje) {
    if (personaje->getNombre() == "Brujo") {
        cout << "El baston ha sido desmaldecido." << endl;
        maldito = false;
    } else {
        cout << "El baston no puede ser desmaldecido por este personaje." << endl;
    }
}
int Baston::hacerDamCritico() const {
    int random = rand() % 100;
    int critChance = critico + poderMagico/5;
    if (random < critChance) {
        return damage * 2 * lentitud;
    }
    return damage * lentitud;
}
int Baston::ataqueMistico() const {
    if (mistico) {
        return 20;
    }
    return 0;
}

void Baston::setPeso(int peso){
    this->peso = peso;
}

void Baston::setLargo(float largo){
    this->largo = largo;
}

void Baston::reforjar() {
    if (!reforjado) {
        cout << "El baston ha sido reforjado." << endl;
        cout << "Nuevo elemento: " << element << endl;
        element = asignarElemento(*this);
        damage += 5;
        critico += 2;
        reforjado = true;
        return;
    }
    cout << "No se puede reforjar el baston nuevamente." << endl;
}
bool Baston::puedePurificar(shared_ptr<Personaje> personaje) const {
    return personaje->getNombre() == "Brujo";
}

Baston::~Baston() = default;

// ====================== LIBRO DE HECHIZOS ==========================

LibroDeHechizos::LibroDeHechizos() :
    ItemMagico(5, 20, 0, true, "Libro de Hechizos") { 
        int random = rand() % 6;
        if (random == 0) {
            this->mistico = true;
        }
        maldito = false;
        if (random == 1) {
            this->maldito = true;
        }

        arma = "Libro de Hechizos";
        
        int cantHojas = rand() % 4700;
        hojas = cantHojas;
        
        if (cantHojas == 0) {
            additionalDamage = 0;
            additionalCritico = 0;
            additionalPoderMagico = 0;
            damage*= additionalDamage;
            critico*= additionalCritico;
            poderMagico*= additionalPoderMagico;
        } else if (cantHojas < 1000){
            additionalCritico = 1;
            additionalDamage = 3;
            additionalPoderMagico = 2;
        } else if (1000 < cantHojas && cantHojas < 2000){
            additionalCritico = 2;
            additionalDamage = 5;
            additionalPoderMagico = 3;
        } else if (2000 < cantHojas && cantHojas < 3000){
            additionalCritico = 3;
            additionalDamage = 7;
            additionalPoderMagico = 4;
        } else if (3000 < cantHojas && cantHojas < 4000){
            additionalCritico = 4;
            additionalDamage = 9;
            additionalPoderMagico = 5;
        } else {
            additionalCritico = 5;
            additionalDamage = 11;
            additionalPoderMagico = 6;
        }
}
bool LibroDeHechizos::puedePurificar(shared_ptr<Personaje> personaje) const {
    return personaje->getNombre() == "Brujo";
}
void LibroDeHechizos::consumir(shared_ptr<Personaje> personaje) {
    if (!maldito){
        damage += additionalDamage;
        critico += additionalCritico;
        poderMagico += additionalPoderMagico;
        personaje->setHP(personaje->getHP() + 10);
        cout << "El libro de hechizos ha sido consumido." << endl;
    } else {
        cout << "El libro de hechizos no se puede consumir debido a la maldicion." << endl;
    }
}

void LibroDeHechizos::purificar(shared_ptr<Personaje> personaje) {
    if (personaje->getNombre() == "Brujo") {
        cout << "El libro de hechizos ha sido desmaldecido." << endl;
        maldito = false;
    } else {
        cout << "El libro de hechizos no puede ser desmaldecido por este personaje." << endl;
    }
}
int LibroDeHechizos::hacerDamCritico() const {
    int random = rand() % 100;
    int critChance = critico + poderMagico/4;
    if (random < critChance) {
        return damage * 5/2;
    }
    return damage;
}
int LibroDeHechizos::ataqueMistico() const {
    if (mistico) {
        return 10 + (poderMagico / 8);
    }
    return 0;
}
void LibroDeHechizos::legendarizar(shared_ptr<Personaje> personaje) {
    if (!legendarizado) {
        if (!maldito) {
            personaje->setLegendario(true);
            personaje->setHP(personaje->getHP() + 120);
            legendarizado = true;
            cout << "El personaje ha sido legendarizado." << endl;
        }
        else {
            cout << "El libro de hechizos no se puede legendarizar debido a la maldicion." << endl;
        }
    } else {
        cout << "El libro de hechizos ya ha sido legendarizado." << endl;
    }
}

LibroDeHechizos::~LibroDeHechizos() = default;

// ====================== Pocion ==========================

enum creadorPocion {
    HECHICERO,
    CONJURADOR,
    BRUJO,
    NIGROMANTE
};

string asignarCreadorPocion(Pocion& pocion) {
    // Asigno creador al azar
    int random = rand() % 4;  
    switch (random) {
        case 0:
            pocion.setCreador("Hechicero");
            return "Hechicero";
        case 1:
            pocion.setCreador("Conjurador");
            return "Conjurador";
        case 2:
            pocion.setCreador("Brujo");
            return "Brujo";
        case 3:
            pocion.setCreador("Nigromante");
            return "Nigromante";
    }
    return "Ninguno";
}

Pocion::Pocion():
ItemMagico(5, 35, 35, true, "Pocion"), isGood(false), seCayo(false) {
        probSeCaiga =  rand() % 15;
        int random = rand() % 3;
        if (random == 0) {
            isGood = false;
            addHp = 0;
            subHp = 30;
        } else {
            isGood = true;
            addHp = 20;
            subHp = 0;
        }
}
bool Pocion::verificarCaida(shared_ptr<Personaje> personaje) const {
    int random = rand() % 100;
    if (random < probSeCaiga) {
        cout << "Se cayó la poción, máquina." << endl;
        if (isGood) {
            cout << "Safaste, la poción es buena." << endl;
            personaje->setHP(personaje->getHP() + addHp);
        } else {
            cout << "La poción es mala. Se te restan " << subHp << " de vida." << endl;
            personaje->setHP(personaje->getHP() - subHp);
        }
        return true;
    }
    return false;
}
bool Pocion::puedePurificar(shared_ptr<Personaje> personaje) const {
    return personaje->getNombre() == nombreCreador;
}
void Pocion::consumir(shared_ptr<Personaje> personaje) {
    if (isGood) {
        cout << "La poción es buena. Se te suman " << addHp << " de vida." << endl;
        personaje->setHP(personaje->getHP() + addHp);
    } else {
        cout << "La poción es mala. Se te restan " << subHp << " de vida." << endl;
        personaje->setHP(personaje->getHP() - subHp);
    }
}

void Pocion::purificar(shared_ptr<Personaje> personaje) {
    maldito = false;
    poderMagico -= 3;
    personaje->setHP(personaje->getHP() + 5);
}

int Pocion::hacerDamCritico() const {
    int random = rand() % 100;
    int critChance = critico + poderMagico;
    if (random < critChance) {
        return damage * 2;
    }
    return damage;
}
int Pocion::ataqueMistico() const {
    if (mistico) {
        return 10 + (poderMagico / 7);
    }
    return 0;
}

Pocion::~Pocion() = default;

// ====================== AMULETO ==========================

Amuleto::Amuleto() :
    ItemMagico(5, 20, 0, true, "Amuleto") {
        maldito = false;
        mistico = false;
        escudo = 30;
        dobleMagia = true;
        addHp = 40;
        legendarizado = false;
        additionalDamage = 0;
}
Amuleto::~Amuleto() = default;

void Amuleto::consumir(shared_ptr<Personaje> personaje) {
    if (legendarizado) {
        cout << "El amuleto ha sido consumido." << endl;
        personaje->setHP(personaje->getHP() + addHp);
        personaje->setLegendario(true);
    } else {
        cout << "El amuleto no se puede consumir." << endl;
    }
}

void Amuleto::purificar(shared_ptr<Personaje> personaje) {
    if (personaje->getNombre() == "Nigromante") {
        cout << "El amuleto ha sido desmaldecido." << endl;
        maldito = false;
    } else {
        cout << "El amuleto no puede ser desmaldecido por este personaje." << endl;
    }
}

int Amuleto::hacerDamCritico() const {
    int random = rand() % 100;
    int critChance = critico + poderMagico/3;
    if (random < critChance) {
        return damage * 2 + additionalDamage;
    }
    return damage + additionalDamage;
}
int Amuleto::ataqueMistico() const {
    if (mistico) {
        return 10 + (poderMagico / 2);
    }
    return 0;
}
bool Amuleto::puedePurificar(shared_ptr<Personaje> personaje) const {
    return personaje->getNombre() == "Nigromante";
}
void Amuleto::legendarizar(shared_ptr<Personaje> personaje) {
    if (!legendarizado) {
        if (!maldito) {
            personaje->setLegendario(true);
            personaje->setHP(personaje->getHP() + 120);
            legendarizado = true;
            cout << "El personaje ha sido legendarizado." << endl;
        }
        else {
            cout << "El amuleto no se puede legendarizar debido a la maldicion." << endl;
        }
    } else {
        cout << "El amuleto ya ha sido legendarizado." << endl;
    }
}

