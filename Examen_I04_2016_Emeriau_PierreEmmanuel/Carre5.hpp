#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <typeinfo>
#include <math.h>

/*************************************/
/*Déclaration des fonctions utilisées*/
/*************************************/

using std::cout;
using std::cerr;
using std::vector;
using std::endl;
using std::string;
using std::is_same;


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
  void moyenne(string moy);      // fonction de moyenne
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


/// Surcharge de l'opérateur +
template <typename T>
Carre<T> operator+(Carre <T> M1, Carre <T> M2){
  Carre <T> res(M1);
  int i,j;
  if(M1.taille() != M2.taille()){
    cout << "ERREUR : vous voulez sommer des matrices de taille différentes" << endl;}
  else{
    for(i=0; i<M1.taille(); i++){
      for(j=0; j<M1.taille(); j++){
        res.put(i,j,M1.get(i,j) + M2.get(i,j));
      }
    }
  }

  return res;
};

/// Surcharge de l'opérateur -
template <typename T>
Carre<T> operator-(Carre <T> M1, Carre <T> M2){
  Carre <T> res(M1);
  int i,j;
  if(M1.taille() != M2.taille()){
    cout << "ERREUR : vous voulez sommer des matrices de taille différentes" << endl;}
  else{
    for(i=0; i<M1.taille(); i++){
      for(j=0; j<M1.taille(); j++){
        res.put(i,j,M1.get(i,j) - M2.get(i,j));
      }
    }
  }

  return res;
};

/// Surcharge de l'opérateur *
template <typename T>
Carre<T> operator*(Carre <T> M1, Carre <T> M2){
  Carre <T> res(M1);
  int i,j;
  if(M1.taille() != M2.taille()){
    cout << "ERREUR : vous voulez sommer des matrices de taille différentes" << endl;}
  else{
    for(i=0; i<M1.taille(); i++){
      for(j=0; j<M1.taille(); j++){
        res.put(i,j,M1.get(i,j) * M2.get(i,j));
      }
    }
  }

  return res;
};

/// Surcharge de l'opérateur * par un élément de type T
template <typename T>
Carre<T> operator*(T s, Carre<T> &C){
  Carre <T> res(C);
  int i,j;
  for(i=0; i<C.taille(); i++){
    for(j=0; j<C.taille(); j++){
      res.put(i,j,s*C.get(i,j));
    }
  }
  return res;
};

template <typename T>
Carre<T> operator*(Carre<T> &M, T s){
  return s*M;
};



/// Surcharge de l'opérateur *=
template <typename T>
Carre<T> operator*=(Carre <T> &C, T s){
    C = s*C;
    return C;
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


///Fonction de moyenne
template <typename T>
void Carre<T>::moyenne(string moy){
  int i,j,n;
  Carre<T> C(*this);
  Carre<T> C2(C);
  n = this->taille();


  if(moy == "tore"){
    /// Calcul des points à l'intérieur de la matrice (idem pour tore et miroir)
    for(i=1; i<n-1 ;i++){
        for(j=1; j<n-1 ;j++){
          if (typeid(T) == typeid(int)){ /// Pour le cas où le type est entier on arrondit à l'entier le plus proche
            C2.put(i,j,round(.2*(this->get(i,j)+this->get(i-1,j)+this->get(i,j-1)+this->get(i+1,j)+this->get(i,j+1))));}
          else{ /// Sinon on fait le calcul de manière classique sur les 4 voisins et le point considéré
            C2.put(i,j,.2*(this->get(i,j)+this->get(i-1,j)+this->get(i,j-1)+this->get(i+1,j)+this->get(i,j+1)));}
          }
        }
    /// Calcul des points à la frontière avec la méthode tore
    if (typeid(T) == typeid(int)){

      for(j=2; j<n-1; j++){
        C2.put(0,j, round(0.2*(this->get(0,j)+this->get(0,j-1)+this->get(0,j+1)+this->get(1,j)+this->get(n-1,j)))   );
      }

      for(j=2; j<n-1; j++){
        C2.put(n-1,j, round(0.2*(this->get(n-1,j)+this->get(n-1,j-1)+this->get(n-1,j+1)+this->get(n-2,j)+this->get(0,j)))   );
      }

      for(i=2; i<n-1; i++){
        C2.put(i,0, round(0.2*(this->get(i,0)+this->get(i-1,0)+this->get(i+1,0)+this->get(i,1)+this->get(i,n-1)))   );
      }

      for(i=2; i<n-1; i++){
        C2.put(i,n-1, round(0.2*(this->get(i,n-1)+this->get(i-1,n-1)+this->get(i+1,n-1)+this->get(i,n-2)+this->get(i,0)))   );
      }
      C2.put(0,0, round(0.2*(this->get(0,0) + this->get(0,1) + this->get(1,0) + this->get(n-1,0) + this->get(0,n-1)) ) );
      C2.put(0,n-1, round(0.2*(this->get(0,n-1) + this->get(1,n-1) + this->get(0,n-2) + this->get(n-1,n-1) + this->get(0,0)) ) );
      C2.put(n-1,0, round(0.2*(this->get(n-1,0) + this->get(n-1,1) + this->get(n-2,0) + this->get(0,0) + this->get(n-1,n-1)) ) );
      C2.put(n-1,n-1, round(0.2*(this->get(n-1,n-1) + this->get(n-1,n-2) + this->get(n-2,n-1) + this->get(n-1,0) + this->get(0,n-1)) ) );
    }

    else{
      for(j=2; j<n-1; j++){
        C2.put(0,j, 0.2*(this->get(0,j)+this->get(0,j-1)+this->get(0,j+1)+this->get(1,j)+this->get(n-1,j))   );
      }

      for(j=2; j<n-1; j++){
        C2.put(n-1,j, 0.2*(this->get(n-1,j)+this->get(n-1,j-1)+this->get(n-1,j+1)+this->get(n-2,j)+this->get(0,j))   );
      }

      for(i=2; i<n-1; i++){
        C2.put(i,0, 0.2*(this->get(i,0)+this->get(i-1,0)+this->get(i+1,0)+this->get(i,1)+this->get(i,n-1))   );
      }

      for(i=2; i<n-1; i++){
        C2.put(i,n-1, 0.2*(this->get(i,n-1)+this->get(i-1,n-1)+this->get(i+1,n-1)+this->get(i,n-2)+this->get(i,0))   );
      }
      C2.put(0,0, 0.2*(this->get(0,0) + this->get(0,1) + this->get(1,0) + this->get(n-1,0) + this->get(0,n-1) ) );
      C2.put(0,n-1, 0.2*(this->get(0,n-1) + this->get(1,n-1) + this->get(0,n-2) + this->get(n-1,n-1) + this->get(0,0) ) );
      C2.put(n-1,0, 0.2*(this->get(n-1,0) + this->get(n-1,1) + this->get(n-2,0) + this->get(0,0) + this->get(n-1,n-1) ) );
      C2.put(n-1,n-1, 0.2*(this->get(n-1,n-1) + this->get(n-1,n-2) + this->get(n-2,n-1) + this->get(n-1,0) + this->get(0,n-1) ) );

    }
  }

  else{
    /// Calcul des points à l'intérieur de la matrice (idem pour tore et miroir)
    for(i=1; i<n-1 ;i++){


    /// Calcul des points à l'intérieur de la matrice (idem pour tore et miroir)
    for(i=1; i<n-1 ;i++){
        for(j=1; j<n-1 ;j++){
          if (typeid(T) == typeid(int)){ /// Pour le cas où le type est entier on arrondit à l'entier le plus proche
            C2.put(i,j,round(.2*(this->get(i,j)+this->get(i-1,j)+this->get(i,j-1)+this->get(i+1,j)+this->get(i,j+1))));}
          else{ /// Sinon on fait le calcul de manière classique sur les 4 voisins et le point considéré
            C2.put(i,j,.2*(this->get(i,j)+this->get(i-1,j)+this->get(i,j-1)+this->get(i+1,j)+this->get(i,j+1)));}
          }
        }
    /// Calcul des points à la frontière avec la méthode miroir
    if (typeid(T) == typeid(int)){

      for(j=2; j<n-1; j++){
        C2.put(0,j, round(0.2*(this->get(0,j)+this->get(0,j-1)+this->get(0,j+1)+this->get(1,j)+this->get(1,j)))   );
      }

      for(j=2; j<n-1; j++){
        C2.put(n-1,j, round(0.2*(this->get(n-1,j)+this->get(n-1,j-1)+this->get(n-1,j+1)+this->get(n-2,j)+this->get(n-2,j)))   );
      }

      for(i=2; i<n-1; i++){
        C2.put(i,0, round(0.2*(this->get(i,0)+this->get(i-1,0)+this->get(i+1,0)+this->get(i,1)+this->get(i,1)))   );
      }

      for(i=2; i<n-1; i++){
        C2.put(i,n-1, round(0.2*(this->get(i,n-1)+this->get(i-1,n-1)+this->get(i+1,n-1)+this->get(i,n-2)+this->get(i,n-2)))   );
      }
      C2.put(0,0, round(0.2*(this->get(0,0) + this->get(0,1) + this->get(1,0) + this->get(0,1) + this->get(1,0)) ) );
      C2.put(0,n-1, round(0.2*(this->get(0,n-1) + this->get(1,n-1) + this->get(0,n-2) + this->get(1,n-1) + this->get(0,n-2)) ) );
      C2.put(n-1,0, round(0.2*(this->get(n-1,0) + this->get(n-1,1) + this->get(n-2,0) + this->get(n-2,0) + this->get(n-1,1)) ) );
      C2.put(n-1,n-1, round(0.2*(this->get(n-1,n-1) + this->get(n-1,n-2) + this->get(n-2,n-1) + this->get(n-1,n-2) + this->get(n-2,n-1)) ) );
    }

    else{
      for(j=2; j<n-1; j++){
        C2.put(0,j, 0.2*(this->get(0,j)+this->get(0,j-1)+this->get(0,j+1)+this->get(1,j)+this->get(1,j))   );
      }

      for(j=2; j<n-1; j++){
        C2.put(n-1,j, 0.2*(this->get(n-1,j)+this->get(n-1,j-1)+this->get(n-1,j+1)+this->get(n-2,j)+this->get(n-2,j))   );
      }

      for(i=2; i<n-1; i++){
        C2.put(i,0, 0.2*(this->get(i,0)+this->get(i-1,0)+this->get(i+1,0)+this->get(i,1)+this->get(i,1))   );
      }

      for(i=2; i<n-1; i++){
        C2.put(i,n-1, 0.2*(this->get(i,n-1)+this->get(i-1,n-1)+this->get(i+1,n-1)+this->get(i,n-2)+this->get(i,n-2))   );
      }
      C2.put(0,0, 0.2*(this->get(0,0) + this->get(0,1) + this->get(1,0) + this->get(1,0) + this->get(0,1) ) );
      C2.put(0,n-1, 0.2*(this->get(0,n-1) + this->get(1,n-1) + this->get(0,n-2) + this->get(1,n-1) + this->get(0,n-2) ) );
      C2.put(n-1,0, 0.2*(this->get(n-1,0) + this->get(n-1,1) + this->get(n-2,0) + this->get(n-2,0) + this->get(n-1,1) ) );
      C2.put(n-1,n-1, 0.2*(this->get(n-1,n-1) + this->get(n-1,n-2) + this->get(n-2,n-1) + this->get(n-1,n-2) + this->get(n-2,n-1) ) );

    }

    }}

  donnees = C2.donnees;
};
