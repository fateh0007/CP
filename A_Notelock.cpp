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
using namespace std;
#define int long long
const int mod = 1e9+7;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt = 0;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='1'){
            int x = k-1;
            int j = i-1;
            bool flag = false;
            while(j>=0 && x>0){
                if(s[j]=='1'){
                    flag = true;
                    break;
                }
                j--;
                x--;
            }
                
            if(flag == false){
                cnt++;
            }
            i = j+1;
        }
    }
    cout<<cnt<<endl;
}
  
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}