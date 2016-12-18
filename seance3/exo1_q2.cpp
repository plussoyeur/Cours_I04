#include <iostream>
#include <cmath>
/* Declaration des fonctions utlisées */
using std::cout;
using std::endl;

/*Programme utilisant un entier plus grand que la capacité des variables utiliseées*/

int main()
{
  short int sent = pow(2,15)-3;
  int i = 0;

  cout << "Suite d'entiers plus grande que la taille maximale d'un short int : \n" ;
  for(i = 0; i < 5; i++)
    {
      cout << sent << endl;
      sent ++;
    }

  return 0;

}
