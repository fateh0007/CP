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
  
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n,rk,ck,rd,cd;
        cin>>n>>rk>>ck>>rd>>cd;

        if(rk>rd){
            if(ck>cd){
                cout<< max(n-ck,n-rk) + min(ck-cd, rk-rd) + 1<<endl; 
            }
            else if(ck<cd){
                cout<<max(ck-0,n-rk) + min(abs(ck-cd), abs(rk-rd))<<endl;
            }else{//same column
                cout<< (n-rk) + (rk-rd)<<endl;
            }
        }
        else if(rk<rd){
            if(ck<cd){
                cout<< max(ck-0,rk-0) + min(cd-ck, rd-rk)  <<endl;
            }else if(ck>cd){
                cout<< max(n-ck,rk-0) + min(ck-cd, rd-rk) <<endl;
            }else{//same column
                cout<<rk-0 + rd-rk <<endl;
            }
        }
        else{//rk == rd
            if(ck<cd){
                cout<<ck-0 + 1 + cd-ck-1<<endl;
            }else if(ck>cd){
                cout<< (n-ck) + (ck-cd)<<endl;
            }
        }
    }
}