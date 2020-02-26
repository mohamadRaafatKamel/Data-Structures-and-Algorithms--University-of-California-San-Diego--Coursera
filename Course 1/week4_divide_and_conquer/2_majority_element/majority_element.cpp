#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef   long long int  MRM;

bool ContainMajority(vector<int> Arr, int n) {
	map<int, int> Freq;
	for (size_t i = 0; i < n; i++)
		Freq[Arr[i]]++;

	for (int i = 0; i <n; i++)
		if (Freq[Arr[i]] > (n / 2))
			return true;

	return false;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> a[i];
  }


  cout << ContainMajority(a, n) << endl;

  return 0;
}
