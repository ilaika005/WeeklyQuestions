#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    //Things to make cpp faster
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //input string
    string s;
    cin >> s;

    //Arrays: p - save the last instance of a letter in the string. ans - The answer.
    vector<ll> p(26, -1), ans(26);

    for(int i = 0; i < s.length(); i ++) {
        //Save the last instance of a letter in the string
        p[s[i] - 'a'] = i;
        //Create x, an array that's exactly the same as p, sorting it/
        vector<ll> x = p;
        x.push_back(-1);

        sort(x.begin(), x.end());

        /*The main algorithm, a little long to explain, but:
        Basically, you save the last instance of a letter in the string, then you sort it(x) and
        retract one by one. How does this work?
        To get the number of single digit increments, retract the biggest from the second biggest, 
        to get the number of double digit increments, retract the second largest from the third largest, and so on.
        */ 
        for(int i = 1; i <= 26; i ++)
            ans[26 - i] += x[i] - x[i - 1];
    }

    //popping all of the irrelevent items in the array
    while(ans.back() <= 0) {
        ans.pop_back();
    }

    //print the ans array.
    cout << ans.size() << endl;
    for(auto x : ans)
        cout << x << endl;
}