#include <iostream>
#include <cassert>
#include <vector>

typedef   long long int  MRM;

using namespace std;

int binary_search_MRM(const vector<int> a, int k, int left, int right) {
  int mid;

  if(k > a[right]) return -1;

  while (left <= right){

    mid=(left + ((right-left)/2) );

    if(a[mid] == k)return mid;

    if(a[mid]> k)
        right=mid-1;
    else
        left=mid+1;
  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //std::cout << linear_search(a, b[i]) << ' ';
    //if(b[i] > a[n-1]) return -1;
    cout << binary_search_MRM(a, b[i],0,n-1) << ' ';
  }
}
