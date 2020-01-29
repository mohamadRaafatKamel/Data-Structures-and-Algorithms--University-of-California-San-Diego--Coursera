/*
Author : Mohamad Raafat Mohamad
the Greatest Common Divisor by Using the Euclidian Algorithm
https://www.youtube.com/watch?v=JUzYl1TYMcU
*/

#include <iostream>
#include <cmath>

using namespace std;

double gcd_MRM(long a, long b) {

  if(b==0){
    return a;
  }
  return gcd_MRM(b,a%b);
}

int main() {
  long a,b,t1,t2;
  cin >> t1 >> t2;
  if(t1!=t2){
    a=max(t1,t2);
    b=min(t1,t2);
    cout << gcd_MRM(a, b) << endl;
  }else
    cout << t1 << endl;
  return 0;
}
