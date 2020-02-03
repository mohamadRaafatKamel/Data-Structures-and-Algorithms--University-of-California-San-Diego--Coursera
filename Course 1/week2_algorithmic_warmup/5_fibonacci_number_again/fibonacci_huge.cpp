/*Author : Mohamad Raafat Mohamad*/

#include <iostream>
#include <vector>

typedef   long long int   MRM;

using namespace std;

MRM Huge_Fib_MRM(MRM n,MRM m) {
    vector<long long> v;
    v.push_back(0);
    v.push_back(1);
    while (true)
    {
        long long second = v[v.size()-2];
        long long last = v[v.size()-1];
        v.push_back((second+last)%m);
        if((v[v.size()-2]==0)  &&  (v[v.size()-1]==1))
        {
            v.pop_back();
            v.pop_back();
             break;
        }
    }
    long long rem = n%v.size(
);
    return v[rem];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << Huge_Fib_MRM(n, m) << '\n';
}
