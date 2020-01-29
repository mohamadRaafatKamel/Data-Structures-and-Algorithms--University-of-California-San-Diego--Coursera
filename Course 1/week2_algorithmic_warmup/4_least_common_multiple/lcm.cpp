/*Author : Mohamad Raafat Mohamad*/
#include <iostream>
#include<algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <list>

typedef   long long int   MRM;

using namespace std;

double gcd_MRM(long a, long b) {

  if(b==0){
    return a;
  }
  return gcd_MRM(b,a%b);
}


MRM lcm_MRM(MRM a, MRM b) {
  if(a==b){
    return a;
  }else{

    return a*b/gcd_MRM(max(a,b),min(a,b));
  }

}



int main() {
  MRM a, b;
  std::cin >> a>>b;
  std::cout << lcm_MRM(a, b)<< std::endl;
  return 0;
}


