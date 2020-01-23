#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (long long first = 0; first < n; ++first) {
        for (long long second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<long long>& numbers) {
    int n = numbers.size();

    int max1=-1;
    for (int i = 0; i < n; ++i) {
        if(max1==-1 || numbers[i]>numbers[max1]){
            max1=i;
        }
    }

    int max2=-1;
    for (int j = 0; j < n; ++j) {
        if((j!=max1)&&(max2==-1 || numbers[j]>numbers[max2])){
            max2=j;
        }
    }

    return numbers[max1]*numbers[max2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";

    return 0;
}
