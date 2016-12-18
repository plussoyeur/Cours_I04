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
private :
  int size;
  vector <vector <T> > donnees;
public :
  Carre();                   // constructeur par défaut
  Carre(int t);              // constructeur par affectation de la taille
  Carre(Carre <T> const& C); // constructeur par recopie
  ~Carre();                  // destructeur par défaut
  Carre <T> & operator=(Carre<T> C); // operateur d'assignation donc surcharge de "="
  void put(int i, int j, T coef); // fonction put
  T get(int i, int j);            // fonction get
  int taille();                   // fonction qui renvoit la taille du carre
};


/********************************/
/* Définition des constructeurs */
/********************************/

///Constructeur par défaut
template <typename T>
Carre<T>::Carre(){
  size = 1;
  donnees = {{1,0,1,0,1,0,1},{1,0,1,0,1,0,1},{1,0,1,0,1,0,1},{1,0,1,0,1,0,1},{1,0,1,0,1,0,1},{1,0,1,0,1,0,1},{1,0,1,0,1,0,1}};
  ///cout << "Appel du contructeur par défaut" << endl;
  ///cout << endl;
};

///Definition du constructeur par affectation
template <typename T>
Carre<T>::Carre(int t){
  size = t;
  donnees = {{1,0,1,0,1,0,1},{1,0,1,0,1,0,1},{1,0,1,0,1,0,1},{1,0,1,0,1,0,1},{1,0,1,0,1,0,1},{1,0,1,0,1,0,1},{1,0,1,0,1,0,1}};
  ///cout << "Appel du constructeur par affectation de la taille du carré : " << size << endl;
  ///cout << endl;
};


///Definition du constructeur par copie
template <typename T>
Carre<T>::Carre(Carre <T> const& C){
  donnees = C.donnees;
  size = C.size;
  ///cout << "Appel du constructeur par copie" << endl;
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
  os << "Carré de taille : " << C.taille() << endl;
  for(i=0; i<C.taille(); i++){
    os << "|";
    for(j=0; j<C.taille(); j++){
      os << C.get(i,j) << " ";
    }
    os << "|" << endl;
  }
  return os;
};


/// Surcharge de l'opérateur =
template <typename T>
Carre<T> & Carre<T>::operator=(Carre<T> M){
  int i, n;
  n = M.size;
  donnees.resize(n);
  for(i=0; i<n; i++){
    donnees[i].resize(n);
  }
  donnees = M.donnees;
  return *this;
};




/**************************************************/
/* Définition des fonctions du template utilisées */
/**************************************************/

///Fonction d'insertion d'un élément
template <typename T>
void Carre<T>::put(int i, int j, T coef){
  donnees[i][j] = coef;
};

///Fonction d'obtention d'un élément
template <typename T>
T Carre<T>::get(int i, int j){
  return donnees[i][j];
};


///Fonction qui renvoit la taille du carre
template <typename T>
int Carre<T>::taille(){
  return size;
};
