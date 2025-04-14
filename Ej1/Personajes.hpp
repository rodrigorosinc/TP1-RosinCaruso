#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>
#include "Armas.hpp"

class Personaje {
    public: 
        virtual ~Personaje() = default;
        virtual void ataqueRapido(std::shared_ptr<Personaje> enemigo) = 0;
        virtual void ataqueFuerte(std::shared_ptr<Personaje> enemigo) = 0;
        virtual void defensaYGolpe(std::shared_ptr<Personaje> enemigo) = 0;
        virtual void setHP(int newHp) = 0;
        virtual int getHP() const = 0;
        virtual std::string getTipo() const = 0;
        virtual std::vector<std::shared_ptr<Arma>> getArmas() const = 0;
        virtual std::string getNombre() const = 0;
        virtual void setLegendario(bool legendario) = 0;
        virtual void removerArma(int index) = 0;
        virtual void setTurno(bool turno) = 0;
        virtual bool getTurno() const = 0;
        virtual std::shared_ptr<Arma> getArmaActual() const = 0;
};