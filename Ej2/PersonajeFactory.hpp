#pragma once
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/PersonajesMagicos.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/PersonajesGuerreros.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/ItemsMagicos.hpp"
#include "/home/rodrigo/TP1-RosinCaruso/Ej1/ItemsCombate.hpp"
#include <cstdlib>
#include <ctime>
#include <memory>

class PersonajeFactory {
    public:
    static void inicializarSemilla();
    static int generarNumerosRandom(int limInf, int limSup);
    static std::shared_ptr<Magos> crearMago();
    static std::shared_ptr<Guerreros> crearGuerrero();
    static std::shared_ptr<ItemMagico> crearItemMagico();
    static std::shared_ptr<ArmaCombate> crearArmaDeCombate();
    static std::vector<std::shared_ptr<Personaje>> crearPersonajes();
};

