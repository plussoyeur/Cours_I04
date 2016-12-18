#include "matrices.hpp"
/******************************/
/* Définition du constructeur */
/******************************/

///Constructeur par défaut
template <typename T>
matrice2d<T>::matrice2d(){
  cout << "Appel du contructeur par défaut" << endl;
};

///Definition du constructeur par copie
template <typename T>
matrice2d<T>::matrice2d(matrice2d <T> const& M){
  coefficients = M.coefficients;
  cout << "Appel du constructeur par copie" << endl;
};

///Definition du constructeur par affectation
template <typename T>
matrice2d<T>::matrice2d(vector <vector <int > > coef){
  coefficients = coef;
  cout << "Appel du constructeur par affectation" << endl;
};

/*****************************/
/* Definition du destructeur */
/*****************************/

template <typename T>
matrice2d<T>::~matrice2d(){
  cout << "Appel du destructeur par défaut" << endl;
};

/**************************************************/
/* Définition des fonctions du template utilisées */
/**************************************************/

///Fonction d'insertion d'un élément
template <typename T>
void matrice2d<T>::put(int i, int j, T coef){
  coefficients[i][j] = coef;
};


///Fonction d'obtention d'un élément
template <typename T>
T matrice2d<T>::get(int i, int j){
  return coefficients[i][j];
};

///Fonction d'affichage de la taille de la matrice
template <typename T>
vector <int> matrice2d<T>::size(){
  vector <int> V(2,0);
  V[0] = coefficients.size();
  V[1] = coefficients.size();
  return V;
};


/***********************************/
/* Surcharge des opérateurs usuels */
/***********************************/

/// Surcharge de l'opérateur d'affichage
template <typename T>
std::ostream & operator <<(std::ostream &os, matrice2d <T> M){
  int i,j;
  os << "Matrice de taille : " << M.size()[0] << "x" << M.size()[1] << endl;
  for(i=0; i<M.size()[0]; i++){
    os << "|";
      for(j=0; j<M.size()[1]; j++){
        os << M.get(i,j) << " ";
      }
    os << "|" << endl;
  }
  return os;
};

/// Surcharge de l'opérateur []
template <typename T>
vector <T>& matrice2d<T>::operator[](int i){
  return coefficients[i];
}

/// Surcharge de l'opérateur +
template <typename T>
matrice2d<T> operator+(matrice2d <T> M1, matrice2d <T> M2){
  matrice2d <T> res(M1);
  int i,j;
  if(M1.size()[0] != M2.size()[0]){
    cout << "ERREUR : vous voulez sommer des matrices de taille différentes" << endl;}
  else{
    for(i=0; i<M1.size()[0]; i++){
      for(j=0; j<M1.size()[0]; j++){
        res[i][j] = M1[i][j] + M2[i][j];
      }
    }
  }

  return res;
};


/// Surcharge de l'opérateur =
template <typename T>
matrice2d<T> & matrice2d<T>::operator=(matrice2d<T> M){
  int i, n;
  n = M.size()[1];
  coefficients.resize(n);
  for(i=0; i<n; i++){
    coefficients[i].resize(n);
  }
  coefficients = M.coefficients;
  return *this;
};

/// Surcharge de l'opérateur +=
template <typename T>
matrice2d<T> operator+=(matrice2d <T> & A, matrice2d <T> M){
    A = A + M;
    return A;
};


/***********************/
/* Programme principal */
/***********************/


int main(){
  /// Definition du vecteur de vecteur pour les coefficients
  vector <int> V1(4,1);
  vector <vector <int> > V2(4,V1);
  int i,j;
  /*for(i=0;i<=3;i++){
    for(j=0;j<=3;j++){
      cout << V2[i][j] << endl;
    }
    }*/

  /// test du constructeur par défaut
  matrice2d <int> M1;

  /// test du constructeur par affectation
  matrice2d <int> M2(V2);

  /// test du constructeur par copie
  matrice2d <int> M3(M2);


  /// test de la fonction de taille
  cout << "Taille de la matrice M3 : " << M3.size()[0] << "x" << M3.size()[1] << endl;

  /// test de la fonction get
  cout << "Coefficient (3,4) de la matrice M3 : " << M3.get(2,3) << endl;

  /// test de la fonction put
  M3.put(2,3,6);
  cout << "Coefficient (3,4) de la matrice M3 : " << M3.get(2,3) << endl;


  /// test de la surcharge de <<
  cout <<  M3 << endl;

  /// test de la surcharge de [][]
  cout << "3 1 : " << M3[2][3] << endl;

  M3[1][3] = 8;
  cout << M3 << endl;

  /// test de la surcharge de +
  matrice2d <int> M4(M3+M3);
  cout << M4 << endl;

  /// test de la surcharge = et +=
  M4 = M3 + M4;
  cout << M4 << endl;

  M4 += M3;
  cout << M4 << endl;
  return 0;
}
