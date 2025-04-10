#pragma once

#include "Armas.hpp"
#include "Personajes.hpp"

using namespace std;

/*
2.1. Interesa implementar dos grupos de armas:  
i. Items Mágicos: bastón, libro de hechizos, poción y amuleto. 
ii. Armas de Combate: hacha simple, hacha doble, espada, lanza y garrote. 
Estas armas derivan de una interfaz única, de la cual se desprenden dos clases 
abstractas. Sea creativo, las clases derivadas deberán tener al menos 5 
atributos y 5 métodos.
*/

//Arma es una interfaz, que define Items magicos y armas de combate. Estas dos ultimas
//heredan de Arma, y son clases abstractas. De ahí, derivan las clases concretas
// que implementan los métodos de las clases abstractas.

class ItemMagico : public Arma {
    protected:
        string nombreCreador;
        string arma; 
        tipoAtaque tAtaque;
        int damage;
        int poderMagico;
        int critico;
        bool maldecido;
        bool consumible;
        bool mistico;

    public:
        ItemMagico(int damage, int poderMagico, int critico, bool consumible, string nombreCreador);
        virtual ~ItemMagico() = default;
        
        virtual void consumir(Personaje& personaje) = 0;
        virtual int hacerDamCritico() const = 0;
        virtual int ataqueMistico() const = 0;     
        virtual void desMaldicir(Personaje& personaje) = 0; 

        
        int calcularDamTotal() const;
        int damAtaqueRapido(bool special) const override;
        int damAtaqueFuerte(bool special) const override;
        int damDefensaYGolpe(bool special) const override;
        
        int getDamage() const override;
        bool isMaldecido() const override;
        
        string getCreador() const;
        tipoAtaque getAtaque() const;
        string getArma() const;
        
        void setDamage(int damage);
        void setAtaque(tipoAtaque tipoAtaque);
        void setMistico(bool mistico);
        void maldicir();
        bool isMistico() const;
        bool isMaldecido() const;
        bool isConsumible() const;
};

class Baston : public ItemMagico {
    private:
        string element;
    public:
        Baston();
        ~Baston() override;

        void consumir(Personaje& personaje) override;
        int hacerDamCritico() const override;
        int ataqueMistico() const override;
        void desMaldicir(Personaje& personaje) override;
};

class LibroDeHechizos : public ItemMagico {
    public:
        LibroDeHechizos();
        ~LibroDeHechizos() override;
        void consumir(Personaje& personaje) override;
        int hacerDamCritico() const override;
        int ataqueMistico() const override;
        void desMaldicir(Personaje& personaje) override;
};

class Pocion : public ItemMagico {
    public:
        Pocion();
        ~Pocion() override;
        void consumir(Personaje& personaje) override;
        int hacerDamCritico() const override;
        int ataqueMistico() const override;
        void desMaldicir(Personaje& personaje) override;
};

class Amuleto : public ItemMagico {
    public:
        Amuleto();
        ~Amuleto() override;
        void consumir(Personaje& personaje) override;
        int hacerDamCritico() const override;
        int ataqueMistico() const override;
        void desMaldicir(Personaje& personaje) override;
};
