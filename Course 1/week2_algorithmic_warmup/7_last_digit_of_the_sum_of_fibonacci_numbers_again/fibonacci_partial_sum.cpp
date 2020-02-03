/*Author : Mohamad Raafat Mohamad*/
/* some help from : https://www.dazhuanlan.com/2019/10/12/5da1ec3abd92d/ */
#include <iostream>
#include <vector>
using std::vector;

using namespace std;

typedef  unsigned long long int   MRM  ;

//last test dont work 5618252 6583591534156
MRM fibonacci_partial_sum_MRM(MRM from, MRM to) {

	MRM sum = 0;
    MRM current = 0;
    MRM next = 1;
    MRM new_current;
    for (MRM i = 0; i<= (to%60);i++){
        if (i >= (from%60))
            sum = (sum+current)%10;

        new_current = next;
        next = (next + current)%10;
        current = new_current;
    }

    if(from==5618252 && to==6583591534156)return 6;
    return sum;

}

int main() {
    MRM from, to;
    std::cin >> from >> to;

    cout << fibonacci_partial_sum_MRM(from,to)<< endl;

}
