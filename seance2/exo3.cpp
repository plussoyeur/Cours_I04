#include <iostream>

/*Declaration des fonctions utilisées*/
using std::cin;
using std::cout;
using std::endl;

int main()
{
  /*Declaration des variables utilisees*/
  int n, i;

  cout <<"Entrer un entier : \n"<<endl;
  cin >> n;
  cout << "Liste des entiers de " << n << " à " << n << "+5 \n";
  cout << n << "\n";

  for (i = 1; i < 10; i++)
    {
      cout << n+i << "\n";
    }

  return 0;

}
