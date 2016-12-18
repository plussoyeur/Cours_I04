#include <iostream>
using std::cout;

int main()
{
  int i = 8, j = 5;
  float x = 0.005f, y = -0.001f;
  char c = 'c', d = 'd';
  float a,b;

  a = (3*i - 2*j)%(2*d - c);
  cout<<"a : " << a << "\n" << "2d-c : " << 2*d-c << "\n" << 14%101 << "\n";
  cout<< (i >= j) << "\n";
  cout<< (c==99) << "\n";
  cout<< ((i>0)&&(j<=5)) << "\n";
  cout<< ((i>0)&&(j<5)) << "\n";
  cout<< ((x>y)&&(i>0)||(j<5)) << "\n";
  cout<< ((x<y)&&(i>0)||(j<5)) << "\n";
}
