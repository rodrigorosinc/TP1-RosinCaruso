#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>

class Arma{
    public:
        virtual ~Arma() = default;
        virtual int getDamage() const = 0;
        virtual std::string getNombreItem() const = 0;
        virtual int damAtaqueRapido() const = 0;
        virtual int damAtaqueFuerte() const = 0;
        virtual int damDefensaYGolpe() const = 0;
        virtual void setDamage(int damage) = 0;
        virtual void setMaldito(bool maldecir) = 0;
        virtual bool isMaldito() const = 0;
        virtual std::string getTipo() const = 0;
        virtual int getDamTotal() const = 0;
};

