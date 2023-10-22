#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    //bs to make cpp faster
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //inputting t, the amount of numbers
    int t;cin>>t;
    while(t--){
        //inputting test case
        ll n;cin>>n;
        //if its odd, the answer is always 2(n-1, 1), this can be proved mathematically.
        if (n&1){
            cout << 2 << endl;
            continue;
        }
        //else, make k equal to n and run the alg
        ll k = n;
        //divide n by 2 until its odd
        while(! (n & 1)) n/=2;
        //if n is 1, which is a power of 2, the answer is -1(this can be proved mathmatically.)
        if(n == 1){
            cout << -1 << endl;
            continue;
        }
        //else, if the number is too large( - or (n^2 + n)/2 <= k), the answer is just n
        if(n<=2e9&&(n * (n+1))/2 <= k) {
            cout << n << endl;
            continue;
        }
        //else, the answer is just the amount of times we divided by 2 times 2.
        cout << 2 * (k/n) << endl;
        //all of the solution is to identify the pattern and writing it, as well as knowing math. This is all pattern-recognition etc'
    }
}