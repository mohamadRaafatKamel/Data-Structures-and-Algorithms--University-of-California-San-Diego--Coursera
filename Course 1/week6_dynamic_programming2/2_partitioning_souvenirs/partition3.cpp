#include <iostream>
#include <vector>

using namespace std;

bool subsetSum(vector<int> &S,int n, int a, int b, int c){
    if(a==0 && b==0 && c==0){
        return true;
    }

    bool A = false;
    if(a - S[n] >=0){
        A = subsetSum(S, n-1, a-S[n], b, c);
    }

    bool B = false;
    if (!A && (b - S[n] >=0)){
        B = subsetSum(S, n-1, a, b-S[n], c);
    }

    bool C = false;
    if ((!A&&!B)&&(c-S[n]>=0)){
        C = subsetSum(S, n-1, a, b, c-S[n]);
    }

    return A||B||C;
}

int partition3(vector<int> &A ,int n) {
  if(n<3)
    return 0;

  int sum =0;
  for(int i=0; i<n; i++){
    sum += A[i];
  }

  return ((sum%3)==0 && subsetSum(A, n-1, sum/3, sum/3, sum/3))?1:0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A , n) << '\n';
}
