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
    int a,b;
    cin>>a>>b;
    int num = min(a,b);
    int target = max(a,b);
    int cnt =0;
    while(num*8<=target){
        num*=8;
        cnt++;
    }
    while(num*4<=target){
        num*=4;
        cnt++;
    }
    while(num*2<=target){
        num*=2;
        cnt++;
    }
    if(num!=target){
        cout<<-1<<endl;
        return;
    }
    cout<<cnt<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
