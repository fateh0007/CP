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
    set<int> unique;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        unique.insert(a[i]);
    }
    vector<int> copy = a;
    reverse(copy.begin(),copy.end());
    if(a==copy){
        cout<<"YES"<<endl;
        return;
    }
    if(n==1||n==2){
        cout<<"YES"<<endl;
        return;
    }
    // if(unique.size()==n){
    //     cout<<"NO"<<endl;
    //     return;
    // }
    int i=0;int j=n-1;
    int x = -1;
    int y = -1;
    while(i<=j){
        if(a[i]!=a[j]){
            x = a[i];
            y = a[j];
            break;
        }
        i++;
        j--;
    }
    //removing x
    vector<int> first;
    for(int i=0;i<n;i++){
        if(a[i]!=x){
            first.push_back(a[i]);
        }
    }
    //removing y
    vector<int> sec;
    for(int i=0;i<n;i++){
        if(a[i]!=y){
            sec.push_back(a[i]);
        }
    }
    vector<int> firstcopy = first;
    vector<int> seccopy = sec;
    reverse(firstcopy.begin(),firstcopy.end());
    reverse(seccopy.begin(),seccopy.end());
    if(first==firstcopy || sec==seccopy){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
