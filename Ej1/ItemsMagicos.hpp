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
        ItemMagico(int myDamage, int myPoderMagico, int myCritico, bool myConsumible, std::string myArma);
        virtual ~ItemMagico();
        
        virtual void consumir(std::shared_ptr<Personaje> personaje) = 0;
        virtual int hacerDamCritico() const = 0;
        virtual int ataqueMistico() const = 0;     
        virtual void purificar(std::shared_ptr<Personaje> personaje) = 0; 
        virtual bool puedePurificar(std::shared_ptr<Personaje> personaje) const = 0;
        
        int calcularDamTotal() const;
        int damAtaqueRapido() const override;
        int damAtaqueFuerte() const override;
        int damDefensaYGolpe() const override;
        void setDamage(int damage) override;
        std::string getNombreItem() const override;
        void setMaldito(bool maldecir) override;
        bool isMaldito() const override;
        int getDamage() const override;
        int getDamTotal() const override;
        
        std::string getCreador() const;
        std::string getArma() const;
        std::string getTipo() const;
        
        void setMistico(bool mistico);

        void setCreador(std::string creador);
        void maldecir();
        bool isMistico() const;
        bool isConsumible() const;
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

        void consumir(std::shared_ptr<Personaje> personaje) override;
        int hacerDamCritico() const override;
        int ataqueMistico() const override;
        void purificar(std::shared_ptr<Personaje> personaje) override;
        void reforjar();
        bool puedePurificar(std::shared_ptr<Personaje> personaje) const override;
        
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

        void consumir(std::shared_ptr<Personaje> personaje) override;
        int hacerDamCritico() const override;
        int ataqueMistico() const override;
        void purificar(std::shared_ptr<Personaje> personaje) override;
        void legendarizar(std::shared_ptr<Personaje> personaje);
        bool puedePurificar(std::shared_ptr<Personaje> personaje) const override;
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
        void consumir(std::shared_ptr<Personaje> personaje) override;
        int hacerDamCritico() const override;
        int ataqueMistico() const override;
        void purificar(std::shared_ptr<Personaje> personaje) override;
        bool puedePurificar(std::shared_ptr<Personaje> personaje) const override;

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
        void consumir(std::shared_ptr<Personaje> personaje) override;
        int hacerDamCritico() const override;
        int ataqueMistico() const override;
        void purificar(std::shared_ptr<Personaje> personaje) override;
        bool puedePurificar(std::shared_ptr<Personaje> personaje) const override;
        void legendarizar(std::shared_ptr<Personaje> personaje);
};
