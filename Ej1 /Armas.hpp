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
        virtual int damAtaqueRapido(bool special) const = 0;
        virtual int damAtaqueFuerte(bool special) const = 0;
        virtual int damDefensaYGolpe(bool special) const = 0;
        virtual bool isMaldecido() const = 0;
        virtual std::string creadoPor() const = 0;
        virtual std::string getTipo() const = 0;
        virtual void setDamage(int damage) = 0;
        virtual void setMaldito(bool maldecido) = 0;
};

