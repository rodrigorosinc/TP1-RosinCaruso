#pragma once
#include "Personajes.hpp"
#include "ItemsMagicos.hpp"
#include "ItemsCombate.hpp"
#include "Armas.hpp"

class Magos : public Personaje {
    protected:
        std::string tipo;
        std::string nombre;
        int hp;
        std::vector<std::shared_ptr<Arma>> armas;
        std::shared_ptr<Arma> armaActual;
        int mana;
        bool legendario;

    public:
        Magos(std::string myNombre, int myHp, std::vector<std::shared_ptr<Arma>> myArmas, std::shared_ptr<Arma> myArmaActual);
        virtual ~Magos();
        // Ataques
        void ataqueRapido(std::shared_ptr<Personaje> enemigo) override;
        void ataqueFuerte(std::shared_ptr<Personaje> enemigo) override;
        void defensaYGolpe(std::shared_ptr<Personaje> enemigo) override;
        // Setters y Getters Virtuales
        void setHP(int newHp) override;
        int getHP() const override;
        std::vector<std::shared_ptr<Arma>> getArmas() const override;
        std::shared_ptr<Arma> getArmaActual() const override;
        void setArmaActual(std::shared_ptr<Arma> arma) override;
        // getters
        std::string getNombre() const;
        std::string getTipo() const;
        int getMana() const;
        // setters
        void setMana(int newMana);
        void setLegendario(bool legendario) override;
        // Funciones complementarias
        void removerArma(int index) override;
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
        Hechicero(std::string myNombre, int myHp, std::vector<std::shared_ptr<Arma>> myArmas, std::shared_ptr<Arma> myArmaActual);
        ~Hechicero() override;

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
        ~Conjurador() override;

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
        ~Brujo() override;

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
        ~Nigromante() override;

        void invocarEspectro(std::shared_ptr<Personaje> enemigo);
        void invocarFantasma(std::shared_ptr<Personaje> enemigo);
        void invocarZombie(std::shared_ptr<Personaje> enemigo);
        void invocarEsqueleto(std::shared_ptr<Personaje> enemigo);
        void invocarVampiro(std::shared_ptr<Personaje> enemigo);
};