#include <iostream>
#include <string>
#include <vector>

/*Fonctions utilisées*/
using std::string;
using std::cout;
using std::vector;

class Point{
private :
  string nom;
  int dimension;
  vector <int> coordonnees;
public :
  Point(int n);
  ~Point();
  float setX(int i, float x);
  float getX(int i);
};
