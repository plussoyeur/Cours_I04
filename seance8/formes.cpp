#include "formes.hpp"

/* Definitions des constructeurs de la classe principale*/
formes_2d::formes_2d(){
  cout << "formes_2d : Appel du constructeur par défaut" << endl;
}

formes_2d::formes_2d(vector <double> T){
  coordonnees_centre = T;
  cout << "forme_2d : Appel du constructeur par passage des coordonnees du centre" << endl;
  if(T.size() > 2){
    cout << "ERROR le vecteur rentré est de taille strictement supérieur à 2. Ce constructeur veut un vecteur de taille 2 pour construire les coordonnées du centre" << endl;
  }
}

formes_2d::formes_2d(formes_2d const& forme){
  coordonnees_centre = forme.coordonnees_centre;
  cout << "forme_2d : Appel du constructeur par copie" << endl;
}



/* Definitions des constructeurs des classes spécialisées*/
triangle::triangle(){
  cout << "Triangle : Appel du constructeur par défaut" << endl;
}
triangle::triangle(double l1, double l2, double l3, vector <double> T){
  nombre_cotes = 3;
  longueur1 = l1;
  longueur2 = l2;
  longueur3 = l3;
  coordonnees_centre = T;
  cout << "Triangle : Appel du constructeur par passage des longueurs des côtés" << endl;
  if(T.size() > 2){
    cout << "ERROR le vecteur rentré est de taille strictement supérieur à 2. Ce constructeur veut un vecteur de taille 2 pour construire les coordonnées du centre" << endl;
  }

}


carre::carre(){
  cout << "Carré : Appel du constructeur par défaut" << endl;
}
carre::carre(double l, vector <double> T){
  nombre_cotes = 4;
  longueur = l;
  coordonnees_centre = T;
  cout << "Carré : Appel du constructeur par passage des longueurs des côtés" << endl;
  if(T.size() > 2){
    cout << "ERROR le vecteur rentré est de taille strictement supérieur à 2. Ce constructeur veut un vecteur de taille 2 pour construire les coordonnées du centre" << endl;
  }
}


rectangle::rectangle(){
  cout << "Rectangle : Appel du constructeur par défaut" << endl;
}
rectangle::rectangle(double l1, double l2, vector <double> T){
  nombre_cotes = 4;
  longueur1 = l1;
  longueur2 = l2;
  coordonnees_centre = T;
  cout << "Rectangle : Appel du constructeur par passage des longueurs des côtés" << endl;
  if(T.size() > 2){
    cout << "ERROR le vecteur rentré est de taille strictement supérieur à 2. Ce constructeur veut un vecteur de taille 2 pour construire les coordonnées du centre" << endl;
  }

}


/* Definitions des destructeurs */
formes_2d::~formes_2d(){
  cout << "formes_2d : Appel du destructeur" << endl;
}
triangle::~triangle(){
  cout << "Triangle : Appel du destructeur" << endl;
}
carre::~carre(){
  cout << "Carré : Appel du destructeur" << endl;
}
rectangle::~rectangle(){
  cout << "Rectangle : Appel du destructeur" << endl;
}


/* Definitions des fonctions */
void triangle::affichage(){
  cout << endl;
  cout << "L'aire du triangle est : " << this->aire() << endl;
  cout << "Le périmètre du triangle est : " << this->perimetre() << endl;
  cout << "Les coordonnées du centre de gravité du triangle sont : " << "x = " << this->centre_gravite()[0] << " et " << "y = " << this->centre_gravite()[1] << endl;
  cout << endl;
}


void carre::affichage(){
  cout << endl;
  cout << "L'aire du carré est : " << this->aire() << endl;
  cout << "Le périmètre du carré est : " << this->perimetre() << endl;
  cout << "Les coordonnées du centre de gravité du carré sont : " << "x = " << this->centre_gravite()[0] << " et " << "y = " << this->centre_gravite()[1] << endl;
  cout << endl;
}


void rectangle::affichage(){
  cout << endl;
  cout << "L'aire du rectangle est : " << this->aire() << endl;
  cout << "Le périmètre du rectangle est : " << this->perimetre() << endl;
  cout << "Les coordonnées du centre de gravité du rectangle sont : " << "x = " << this->centre_gravite()[0] << " et " << "y = " << this->centre_gravite()[1] << endl;
  cout << endl;
}





double triangle::aire(){
  double p, A;
  p = .5*(longueur1+longueur2+longueur3);
  A = sqrt(fabs(p*(p-longueur1)*(p-longueur2)*(p-longueur3)));
  return A;
}

double triangle::perimetre(){
  return longueur1 + longueur2 + longueur3;
}

vector <double> triangle::centre_gravite(){
  return coordonnees_centre;
}

double carre::aire(){
  return longueur*longueur;
}

double carre::perimetre(){
  return 4*longueur;
}

vector <double> carre::centre_gravite(){
  return coordonnees_centre;
}

double rectangle::aire(){
  return longueur1*longueur2;
}

double rectangle::perimetre(){
  return 2*longueur1 + 2*longueur2;
}

vector <double> rectangle::centre_gravite(){
  return coordonnees_centre;
}



int main(){
  //formes_2d forme(T);
  //formes_2d forme2(forme);

  vector <double> T1(2,0);
  vector <double> T2(2,2);
  triangle Tr(2, 4, 10, T1);
  carre C(2.5, T2);
  rectangle R(1, 8.5, T1);

  Tr.affichage();
  C.affichage();
  R.affichage();

  return 0;
}
