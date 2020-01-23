#include <iostream>
#include <cmath>

using namespace std;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

double gcd_fast(double a, double b) {

  if(b==0){
    return a;
  }
  double remenderA = fmod(a,b);
  cout << b<<"  " <<remenderA << endl;
  return gcd_fast(b,remenderA);
}

int main() {
  double a=3918848;
  double b=1653264;
  //cin >> a >> b;
  cout << gcd_fast(a, b) << endl;
  return 0;
}
