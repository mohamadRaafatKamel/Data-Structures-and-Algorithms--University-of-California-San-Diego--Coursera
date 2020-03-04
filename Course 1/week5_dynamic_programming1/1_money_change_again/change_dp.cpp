#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int get_change(int money) {
    int coin[3]={1,3,4};
    int NumCoins;
    //vector<int> MinNumCoins(money+1 , INT8_MAX);
    vector<int> MinNumCoins(money+1);
    MinNumCoins[0]=0;
    for(int m=1;m<=money+1;m++){
        MinNumCoins[ m ] = numeric_limits<int>::max() ;
        for(int i=0;i< 3 ;i++){
            if(m>=coin[i]){
                NumCoins = MinNumCoins[m - coin[i] ] +1  ;
                if (NumCoins < MinNumCoins[m]){//NumCoins!= INT8_MAX  &&
                    MinNumCoins[m] = NumCoins;
                }
            }
        }
    }
    return MinNumCoins[money];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
