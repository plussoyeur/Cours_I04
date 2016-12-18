#include <iostream>
#include <stdlib.h>
#include <vector>

/*Declaration des fonctions utilisees*/
using std::cout;
using std::vector;
using std::endl;

/*Definition de la classe polynome*/
template <typename T> class Poly{
private :
  vector <T> coefficients;
public :
  Poly(){};
  Poly(vector <T> coef);
  Poly(Poly <T> const& P);
  T operator[] (int i);
  vector <T> get_coef();
  int get_degre();
  void affichage();
};
