#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int optimal_weight(int W, const vector<int> &w ,int n) {
  int val[n+1][W+1]={0};
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= W; ++j) {
        val[i][j] = val[i-1][j];
        if (j>=w[i-1])
            val[i][j] = max(val[i-1][j- w[i-1] ] + w[i-1], val[i][j]);


    }
  }
  return val[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w ,n) << '\n';
}
