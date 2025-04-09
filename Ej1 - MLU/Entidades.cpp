#include "Entidades.hpp"
#include "Empleados.hpp"

using namespace std;

// ========================= ENTIDAD ORGANIZATIVA ============================

int EntidadOrganizativa::contarSubentidades() {
    return entidadesOrganizativas.size();
}
void EntidadOrganizativa::agregarSubidentidad(EntidadOrganizativa* entidad) {
    shared_ptr<EntidadOrganizativa> entidadPtr(entidad);
    entidadesOrganizativas.push_back(entidadPtr);
}


// ========================= EMPRESA =========================================

Empresa::Empresa(string empNombre, string empDireccion) {
    nombre = empNombre;
    direccion = empDireccion;
    departamentos = vector<shared_ptr<Departamento>>(); // Inicializa el vector de departamentos
    agregarSubidentidad(this); // Agrega la empresa a su propia lista de entidades organizativas
    //
}
Empresa::Empresa(string empNombre, string empDireccion, vector<shared_ptr<Departamento>> empDepartamentos) {
    nombre = empNombre;
    direccion = empDireccion;
    departamentos = empDepartamentos;
    agregarSubidentidad(this); // Agrega la empresa a su propia lista de entidades organizativas
}

shared_ptr<Departamento> Empresa::getDepByName(string nombre) {
    for (int i = 0; i < departamentos.size(); i++) {
        if (departamentos[i]->nombre == nombre) {
            return departamentos[i];
        }
    }
    return nullptr; // Si no se encuentra el departamento, devuelve nullptr
}

vector<shared_ptr<Departamento>> Empresa::getDepNames() {
    return departamentos;
}
// ========================= DEPARTAMENTO ===================================

// ======================== CENTRAL REGIONAL ==============================

CentralRegional::CentralRegional() {
    cantEmpleados = 0;
    paises = vector<string>();
    gerentesAlto = vector<shared_ptr<GerenteAlto>>();
    gerentesMedio = vector<shared_ptr<GerenteMedio>>();
    empresas = vector<shared_ptr<Empresa>>();
}


