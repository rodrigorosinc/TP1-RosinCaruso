#include "ItemsCombate.hpp"
#include "ItemsMagicos.hpp"
#include "Personajes.hpp"
#include "Armas.hpp"
#include "PersonajesGuerreros.hpp"
#include "PersonajesMagicos.hpp"


using namespace std;

int main(){
    shared_ptr<Personaje> personaje1 = make_shared<Barbaro>("Barbaro", 100, vector<shared_ptr<Arma>>(), nullptr);
    shared_ptr<Personaje> personaje2 = make_shared<Nigromante>("Nigromante", 100, vector<shared_ptr<Arma>>(), nullptr);

    cout << "Personaje 1: " << personaje1->getNombre() << endl;
    cout << "Tipo: " << personaje1->getTipo() << endl;
    cout << "HP: " << personaje1->getHP() << endl;

    cout << "Personaje 2: " << personaje2->getNombre() << endl;
    cout << "Tipo: " << personaje2->getTipo() << endl;
    cout << "HP: " << personaje2->getHP() << endl;


    return 0;
}