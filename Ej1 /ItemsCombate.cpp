#include "ItemsCombate.hpp"


using namespace std;

/*
ii. Armas de Combate: hacha simple, hacha doble, espada, lanza y garrote. 
Estas armas derivan de una interfaz única, de la cual se desprenden dos clases 
abstractas. Sea creativo, las clases derivadas deberán tener al menos 5 
atributos y 5 métodos.
*/

ArmaCombate::ArmaCombate(string arma, int damage, int sharpness, int letalidad)
    : arma(arma), damage(damage), sharpness(sharpness), letalidad(letalidad) {}

int ArmaCombate::calcularDamTotal() const {
    return calcularDamage() + calcularAddedDamage();
}
int ArmaCombate::damAtaqueRapido(bool special) const {
    return 10 + calcularDamTotal();
}
int ArmaCombate::damAtaqueFuerte(bool special) const {
    return 10 + calcularDamTotal();
}
int ArmaCombate::damDefensaYGolpe(bool special) const {
    return 10 + calcularDamTotal();
}
int ArmaCombate::getDamage() const {
    return damage;
}
bool ArmaCombate::isMaldecido() const {
    return false;
}
string ArmaCombate::creadoPor() const {
    return nombreCreador;
}

// ==================== HachaSimple ====================

HachaSimple::HachaSimple()
    : ArmaCombate("Hacha Simple", 10, 5, 2){
        srand(time(0));
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
                quebrada = false;
                return;
        }
        addedDamage = rand() % 4 + 1;
        quebrada = false;           
    }

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
    longitudHoja--;
}
void HachaSimple::rehacer() {
    srand(time(0));
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

// ==================== HachaDoble ====================

