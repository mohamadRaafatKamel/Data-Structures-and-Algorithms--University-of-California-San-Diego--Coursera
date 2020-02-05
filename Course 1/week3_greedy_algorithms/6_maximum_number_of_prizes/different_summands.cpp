#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int i = 1;
  while (1){
    if (n - i >= 0){
        n -= i;
        summands.push_back(i);
        i ++;
    }else{
        summands[summands.size() - 1] += n;
        break;
    }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
