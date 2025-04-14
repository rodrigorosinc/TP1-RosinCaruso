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


class Guerreros : public Personaje {
    protected:
        std::string nombre;  // Mover primero
        int hp;             // Luego hp
        std::vector<std::shared_ptr<Arma>> armas;  // Luego armas
        std::shared_ptr<Arma> armaActual;          // Luego armaActual
        std::string tipo;    // Finalmente tipo
        int fuerzaDelRey;
        bool legendario;

    public:
        Guerreros(std::string myNombre, int myHp, std::vector<std::shared_ptr<Arma>> myArmas, std::shared_ptr<Arma> myArmaActual);
        virtual ~Guerreros();

        void ataqueRapido(std::shared_ptr<Personaje> enemigo) override;
        void ataqueFuerte(std::shared_ptr<Personaje> enemigo) override;
        void defensaYGolpe(std::shared_ptr<Personaje> enemigo) override;

        void setHP(int newHp) override;
        int getHP() const override;
        std::vector<std::shared_ptr<Arma>> getArmas() const override;
        void removerArma(int index) override;
        std::shared_ptr<Arma> getArmaActual() const override;
        
        std::string getNombre() const;
        std::string getTipo() const;
        int getFuerzaDelRey() const;

        void setFuerzaDelRey(int newFDR);
        void setArmaActual(std::shared_ptr<Arma> arma);
        void setLegendario(bool legendario);

        bool isLegendario() const;
};

class Barbaro : public Guerreros {
    private: 
        int peso;
        int fuerza;
        int resistencia;
        bool lider;
        bool berserker;
    public:
        Barbaro(std::string nombre, int hp, std::vector<std::shared_ptr<Arma>> armas, std::shared_ptr<Arma> armaActual);
        ~Barbaro() override;

        void gritar(std::shared_ptr<Personaje> enemigo);
        void embestir(std::shared_ptr<Personaje> enemigo);
        void gritarFuria(std::shared_ptr<Personaje> enemigo);
        void resistir();
        void poderBerserker(std::shared_ptr<Personaje> enemigo);
};

class Paladin : public Guerreros {
    private:
        bool espadaDeLaVerdad;
        bool yelmoDeLaEsperanza;
        int inteligencia;
        int nivelDeFe;
        int justicia;
    public:
        Paladin(std::string nombre, int hp, std::vector<std::shared_ptr<Arma>> armas, std::shared_ptr<Arma> armaActual);
        ~Paladin() override;

        void espadazo(std::shared_ptr<Personaje> enemigo);
        void ponerYelmo();
        void ajusticiar(std::shared_ptr<Personaje> enemigo);
        void fe();
        void poderDivino(std::shared_ptr<Personaje> enemigo);
};

class Caballero : public Guerreros {
    private:
        bool armaduraDeHierro;
        bool escudoTemplario;
        int fuerza;
        int curacion;
        std::string unidad;
    public:
        Caballero(std::string nombre, int hp, std::vector<std::shared_ptr<Arma>> armas, std::shared_ptr<Arma> armaActual);
        ~Caballero() override;

        void curarse();
        void usarArmadura();
        void usarEscudo();
        void ataqueEspecial(std::shared_ptr<Personaje> enemigo);
        void cambiarUnidad(std::string nuevaUnidad);
};

class Mercenario : public Guerreros {
    private:
        int inteligencia;
        int apetitoDeDinero;
        bool vengador;
        bool justiciero;
        bool jinete;
    public:
        Mercenario(std::string nombre, int hp, std::vector<std::shared_ptr<Arma>> armas, std::shared_ptr<Arma> armaActual);
        ~Mercenario() override;

        void robar(std::shared_ptr<Personaje> enemigo);
        void atacarPorDinero(std::shared_ptr<Personaje> enemigo);
        void atacarPorJusticia(std::shared_ptr<Personaje> enemigo);
        void atacarPorVenganza(std::shared_ptr<Personaje> enemigo);
        void montarJinete();
};

class Gladiador : public Guerreros {
    private:
        bool espartano;
        int fuerzaEspartana;
        int resistenciaEspartana;
        bool sangreEspartana;
        bool voluntadEspartana;
    public:
        Gladiador(std::string nombre, int hp, std::vector<std::shared_ptr<Arma>> armas, std::shared_ptr<Arma> armaActual);
        ~Gladiador() override;

        void gritar(std::shared_ptr<Personaje> enemigo);
        void chocarCabeza(std::shared_ptr<Personaje> enemigo);
        void cerrarHerida();
        void xerxes(std::shared_ptr<Personaje> enemigo);
        void pasarPorElFuego(std::shared_ptr<Personaje> enemigo);
};  