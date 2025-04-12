#include "Armas.hpp"
#include "ItemsMagicos.hpp"
#include "Personajes.hpp"


class ArmaCombate : public Arma {
    protected:
        std::string nombreCreador;
        std::string arma;
        std::string tipo;
        int damage;
        int sharpness;
        int letalidad;
        bool legendaria;
    public:
        ArmaCombate(std::string arma, int damage, int sharpness, int letalidad, string tipo);
        virtual ~ArmaCombate() = default;
        
        int calcularDamTotal() const;
        int damAtaqueRapido(bool special) const override;
        int damAtaqueFuerte(bool special) const override;
        int damDefensaYGolpe(bool special) const override;
        int getDamage() const override;
        void setDamage(int damage) override;
        bool isMaldecido() const override;

        virtual int calcularDamage() const = 0;
        virtual int calcularAddedDamage() const = 0;

        std::string creadoPor() const override;
};

class HachaSimple : public ArmaCombate {
    private:
        std::string material;
        int addedDamage;
        int longitudHoja;
        int peso;
        bool quebrada;
    public:
        HachaSimple();
        ~HachaSimple() override = default;

        int calcularDamage() const override;
        int calcularAddedDamage() const override;
        void restaurar();
        void afilar();
        void rehacer();
};

class HachaDoble : public ArmaCombate {
    private:
        std::string material;
        int addSharpness;
        int anchoMango;
        bool tieneLanza;
        bool quebrada;
    public:
        HachaDoble();
        ~HachaDoble() override = default;

        int calcularDamage() const override;
        int calcularAddedDamage() const override;
        void afilar();
        void pulir();
        void lanzar(shared_ptr<Personaje> enemigo);
};

class Espada : public ArmaCombate {
    private:
        std::string material;
        int longitudHoja;
        int peso;
        bool doblada;
        int addLetalidad;
        int aura;

    public:
        Espada();
        ~Espada() override = default;

        int calcularDamage() const override;
        int calcularAddedDamage() const override;
        void relucir();
        void desdoblar();
        void canjearAura(shared_ptr<Personaje> enemigo);
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
        ~Lanza() override = default;

        int calcularDamage() const override;
        int calcularAddedDamage() const override;
        void lanzar(shared_ptr<Personaje> enemigo);
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
        ~Garrote() override = default;

        int calcularDamage() const override;
        int calcularAddedDamage() const override;
        void addPinchos(int cantidad);
        void envenenar();
        void envenenarPinchos();
};