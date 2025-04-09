#pragma once
#include "Entidades.hpp"

class Empleado {
    private:
        int antiguedad;
        float salario;
    public:
        string nombre;
        string puesto;
        int getAntiguedad();
        bool updateSalario();
        int getSalario();
};

class Manager : public Empleado {
    private:
        float bono;
        string level; // ??? enumclass o no?
    public:
        bool updateBono();
        float getBono();
        bool setLevel();
    
};

class GerenteAlto : public Manager {};

class GerenteMedio : public Manager {};

class LiderEquipo : public Manager {};

class  GerenteBajo : public Manager {};