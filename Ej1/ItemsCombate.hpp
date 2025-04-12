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
    // Constructor en el mismo orden:
        ArmaCombate(std::string arma, int damage, int sharpness, int letalidad, std::string tipo);
        virtual ~ArmaCombate();
        virtual int calcularDamage() const = 0;
        virtual int calcularAddedDamage() const = 0;
        int calcularDamTotal() const;
        int damAtaqueRapido() const override;
        int damAtaqueFuerte() const override;
        int damDefensaYGolpe() const override;
        int getDamage() const override;
        std::string getNombreItem() const override;
        void setDamage(int damage) override;
        std::string getTipo() const override;
        void setMaldito(bool maldecir) override;
        bool isMaldito() const override;
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

        int calcularDamage() const override;
        int calcularAddedDamage() const override;
        void addPinchos(int cantidad);
        void envenenar();
        void envenenarPinchos();
};