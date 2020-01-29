/*Author : Mohamad Raafat Mohamad*/
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

string sumString(string str1,string str2){

    if (str1.length() > str2.length())
        swap(str1, str2);

    string reslt = "";
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        reslt.push_back(sum%10 + '0');

        // Calculate carry for next step
        carry = sum/10;
    }

    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        reslt.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining carry
    if (carry)
        reslt.push_back(carry+'0');

    // reverse resultant string
    reverse(reslt.begin(), reslt.end());
    return reslt;
}

string get_fibonacci_last_digit_naive(int n) {
    if (n == 1)
        return "1";
    if (n == 0)
        return "0";

    string previous = "0";
    string current  = "1";
    string tmp_previous ;

    for (int i = 0; i < n - 1; ++i) {
        tmp_previous = previous;
        previous = current;
        current = sumString(tmp_previous , current);
    }

    return current ;
}

//int main() {
//    long n;
//    std::cin >> n;
//    string c = get_fibonacci_last_digit_naive(n);
    //std::cout << c << '\n';
//    std::cout << c[c.length()-1]<< '\n';

//    }
 //

 typedef   long long int               ll;

ll fibCalc(int n)
{
	vector<ll> fib(n + 1);
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= n; i++)
		fib[i] = (fib[i - 1]%10 + fib[i - 2]%10)%10;
	return fib[n];
}

int main()
{
	int n;
	cin >> n;
	cout << fibCalc(n) << endl;
}
