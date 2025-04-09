#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>
#include "Empleados.hpp"

using namespace std;

class EntidadOrganizativa {
    private:
        vector<shared_ptr<EntidadOrganizativa>> entidadesOrganizativas;
    public:
        string nombre;
        void agregarSubidentidad(shared_ptr<EntidadOrganizativa> entidad);
        int contarSubentidades();
};

class Empresa : public EntidadOrganizativa {
    private:
        vector<shared_ptr<Departamento>> departamentos;
    public:
        string direccion;

        Empresa(string nombre, string direccion);
        Empresa(string nombre, string direccion, vector<shared_ptr<Departamento>> departamentos);

        shared_ptr<Departamento> getDepByName(string nombre);
        vector<shared_ptr<Departamento>> getDepNames();

};

class CentralRegional : public EntidadOrganizativa {
    private:
        int cantEmpleados;
        vector<shared_ptr<GerenteAlto>> gerentesAlto;
        vector<shared_ptr<GerenteMedio>> gerentesMedio;
        set<shared_ptr<Empresa>> empresas;
    public:
        set<string> paises;
        CentralRegional();
        
        int getCantEmpleados();
        vector<shared_ptr<GerenteAlto>> getGerentesAlto();
        vector<shared_ptr<GerenteMedio>> getGerentesMedio();
        vector<string> getEmpNames();
};

class Departamento {
    private:
        vector<shared_ptr<Empleado>> Empleados;
        static int cantEmpleadosDepts;
    public:
        string nombre;
        string ubicacion;
        
        static int contarEmpleados();
        vector<shared_ptr<Empleado>> getEmpleados();
        bool contratarEmpleado();
        bool despedirEmpleado();
};

