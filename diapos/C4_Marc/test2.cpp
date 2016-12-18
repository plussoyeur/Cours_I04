#include <iostream>

using namespace std;

class A {
public:
  int x[50];
  void f() {
    this->y = x[6];
  }

private:
  int y;

};

double f3(int& x)
{
  x = x + 3;
  double y = x*2.0;
  return y;
}

double f4(A z)
{
  return z.x[4] + 5;
}
double f4a(const A *z)
{
  return (*z).x[4] + 5;
}
double f4b(const A &z)
{
  //z.x[6] = 6;
  return z.x[4] + 5;
}

int main(int argc, char **argv) 
{
  double b, c, d;
  int a;

  a = 2;

  std::cout << "avant a = " << a << std::endl;

  d = f3(a);

  std::cout << "apres f3: a = " << a << std::endl;

  A v;
  v.x[4] = 5;
  //v.y = 3;
  v.f();
  f4b(v);

  return 0;

}
