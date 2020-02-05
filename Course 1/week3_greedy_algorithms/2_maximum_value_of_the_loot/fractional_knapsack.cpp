#include <iostream>
#include <vector>
#include<algorithm>
#include <cmath>

typedef   long long int  MRM;

using namespace std;

int max_vector(vector<double> v, int n){
    double m=v[0],mi=0;
    for (int i = 1; i < n; i++) {
      if(m<v[i] && v[i]!=0){
        m=v[i],mi=i;
      }
    }
    return mi;
}

double get_optimal_value(int n,int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0,best;

  vector<double> vw(n);
  for (int i = 0; i < n; i++) {
    vw[i] =values[i] /(double) weights[i];
  }

  while (capacity !=0 && n!=0){
    if(n==1){
        best=0;
        n=0;
    }else
        best=max_vector(vw , n);

    if(capacity>=weights[best]){
        capacity-=weights[best];
        vw[best]=0;
        value+=values[best];
    }
    else{
        value=value+(vw[best]*capacity);
        capacity=0;
    }
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(n,capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
