#include <iostream>

typedef   long long int  MRM;

using namespace std;

MRM get_change(MRM m) {

  int n=0,m2,m3;

  m2=m/10;
  n+=m2;// coin 10

  m2=m%10;
  m3=m2/5;
  n+=m3;// coin 5

  m3=m2%5;
  n+=m3;// ooin 1
  return n;
}

int main() {
  MRM m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
