#pragma once
#include "Personajes.hpp"
#include "ItemsMagicos.hpp"
#include "ItemsCombate.hpp"
#include "Armas.hpp"

/*Al mismo tiempo, se desea implementar dos grupos de personajes 
i. Magos: hechicero, conjurador, brujo y nigromante. 
ii. Guerreros: bárbaro, paladín, caballero, mercenario y gladiador. 
Al igual que en el punto anterior, estos personajes derivan de una interfaz 
única, de la cual se desprenden dos clases abstractas. Sea creativo, las clases 
derivadas deberán tener al menos 5 atributos y 5 métodos.*/

class Magos : public Personaje {
    protected:
        std::string nombre;
        std::string tipo;
        int hp;
        int mana;
        bool miTurno;
        bool legendario;
        std::vector<std::shared_ptr<Arma>> armas;
        std::shared_ptr<Arma> armaActual;

    public:
        Magos(std::string nombre, int hp, std::vector<std::shared_ptr<Arma>> armas, std::shared_ptr<Arma> armaActual, std::string tipo);
        virtual ~Magos() = default;

        void ataqueRapido(std::shared_ptr<Personaje> enemigo) override;
        void ataqueFuerte(std::shared_ptr<Personaje> enemigo) override;
        void defensaYGolpe(std::shared_ptr<Personaje> enemigo) override;
        void setHP(int newHp) override;
        int getHP() const override;
        std::vector<std::shared_ptr<Arma>> getArmas() const override;

        std::string getNombre() const;
        std::string getTipo() const;
        int getMana() const;
        
        void setMana(int newMana);
        void setTurno(bool turno);
        void setArmaActual(std::shared_ptr<Arma> arma);

        bool isLegendario() const;

};


class Hechicero : public Magos {
    private:
        bool tienePocionEscudo;
        bool tienePocionRecuperacion;
        bool tienePocionMana;
        bool tienePocionFuria;
        bool tienePocionX2;
    public:
        Hechicero(std::string nombre, int hp, std::vector<std::shared_ptr<Arma>> armas, std::shared_ptr<Arma> armaActual);
        ~Hechicero() override = default;

        void pocionEscudo();
        void pocionRecuperacion();
        void pocionMana();
        void pocionFuria();
        void pocionX2();
};

class Conjurador : public Magos {
    private:
        bool conjuroOscuro;
        bool conjuroLuminoso;
        bool conjuroElemental;
        bool maldijo; //una vez sola
        bool purificado; //una vez sola

    public:
        Conjurador(std::string nombre, int hp, std::vector<std::shared_ptr<Arma>> armas, std::shared_ptr<Arma> armaActual);
        ~Conjurador() override = default;

        void conjurarOscuro(std::shared_ptr<Personaje> enemigo);
        void conjurarLuminoso(std::shared_ptr<Personaje> enemigo);
        void conjurarElemental(std::shared_ptr<Personaje> enemigo);
        void maldecir(std::shared_ptr<Personaje> enemigo);
        void purificar(std::shared_ptr<Personaje> enemigo);
};

class Brujo : public Magos {
    private:
        bool embrujado;
        bool abracadabra;
        bool metamorfosis;
        bool hiperMetamorfosis;
        bool yinYang;

    public:
        Brujo(std::string nombre, int hp, std::vector<std::shared_ptr<Arma>> armas, std::shared_ptr<Arma> armaActual);
        ~Brujo() override = default;

        void embrujar(std::shared_ptr<Personaje> enemigo);
        void hacerAbracadabra(std::shared_ptr<Personaje> enemigo);
        void hacerMetamorfosis(std::shared_ptr<Personaje> enemigo);
        void hacerHiperMetamorfosis(std::shared_ptr<Personaje> enemigo);
        void recuperse();
};

class Nigromante : public Magos {
    private:
        bool invocoEspectro;
        bool invocoFantasma;
        bool invocoZombie;
        bool invocoEsqueleto;
        bool invocoVampiro;
    public:
        Nigromante(std::string nombre, int hp, std::vector<std::shared_ptr<Arma>> armas, std::shared_ptr<Arma> armaActual);
        ~Nigromante() override = default;

        void invocarEspectro(std::shared_ptr<Personaje> enemigo);
        void invocarFantasma(std::shared_ptr<Personaje> enemigo);
        void invocarZombie(std::shared_ptr<Personaje> enemigo);
        void invocarEsqueleto(std::shared_ptr<Personaje> enemigo);
        void invocarVampiro(std::shared_ptr<Personaje> enemigo);
};