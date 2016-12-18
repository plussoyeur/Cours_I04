#include <iostream>
#include <string>
#include <vector>
#include <cmath>

/* Déclaration des fonctions utilisées*/
using std::cout;
using std::endl;
using std::string;
using std::vector;

/* Définition de la classe de base */
class formes_2d{
protected :
  vector <double> coordonnees_centre;
public :
  formes_2d();
  formes_2d(formes_2d const& forme);
  formes_2d(vector <double> T);
  ~formes_2d();
  virtual double aire()=0;
  virtual double perimetre()=0;
  virtual vector <double> centre_gravite()=0;
};

/* Définition des classes spécialisées*/
class triangle : public formes_2d{
private :
  int nombre_cotes;
  double longueur1, longueur2, longueur3;
public :
  triangle();
  triangle(double l1, double l2, double l3, vector <double> T);
  ~triangle();
  double aire();
  double perimetre();
  vector <double> centre_gravite();
  void affichage();
};

class carre : public formes_2d{
private :
  int nombre_cotes;
  double longueur;
public :
  carre();
  carre(double l, vector <double> T);
  ~carre();
  double aire();
  double perimetre();
  vector <double> centre_gravite();
  void affichage();
};

class rectangle : public formes_2d{
private :
  int nombre_cotes;
  double longueur1, longueur2;
public :
  rectangle();
  rectangle(double l1, double l2, vector <double> T);
  ~rectangle();
  double aire();
  double perimetre();
  vector <double> centre_gravite();
  void affichage();
};
