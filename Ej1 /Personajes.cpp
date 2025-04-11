#include "Personajes.hpp"
#include "ItemsMagicos.hpp"

using namespace std;

// ========================= PERSONAJES =========================
Personaje::Personaje(string nombre, int nivel, int experiencia, bool esLegendario,
    vector<shared_ptr<Arma>> armas, int armaEquipada)
    : nombre(nombre),nivel(nivel), HP(HP), experiencia(experiencia),
      esLegendario(esLegendario), armas(armas), armaEquipada(armaEquipada) {
        if (armas.size() > 3 || armas.size() < 0) {
            throw invalid_argument("El personaje no puede tener más de 3 armas");
        }
        if (nivel < 1) {
            throw invalid_argument("El nivel no puede ser menor a 1");
        }
        HP = 100;       
}

Personaje::~Personaje() {}

int Personaje::getNivel() const {
    return nivel;
}
int Personaje::getHP() const {
    return HP;
}
int Personaje::getXP() const {
    return experiencia;
}
string Personaje::getNombre() const {
    return nombre;
}
bool Personaje::isLegendario() const {
    return esLegendario;
}
void Personaje::setHP(int newHp) {
    HP = newHp;
}
void Personaje::setXP(int newXP) {
    experiencia = newXP;
}
void Personaje::setNivel(int newNivel) {
    nivel = newNivel;
}

// ========================= MAGO =========================

Mago::Mago(TipoMago tipoMago, string nombre, vector<shared_ptr<Arma>> armas) : 
    Personaje(nombre, nivel, experiencia, esLegendario, armas, armaEquipada) {
        this->tipoMago = tipoMago;
        this->armas = armas;
        this->armaEquipada = armaEquipada;

        if (tipoMago == TipoMago::HECHICERO) {
            poderMagico = 10;
            escudoMagico = 5;
            mana = 100;
            esLegendario = true;
            dobleMagia = true;

        } else if (tipoMago == TipoMago::CONJURADOR) {
            poderMagico = 8;
            escudoMagico = 7;
            mana = 80;
            esLegendario = false;
            dobleMagia = true;
        } else if (tipoMago == TipoMago::BRUJO) {
            poderMagico = 12;
            escudoMagico = 3;
            mana = 120;
            esLegendario = false;
            dobleMagia = false;
        } else if (tipoMago == TipoMago::NIGROMANTE) {
            poderMagico = 15;
            escudoMagico = 2;
            mana = 150;
            esLegendario = true;
            dobleMagia = false;
        }
        
}
