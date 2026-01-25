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
    int n;
    cin>>n;
    string a,b;
    cin>>a;
    cin>>b;
    vector<bool> canFlip(n);
    int cnt0 = 0;
    int cnt1 = 0;
    for(int i=0;i<n;i++){
        if(a[i]=='0'){
            cnt0++;
        }else{
            cnt1++;
        }
        if(cnt0==cnt1){
            canFlip[i] = true;
        }
    }
    bool isFlipped = false;
    bool isPoss = true;
    for(int i=n-1;i>=0;i--){
        if(isFlipped==false){
            if(a[i]!=b[i]){
                if(canFlip[i]){
                    isFlipped ^= true;
                }else{
                    isPoss = false;
                    break;
                }
            }
        }else{
            if(a[i]==b[i]){
                if(canFlip[i]){
                    isFlipped ^= true;
                }else{
                    isPoss = false;
                    break;
                }
            }
        }
    }
    if(isPoss){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
