#include <iostream>
#include <vector>

/* Declaration des fonctions utlisées */
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
  /* Declaration des variables*/
  int i, n;

  /* Demande de n à l'utilisateur */
  cout << "Entrer la valeur de l'entier n \n";
  cin >> n;

  vector<int> u(n);

  u[0] = 1;
  u[1] = 1;

  for (i = 2; i <= n; i++)
    {
      u[i] = u[i-1] + u[i-2];
    }

  cout << "La valeur de u(n) est : \n" << u[n] << "\n" << endl;

  return 0;
}
