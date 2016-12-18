#include "template_premiere_version_poly.hpp"

/*Definition des constructeurs*/
template <typename T> /// constructeur par affectation
Poly<T>::Poly(vector <T> coef){
  coefficients = coef;
}

template <typename T> ///contructeur par recopie
Poly<T>::Poly(Poly <T> const& P){
  coefficients = P.coefficients;
}


/* Définition des fonctions du template */
template <typename T>
vector <T> Poly<T>::get_coef(){
  return coefficients;
}

template <typename T>
int Poly<T>::get_degre(){
  return coefficients.size();
}

template <typename T>
void Poly<T>::affichage(){
  int i;
  for(i = 0; i < coefficients.size(); i++){
    cout <<
  }
}

/* Surcharge des opérateurs usuels */
template <typename T>
T Poly<T>::operator[](int i){
  return coefficients[i];
}

template <typename T>
Poly<T> operator +(Poly <T> &P, Poly <T> &Q){
  vector <T> C;
  int i;
  if(P.get_degre() >= Q.get_degre()){
    for(i = 0; i < P.get_degre(); i++){
      C.push_back(P.get_coef()[i]);}
    for(i = 0; i < Q.get_degre(); i++){
      C[i] += Q[i];}
  }
  else{
    for(i = 0; i < Q.get_degre(); i++){
      C.push_back(Q.get_coef()[i]);}
    for(i = 0; i < P.get_degre(); i++){
      C[i] += P[i];}
    }
  return Poly<T>(C);
}



template <typename T>
Poly<T> operator -(Poly <T> &P, Poly <T> &Q){
  vector <T> C;
  int i;
  if(P.get_degre() >= Q.get_degre()){
    for(i = 0; i <  P.get_degre(); i++){
      C.push_back(P.get_coef()[i]);}
    for(i = 0; i <  Q.get_degre(); i++){
      C[i] -= Q[i];}
  }
  else{
    for(i = 0; i <  Q.get_degre(); i++){
      C.push_back(-(Q.get_coef()[i]));}
    for(i = 0; i <  P.get_degre(); i++){
      C[i] += P[i];}
    }
  return Poly<T>(C);
}


template <typename T>
Poly<T> operator *(Poly <T> &P, Poly <T> &Q){
  vector <T> C;
  int i, j;

  for(i=0; i <  P.get_degre()+Q.get_degre(); i++){
    for(j=0; j<=i; j++){
      C.push_back(P[j]*Q[i-j]);
    }
  }
  return Poly<T>(C);
}


/* PROGRAMME PRINCIPAL */
int main(){
  vector <int> C1, C2;
  int i;

  for(i=1; i<10; i++){
    C1.push_back(i);
  }

  for(i=1; i<20; i++){
    C2.push_back(i);
  }

  Poly <int> P1(C1);
  Poly <int> P2(C2);

  cout << "Coefficients 5 de P1 : " << P1[5] << endl;

  Poly <int> Q = P2 - P1;

  cout << "Coeefficients 5 de P1+P2 : " << Q[5] << endl;

  Poly <int> R = P2*P1;

  cout << "Coefficients 5 de P1*P2 : " << R[5] << endl;
  return 0;
}
