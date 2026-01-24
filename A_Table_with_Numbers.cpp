#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map> 
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include<numeric>
using namespace std;
#define int long long 
const int mod = 1e9 + 7;
bool isPalindrome(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}
void solve() {
    int n,h,l;
    cin>>n>>h>>l;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // sort(a.begin(),a.end());
    int row=0;
    int col =0;
    for(int i=0;i<n;i++){
        if(a[i]<=h){
            row++;
        }
        if(a[i]<=l){
            col++;
        }
    }
    int mini = min(row,col);
    int maxi = max(row,col);
    // cout<<maxi<<" "<<mini<<endl;
    if(maxi>=2*mini){
        cout<<mini<<endl;
    }
    else{
        cout<<maxi/2<<endl;;
    }
    
    // int sum =0 ;
    // for(int i=0;i<n;i+=2){
    //     int row = a[i];
    //     int col = a[i+1];
    //     if(row<=h && col<=l){
    //         sum+=1;
    //     }
    // }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
