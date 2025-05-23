#pragma once
#include "Armas.hpp"
#include "Personajes.hpp"


class ArmaCombate : public Arma {
    protected:
        int letalidad;
        int damage;
        int sharpness;
        std::string arma;
        std::string tipo;
        bool legendaria;
        bool maldita;
    public:
        ArmaCombate(std::string arma_, int damage_, int sharpness_, int letalidad_, std::string tipo_);
        virtual ~ArmaCombate();
        //Defino los metodos virtuales de la clase Arma
        int damAtaqueRapido() const override;
        int damAtaqueFuerte() const override;
        int damDefensaYGolpe() const override;
        //Getters y Setters virtuales
        std::string getNombreItem() const override;
        std::string getTipo() const override;
        int getDamTotal() const override;
        int getDamage() const override;
        void setDamage(int damage) override;
        void setMaldito(bool maldecir) override;
        bool isMaldito() const override;
        //Funciones virtuales para las derivadas
        virtual int calcularDamage() const = 0;
        virtual int calcularAddedDamage() const = 0;
        //Funcion para calcular el daño total
        int calcularDamTotal() const;
};

class HachaSimple : public ArmaCombate {
    private:
        int addedDamage;
        int longitudHoja;
        int peso;
        std::string material;
        bool quebrada;
    public:
        HachaSimple();
        ~HachaSimple() override;
        //Metodos
        int calcularDamage() const override;
        int calcularAddedDamage() const override;
        void restaurar();
        void afilar();
        void rehacer();
};

class HachaDoble : public ArmaCombate {
    private:
        int addSharpness;
        int anchoMango;
        std::string material;
        bool tieneLanza;
        bool quebrada;
    public:
        HachaDoble();
        ~HachaDoble() override;
        //Metodos
        int calcularDamage() const override;
        int calcularAddedDamage() const override;
        void afilar();
        void pulir();
        void lanzar(std::shared_ptr<Personaje> enemigo);
};

class Espada : public ArmaCombate {
    private:
        int longitudHoja;
        int peso;
        int addLetalidad;
        int aura;
        std::string material;
        bool doblada;

    public:
        Espada();
        ~Espada() override;
        //Metodos
        int calcularDamage() const override;
        int calcularAddedDamage() const override;
        void relucir();
        void desdoblar();
        void canjearAura(std::shared_ptr<Personaje> enemigo);
};

class Lanza : public ArmaCombate {
    private:
        int longitud;
        int peso;
        bool envenenada;
        int addletalidad;
        bool headshot;

    public:
        Lanza();
        ~Lanza() override;
        //Metodos
        int calcularDamage() const override;
        int calcularAddedDamage() const override;
        void lanzar(std::shared_ptr<Personaje> enemigo);
        void envenenar();
        void deshacerEnvenenamiento();
};

class Garrote : public ArmaCombate {
    private:
        int cantidadPinchos;
        int peso;
        bool envenenada;
        int addletalidad;
        int largoPinchos;
    public:
        Garrote();
        ~Garrote() override;
        //Metodos
        int calcularDamage() const override;
        int calcularAddedDamage() const override;
        void addPinchos(int cantidad);
        void envenenar();
        void envenenarPinchos();
};