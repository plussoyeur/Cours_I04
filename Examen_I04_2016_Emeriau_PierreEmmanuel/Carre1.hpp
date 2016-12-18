#include <iostream>
#include <vector>
#include <stdlib.h>


/*************************************/
/*Déclaration des fonctions utilisées*/
/*************************************/

using std::cout;
using std::cerr;
using std::vector;
using std::endl;



/*********************************/
/* Définition de la classe Carre */
/*********************************/


template <typename T> class Carre{
public :
  int taille;
  vector <vector <T> > donnees = {{1,0,1,0,1,0,1},{1,0,1,0,1,0,1},{1,0,1,0,1,0,1},{1,0,1,0,1,0,1},{1,0,1,0,1,0,1},{1,0,1,0,1,0,1},{1,0,1,0,1,0,1}};
  Carre();                   // constructeur par défaut
  Carre(int t);              // constructeur par affectation de la taille
  ~Carre();                  // destructeur par défaut
};


/********************************/
/* Définition des constructeurs */
/********************************/

///Constructeur par défaut
template <typename T>
Carre<T>::Carre(){
  taille = 1;
  ///cout << "Appel du contructeur par défaut" << endl;
  ///cout << endl;
};

///Definition du constructeur par affectation
template <typename T>
Carre<T>::Carre(int t){
  taille = t;
  ///cout << "Appel du constructeur par affectation de la taille du carré : " << taille << endl;
  ///cout << endl;
};


/*****************************/
/* Definition du destructeur */
/*****************************/

template <typename T>
Carre<T>::~Carre(){
  ///cout << "Appel du destructeur par défaut" << endl;
  ///cout << endl;
};


/***********************************/
/* Surcharge des opérateurs usuels */
/***********************************/

/// Surcharge de l'opérateur d'affichage
template <typename T>
std::ostream & operator <<(std::ostream &os, Carre <T> C){
  int i,j;
  os << "Carré de taille : " << C.taille << endl;
  for(i=0; i<C.taille; i++){
    os << "|";
      for(j=0; j<C.taille; j++){
        os << C.donnees[i][j] << " ";
      }
    os << "|" << endl;
  }
  return os;
};

