#include "Point.hpp"

/* Definition du constructeur nul*/
Point::Point(int n){
  int i;
  dimension = n;
  coordonnees.reserve(dimension);
  for (i = 1; dimension; i++){
    coordonnees.push_back(0);}
}

/*Definition du destructeur*/
Point::~Point(){}


int main(){
  Point vect(10);
  return 0;
}
