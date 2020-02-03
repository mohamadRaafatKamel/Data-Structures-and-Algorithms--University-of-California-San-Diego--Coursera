/*Author : Mohamad Raafat Mohamad*/
#include <iostream>
#include <cassert>

using namespace std;

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {

    long long fibList [n];

    for(int i=0; i<=n;i++){
        if(i<=1){
            fibList[i]=i;
        }else{
            fibList[i]=fibList[i-1]+fibList[i-2];
        }
    }
    return fibList[n];
}

void test_solution() {
    //assert(fibonacci_fast(3) == 2);
    //assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 40; ++n)
        if(fibonacci_fast(n) == fibonacci_naive(n)){
            cout<< n <<" ok"<<'\n';
        }else{
            cout<< n <<" not Work"<<'\n';
        }

}

int main() {
    int n = 0;
    cin >> n;
    //cout << fibonacci_naive(n) << '\n';
    //test_solution();
    cout << fibonacci_fast(n) << '\n';
    return 0;
}
