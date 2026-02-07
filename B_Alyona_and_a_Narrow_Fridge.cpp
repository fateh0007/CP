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
#define int  long long 
const int mod = 1e9 + 7;

void solve() {
    int n,h;
    cin>>n>>h;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxi = 0;
    vector<int> temp;
    for(int i=0;i<n;i++){
        temp.push_back(a[i]);
        sort(temp.rbegin(),temp.rend());
        int x = h;
        bool flag = true;
        for(int j=0;j<temp.size();j+=2){
            if(temp[j]<=x){
                x-=temp[j];
            }
            else{
                flag = false;
            }
        }
        if(flag==true) {
            if(temp.size()>maxi){
                maxi = temp.size();
            }
        }
        else break;
    }
    cout<<maxi<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin >> t;
    while (t--) solve();
}
