#pragma once
#include "Armas.hpp"
#include "Personajes.hpp"

//Arma es una interfaz, que define Items magicos y armas de combate. Estas dos ultimas
//heredan de Arma, y son clases abstractas. De ahí, derivan las clases concretas
// que implementan los métodos de las clases abstractas.

class ItemMagico : public Arma {
    protected:
        int damage;
        int poderMagico;
        int critico;
        bool consumible;
        std::string nombreCreador;
        std::string arma;
        std::string tipo;
        bool maldito;
        bool mistico;

    public:
        ItemMagico(int damage_, int poderMagico_, int critico_, bool consumible_, std::string armaName);
        virtual ~ItemMagico();
        //Defino los metodos virtuales de la clase Arma
        int damAtaqueRapido() const override;
        int damAtaqueFuerte() const override;
        int damDefensaYGolpe() const override;
        int getDamage() const override;
        int getDamTotal() const override;
        std::string getNombreItem() const override;
        void setDamage(int damage) override;
        void setMaldito(bool maldecir) override;
        bool isMaldito() const override;
        //Metodos virtuales para todos los items magicos
        virtual void consumir(std::shared_ptr<Personaje> personaje) = 0;
        virtual int hacerDamCritico() const = 0;
        virtual int ataqueMistico() const = 0;     
        virtual void purificar(std::shared_ptr<Personaje> personaje) = 0; 
        virtual bool puedePurificar(std::shared_ptr<Personaje> personaje) const = 0;
        //Funciones complementarias
        std::string getArma() const;
        std::string getTipo() const;
        void setMistico(bool mistico);
        void setCreador(std::string creador);
        void maldecir();
        int calcularDamTotal() const;
        bool isMistico() const;
};

class Baston : public ItemMagico {
    private:
        std::string element;
        float largo;
        int peso;
        float lentitud;
        bool reforjado;
    public:
        Baston();
        ~Baston() override;
        //Metodos
        void consumir(std::shared_ptr<Personaje> personaje) override;
        void purificar(std::shared_ptr<Personaje> personaje) override;
        bool puedePurificar(std::shared_ptr<Personaje> personaje) const override;
        int hacerDamCritico() const override;
        int ataqueMistico() const override;
        void reforjar();
        //Funciones complementarias
        void setLargo(float largo);
        void setPeso(int peso);
};

class LibroDeHechizos : public ItemMagico {
    private:
        int additionalDamage;
        int additionalCritico;
        int additionalPoderMagico;
        bool legendarizado;
        int hojas;
    
    public:
        LibroDeHechizos();
        ~LibroDeHechizos() override;
        //Metodos
        bool puedePurificar(std::shared_ptr<Personaje> personaje) const override;
        void purificar(std::shared_ptr<Personaje> personaje) override;
        void consumir(std::shared_ptr<Personaje> personaje) override;
        int hacerDamCritico() const override;
        int ataqueMistico() const override;
        //Funciones complementarias
        void legendarizar(std::shared_ptr<Personaje> personaje);
};

class Pocion : public ItemMagico {
    private:
        int addHp;
        int subHp;
        bool isGood;
        bool seCayo;
        int probSeCaiga;

    public:
        Pocion();
        ~Pocion() override;
        //Metodos
        bool puedePurificar(std::shared_ptr<Personaje> personaje) const override;
        void purificar(std::shared_ptr<Personaje> personaje) override;
        void consumir(std::shared_ptr<Personaje> personaje) override;
        int hacerDamCritico() const override;
        int ataqueMistico() const override;
        //Funciones complementarias
        bool verificarCaida(std::shared_ptr<Personaje> personaje) const;
};

class Amuleto : public ItemMagico {
    private:
        int escudo;
        bool dobleMagia;
        int addHp;
        bool legendarizado;
        int additionalDamage;

    public:
        Amuleto();
        ~Amuleto() override;
        //Metodos
        bool puedePurificar(std::shared_ptr<Personaje> personaje) const override;
        void purificar(std::shared_ptr<Personaje> personaje) override;
        void consumir(std::shared_ptr<Personaje> personaje) override;
        int ataqueMistico() const override;
        int hacerDamCritico() const override;
        //Funciones complementarias
        void legendarizar(std::shared_ptr<Personaje> personaje);
};
