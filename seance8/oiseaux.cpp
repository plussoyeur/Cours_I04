#include "oiseaux.hpp"

/* Définitions des constructeurs */
creature_volante::creature_volante(){
  nombre_ailes = 2;
  cout << "Appel du constructeur creature_volante" << endl;
}

animal::animal(){
  nombre_pattes = 2;
  type_pelage = "plume";
  cout << "Appel du constructeur animal" << endl;
}

oiseau::oiseau(){
  nombre_oeufs = 3;
  cout << "Appel du constructeur oiseau" << endl;
}

/* Définitions des destructeurs */

creature_volante::~creature_volante(){
  cout << "Destructeur de creature_volante" << endl;
}

animal::~animal(){
  cout << "Destructeur de animal" << endl;
}

oiseau::~oiseau(){
  cout << "Destructeur de oiseau" << endl;
}



/* Définition de la fonction d'affichage de creature_volante */
void creature_volante::affichage(){
  cout << "Nombre d'ailes = " << nombre_ailes << endl;
}

void animal::affichage(){
  cout << "Nombre de pattes = " << nombre_pattes << endl;
  cout << "Type pelage = " << type_pelage << endl;
}

void oiseau::affichage(){
  cout << "Nombre d'oeufs = " << nombre_oeufs << endl;
  creature_volante::affichage();
  animal::affichage();
}


int main(){
  oiseau pie;
  pie.affichage();

  return 0;
}
