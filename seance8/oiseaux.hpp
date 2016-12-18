#include <iostream>
#include <string>

/* Déclaration des fonctions utilisées*/
using std::cout;
using std::endl;
using std::string;

/* Définition de la classe creature_volante */
class creature_volante{
private :
  int nombre_ailes;
public :
  creature_volante();
  ~creature_volante();
  void affichage();
};


/* Définition de la classe animal */
class animal{
private :
  int nombre_pattes;
  string type_pelage;
public :
  animal();
  ~animal();
  void affichage();
};


/* Définition de la classe oiseaux */
class oiseau : public creature_volante, public animal{
private :
  int nombre_oeufs;
public :
  oiseau();
  ~oiseau();
  void affichage();
};
