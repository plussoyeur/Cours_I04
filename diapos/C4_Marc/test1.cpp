#include <iostream>
#include "f37.h"

#define AA 2+5


int f()
{

  const double z = 3.5;

  return AA+5;
  //  return 7+5;
}

using namespace std;

class A {
public:
  int x[50];
  void f() {
    y = x[6];
  }

private:
  int y;

};

double f(int x)
{
  x = x + 3;
  double y = x*2.0;
  return y;
}

double f2(int *x)
{
  *x = *x + 3;
  double y = *x*2.0;
  double y2 = 2.0**x;
  return y;
}

double f3(int& x)
{
  x = x + 3;
  double y = x*2.0;
  return y;
}

int main(int argc, char **argv) 
{
  double b, c, d;
  int a;

  a = 2;

  (std::cout << "avant a = ") << a << std::endl;

  b = f(a);
  std::cout << "apres f: a = " << a << std::endl;

  c = f2(&a);

  std::cout << "apres f2: a = " << a << std::endl;

  d = f3(a);

  std::cout << "apres f3: a = " << a << std::endl;

  f37(4);

  A v;
  v.x[4] = 5;
  //v.y = 3;

  return 0;

}
