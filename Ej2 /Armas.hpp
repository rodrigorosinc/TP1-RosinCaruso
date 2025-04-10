#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>

enum tipoAtaque{
    RAPIDO = 1,
    FUERTE = 2,
    DEFENSA_Y_GOLPE = 3
};

class Arma{
    public:
        virtual ~Arma() = default;
        virtual int getDamage() const = 0;
        virtual int damAtaqueRapido(bool special) const = 0;
        virtual int damAtaqueFuerte(bool special) const = 0;
        virtual int damDefensaYGolpe(bool spsecial) const = 0;
        virtual bool isMaldecido() const = 0;
        virtual std::string creadoPor() const = 0;
};

