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
    string s;
    cin>>s;
    int cntB=0,cntS=0,cntC=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='B') cntB++;
        else if(s[i]=='S') cntS++;
        else cntC++;
    }
    int nb,ns,nc;
    cin>>nb>>ns>>nc;
    int pb,ps,pc;
    cin>>pb>>ps>>pc;
    int r ;
    cin>>r;
    bool flag = true;
    int cnt =0;
    while(r>=min(pb,min(ps,pc)) && flag==true){
        for(int i=0;i<s.size();i++){
            if(s[i]=='B'){
                if(nb>0){
                    nb--;
                }else{
                    if(r>=pb){
                        r-=pb;
                    }else{
                        flag = false;
                        break;
                    }
                }

            }else if(s[i]=='S'){
                if(ns>0){
                    ns--;
                }else{
                    if(r>=ps){
                        r-=ps;
                    }else{
                        flag = false;
                        break;
                    }
                }
            }else{
                if(nc>0){
                    nc--;
                }else{
                    if(r>=pc){
                        r-=pc;
                    }else{
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag) cnt++;
        if(nb==0 && nc==0 && ns==0 && r>=max(cntB*pb,max(cntS*ps,cntC*pc))){
            int sum = cntB*pb + cntS*ps + cntC*pc;
            int add = r/sum;
            cnt+=add;
            break;
        }
        if(cntC!=0 && nc==0 && cntS==0 && cntB==0){
            int costC = cntC*pc;
            int add = r/costC;
            cnt+=add;
            break;
        }else if(cntS!=0 && ns==0 && cntC==0 && cntB==0){
            int costS = cntS*ps;
            int add = r/costS;
            cnt+=add;
            break;
        }
        else if(cntB!=0 && nb==0 && cntC==0 && cntS==0){
            int costB = cntB*pb;
            int add = r/costB;
            cnt+=add;
            break;
        }else if(cntC!=0 && nc==0 && cntS!=0 && ns==0 && cntB==0){
            int costC = cntC*pc;
            int costS = cntS*ps;
            int totalCost = costC + costS;
            int add = r/totalCost;
            cnt+=add;
            break;
        }else if(cntC!=0 && nc==0 && cntB!=0 && nb==0 && cntS==0){
            int costC = cntC*pc;
            int costB = cntB*pb;
            int totalCost = costC + costB;
            int add = r/totalCost;
            cnt+=add;
            break;
        }else if(cntB!=0 && nb==0 && cntS!=0 && ns==0 && cntC==0){
            int costB = cntB*pb;
            int costS = cntS*ps;
            int totalCost = costB + costS;
            int add = r/totalCost;
            cnt+=add;
            break;
        }
    }
    cout<<cnt<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
