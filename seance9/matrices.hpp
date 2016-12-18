#include <iostream>
#include <vector>
#include <stdlib.h>

/*Déclaration des fonctions utilisées*/
using std::cout;
using std::cerr;
using std::vector;
using std::endl;

/*Définition de la classe polynôme*/
template <typename T> class matrice2d{
private :
  vector <vector <T> > coefficients;
public :
  matrice2d();   ///accolades servent à définir le constructeur
  matrice2d(matrice2d <T> const& M);
  matrice2d(vector <vector <int> > coef);
  ~matrice2d();
  T get(int i, int j);
  void put(int i, int j, T coef);
  vector <int> size();
  vector <T> & operator[](int i);
  matrice2d <T> & operator=(matrice2d<T> M1);
};
