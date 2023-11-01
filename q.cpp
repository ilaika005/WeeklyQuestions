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

    //defining variable
    int n, x; cin >> n >> x;
    int more = 0;
    int less = 0;
    int exact = 0;
    //running alg
    while(n--){
        //getting current number, and acting accordingly
        int num; cin >> num;
        if (num > x){
            more++;
        }
        else if (num < x){
            less++;
        }
        else{
            exact++;
        }
    }
    //dividing into 2 cases: if the nubmer is present, or not.
    if (!exact){
        //if it is, print the difference between how many numbers are more/less. if there are more less than more(or exact), add 1.
        if (less >= more){
            cout << less - more + 1 << endl;
        }
        else{
            cout << more - less << endl;
        }
    }
    else{
        //if it isn't, if the number is already at the place it's supposed to be - print 0
        if ((int)((more + less + exact + 1) / 2) > less && (int)((more + less + exact + 1) / 2) <= less + exact){
            cout << 0 << endl;
        }
        else{
            //else, print the differnece between less, more and exact. if there are more less than more add 1.
            if (less > more){
                cout << abs(less - more - exact) + 1 << endl;
            }
            else{
                cout << abs(more - less - exact) << endl;
            }
        }
    }
}