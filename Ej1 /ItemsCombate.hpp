#include "Armas.hpp"
#include "ItemsMagicos.hpp"
#include "Personajes.hpp"

/*
ii. Armas de Combate: hacha simple, hacha doble, espada, lanza y garrote. 
Estas armas derivan de una interfaz única, de la cual se desprenden dos clases 
abstractas. Sea creativo, las clases derivadas deberán tener al menos 5 
atributos y 5 métodos.
*/

class ArmaCombate : public Arma {
    protected:
        std::string nombreCreador;
        std::string arma;
        int damage;
        int sharpness;
        int letalidad;
        bool legendaria;
    public:
        ArmaCombate(std::string arma, int damage, int sharpness, int letalidad);

        virtual ~ArmaCombate() = default;
        
        int calcularDamTotal() const;
        int damAtaqueRapido(bool special) const override;
        int damAtaqueFuerte(bool special) const override;
        int damDefensaYGolpe(bool special) const override;
        int getDamage() const override;
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
    public:
        HachaDoble();
        ~HachaDoble() override = default;

        int calcularDamage() const override;
        int calcularAddedDamage() const override;
};