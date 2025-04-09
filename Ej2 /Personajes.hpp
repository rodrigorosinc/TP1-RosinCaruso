#pragma once
#include "Items.hpp"

/*Al mismo tiempo, se desea implementar dos grupos de personajes 
i. Magos: hechicero, conjurador, brujo y nigromante. 
ii. Guerreros: bárbaro, paladín, caballero, mercenario y gladiador. 
Al igual que en el punto anterior, estos personajes derivan de una interfaz 
única, de la cual se desprenden dos clases abstractas. Sea creativo, las clases 
derivadas deberán tener al menos 5 atributos y 5 métodos.*/

enum class TipoMago {
    HECHICERO,
    CONJURADOR,
    BRUJO,
    NIGROMANTE
};
enum class TipoGuerrero {
    BARBARO,
    PALADIN,
    CABALLERO,
    MERCENARIO,
    GLADIADOR
};


class Personaje {
    protected:
        string nombre;
        string tipo;
        int nivel;
        int HP;
        int experiencia;
        bool esLegendario;
        vector<shared_ptr<Arma>> armas;
        int armaEquipada;

    public:
        Personaje(string nombre, int nivel, int experiencia, bool esLegendario,
            vector<shared_ptr<Arma>> armas, int armaEquipada);
        virtual ~Personaje();

        int getNivel() const;
        int getXP() const;
        int getHP() const;
        string getNombre() const;

        void setHP(int newHP);
        void setXP(int newXP);
        void setNivel(int newNivel);
        void setLegendario(bool esLegendario);

        bool isLegendario() const;

        vector<Arma> getArmas() const;
        void setArma(shared_ptr<Arma> arma);

        virtual void ataques(Personaje& enemigo) = 0;
};


class Mago : public Personaje {
    private:
        int poderMagico;
        TipoMago tipoMago;
        int escudoMagico;
        bool dobleMagia;
        int mana;

    public:
        Mago(TipoMago tipoMago, string nombre, vector<shared_ptr<Arma>> armas);
        ~Mago();
        void ataques(Personaje& enemigo) override;

        int getPoderMagico() const;
        int getEscudoMagico() const;
        int getMana() const;
        void setPoderMagico(int poderMagico);
        void setEscudoMagico(int escudoMagico);
        void setMana(int mana);

        
};

class Guerrero : public Personaje {
    private:
        int poderFisico;
        TipoGuerrero tipoGuerrero;
        int armadura;
        int fuerza;
    public:
};