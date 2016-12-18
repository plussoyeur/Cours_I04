#include "exemple.hpp"

int main()

{

  int i, j = 1, k = 2;
  //int nb_max = 5;
  int res;

  std::cout<<"petitexemple \n";
  std::cout<<"pour j = "<<j<< ",k = "<<k<<"\n" ;

  for (i = j; i < nb_max; i++)
    {
      res = (3*j++)+5*++k;
      std::cout<<"res("<<i<<") = " << res <<;
      std::cout<< std::endl;

    }
  return 0;
}
