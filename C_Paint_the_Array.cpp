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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b); 
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int gcdd = a[0];
    for(int i=0;i<n;i+=2){
        gcdd = gcd(gcdd,a[i]);
    }
    int gcdd2 = a[1];
    for(int i=1;i<n;i+=2){
        gcdd2 = gcd(gcdd2,a[i]);
    }
    vector<int> copy = a;
    for(int i=0;i<n;i++){
        if(a[i]%gcdd==0) a[i] = 0;

    }
    bool check1 = true;
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            check1 = false;
            break;
        }
    }
    a = copy;
    for(int i=0;i<n;i++){
        if(a[i]%gcdd2==0) a[i] = 0;
    }
    bool check2 = true;
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            check2 = false;
            break;
        }
    }
    // cout<<gcdd<<" "<<gcdd2<<endl;
    // cout<<check1<<" "<<check2<<endl;
    if(check1==false && check2==false){
        cout<<0<<endl;
        return;
    }
    if(check1==true && check2==false){
        cout<<gcdd<<endl;
        return;
    }
    if(check1==false && check2==true){
        cout<<gcdd2<<endl;
        return;
    }
    cout<<max(gcdd,gcdd2)<<endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
