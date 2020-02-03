/*Author : Mohamad Raafat Mohamad*/
/* some help from : https://www.dazhuanlan.com/2019/10/12/5da1ec3abd92d/ */
#include <iostream>
#include <vector>

using namespace std;

typedef   long long int   MRM;

MRM fibonacci_sum_naive(MRM n) {
    if (n <= 1)
        return n;


    MRM previous = 0;
    MRM current  = 1;
    MRM sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        MRM tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }
    cout << current <<'\n' <<sum<<'\n';
    return (2*current + previous - 1) % 10;
}

MRM last_sum_digit_MRM(MRM n) {

    //int A [1];

    if (n <= 1){
        return n;
    }
    int check =0;
    MRM period,t;

    //if (n>=500000){check=1;n-=500000;}

    vector<int> A ;

    if (check==0){
        A.push_back(0);
        A.push_back(1);
    }

    if(check==1){
        A[0]=5; //f[500000]
        A[1] =6; //f[500001]
        //period=60;
        //std::cout <<"1"<<'\n';
    }



    for (int i = 2; i <= n; ++i) {
        A.push_back((A[i-1] + A[i-2]) % 10);
        if (A[i] == 1 && A[i-1] == 9){
            period = i+1;
            break;
        }
    }
    //return (2*A[n] + A[n-1] - 1) % 10;
    //period+=period2;
    t = n % (period);
    if (t == 0)
        t = period-1;

    //cout << period<<'\n';
    return (2*A[t] + A[t-1] - 1) % 10;


}

int main() {
    MRM n = 0;
    std::cin >> n;
    std::cout << last_sum_digit_MRM(n);
}
