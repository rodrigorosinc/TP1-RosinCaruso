#pragma once
#include "Personajes.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>

using namespace std;

/*
2.1. Interesa implementar dos grupos de armas:  
i. Items Mágicos: bastón, libro de hechizos, poción y amuleto. 
ii. Armas de Combate: hacha simple, hacha doble, espada, lanza y garrote. 
Estas armas derivan de una interfaz única, de la cual se desprenden dos clases 
abstractas. Sea creativo, las clases derivadas deberán tener al menos 5 
atributos y 5 métodos.
*/

class Arma {
    protected:
        std::string nombre;
        int damage;
        int critico; // probabilidad de critico, 0 a 100
        bool ataqueLetal;

    public:
        Arma(std::string nombre, int damage, int nivel, 
            int critico, bool ataqueLetal);
        
        virtual int calcularDamage(Personaje& personaje) = 0;
        virtual int sumarDamCritico() = 0;
        virtual ~Arma() = default;
        int getCritico() const;
        int getDamage() const;
        std::string getNombre();

        void setCritico(int critico);
        void setDamage(int damage);
        void setAtaqueLetal(bool ataqueLetal);
        void setNombre(std::string nombre);

};

class ItemMagico : public Arma {
    private:
        int poderMagico;
        bool esConsumible;
        bool esMistico;
        std::string nombreCreador;
        bool cursed;

    public:
        ItemMagico(std::string nombre, int damage, int nivel, 
            int critico, bool ataqueLetal, int poderMagico, bool esConsumible, 
            bool esMistico, std::string nombreCreador, bool cursed);
        
        int calcularDamage(Personaje& personaje) override;
        int sumarDamCritico() override;
        void usarItem(Personaje& personaje);
        void usoMistico(Personaje& personaje);
        void incrementarPoderMagico(int incremento);
};

class ArmaCombate : public Arma {
    private:
        int poderFisico;
        int peso;
        bool seLanza;
        bool esLegendaria;
        std::string nombreCreador;
    public:
        ArmaCombate(std::string nombre, int damage, int nivel, 
            int critico, bool AtaqueLetal, int poderFisico, int peso, bool seLanza, 
            bool esLegendaria, std::string nombreCreador);
        
        int calcularDamage(Personaje& personaje) override;
        int sumarDamCritico() override;
        void lanzarArma(Personaje& personaje);
};