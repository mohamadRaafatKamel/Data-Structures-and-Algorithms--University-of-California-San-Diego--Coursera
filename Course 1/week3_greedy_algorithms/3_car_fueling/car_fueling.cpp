#include <iostream>
#include <vector>

typedef   long long int  MRM;

using namespace std;

int compute_min_refills(int dist, int tank,int n, vector<int> stops) {
    int numrefill=0,currentDist=0,lastRefill=0;
    while(currentDist <= n){
        while (currentDist <=n && stops[currentDist+1]-stops[lastRefill]<=tank){
            currentDist++;
        }
        if(currentDist == lastRefill){
            return -1;
        }
        if(currentDist <= n){
            numrefill++;
            lastRefill=currentDist;
        }
    }
    return numrefill;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    stops.push_back(0);
    for (size_t i = 1; i < n+1; ++i)
        cin >> stops.at(i);
    stops.push_back(d);//n+1 is point B
    cout << compute_min_refills(d, m,n, stops) << "\n";

    return 0;
}
