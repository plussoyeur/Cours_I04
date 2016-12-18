#include <iostream>
/* Declaration des fonctions utlisées */
using std::cout;
using std::endl;

/*Programme qui donne la taille des différentes représentations*/
int main()
{
  /*Declaration des variables*/
  int ent;
  long int lent;
  long long int llent;
  unsigned int uent;
  short int sent;

  cout << "Taille :\n";
  cout << "Type int : " << sizeof(int) << "\n";
  cout << "Type long int : " << sizeof(long int) << "\n";
  cout << "Taille long long int : " << sizeof(long long int) << "\n";
  cout << "Taille unsigned int : " << sizeof(unsigned int) << "\n";
  cout << "Taille short int : " << sizeof(short int) << "\n" << endl;

  return 0;
}
