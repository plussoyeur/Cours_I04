# include <iostream>
# include <cmath>

/* Fonctions utilisees */
using std::cout;
using std::endl;
using std::cin;


float suite_fl(int n)
{
  if( n==0 )
    return 2;
  else if( n == 1)
    return -4;
  else
    {float un_1 = suite_fl(n-1);
    return 111.0 - 1130.0/un_1 + 3000.0/(un_1*suite_fl(n-2));
    }
}

double suite_d(int n)
{
  if( n==0 )
    return 2;
  else if( n == 1)
    return -4;
  else
    {
    double un_1 = suite_d(n-1);
    return 111.0 - 1130.0/un_1 + 3000.0/(un_1*suite_d(n-2));
    }
}


int main()
{
  /* Declarations des variables*/
  int n,i;
  double u;

  cout << "Donner la valeur du rang n pour l'affichage de u_0...u_n" << endl;
  cin >> n;

  cout << "Pour les float" << endl;
  for (i = 0; i <= n; i++)
    {
      u = (4*pow(5.0,i+1) - 3*pow(6.0,i+1))/(4*pow(5.0,i) - 3*pow(6.0,i));
        cout << "La valeur de u_" << i << " est : " << "fl : " << suite_fl(i) << "     ---double : " << suite_d(i) << "      ---vraie : " << u << endl;

    }


   return 0;
}
