#include <bits/stdc++.h>
using namespace std;

string key(const vector<string>& v){
    string r;
    for (auto& s: v){ r+=s; r.push_back('\n'); }
    return r;
}

vector<vector<string>> neighbors(const vector<string>& v){
    int n=v.size();
    vector<vector<string>> res;
    int sum = 0;
    map<string,int> mp;
    for(int i=0;i<n;i++){
        sum+=i;
        mp[v[i]]=sum;
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int len=j-i+1;
            vector<string> cut(v.begin()+i,v.begin()+j+1);
            vector<string> rest;
            rest.reserve(n-len);
            rest.insert(rest.end(),v.begin(),v.begin()+i);
            rest.insert(rest.end(),v.begin()+j+1,v.end());
            for(int k=0;k<=n-len;k++){
                if(k==i) continue;
                vector<string> nv=rest;
                nv.insert(nv.begin()+k,cut.begin(),cut.end());
                res.push_back(move(nv));
            }
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    if(!(cin>>n)) return 0;
    string tmp; getline(cin,tmp);
    getline(cin,tmp);
    vector<string> A(n),B(n);
    for(int i=0;i<n;i++) getline(cin,A[i]);
    getline(cin,tmp);
    for(int i=0;i<n;i++) getline(cin,B[i]);
    if(A==B){ cout<<0; return 0; }
    queue<vector<string>> qa,qb;
    unordered_map<string,int> da,db;
    string ka=key(A), kb=key(B);
    qa.push(A); qb.push(B);
    da[ka]=0; db[kb]=0;
    while(!qa.empty() && !qb.empty()){
        if(qa.size()<=qb.size()){
            int sz=qa.size();
            while(sz--){
                auto cur=qa.front(); qa.pop();
                int d=da[key(cur)];
                for(auto& nx: neighbors(cur)){
                    string k=key(nx);
                    if(da.count(k)) continue;
                    if(db.count(k)){ cout<<d+1+db[k]; return 0; }
                    da[k]=d+1; qa.push(move(nx));
                }
            }
        }else{
            int sz=qb.size();
            while(sz--){
                auto cur=qb.front(); qb.pop();
                int d=db[key(cur)];
                for(auto& nx: neighbors(cur)){
                    string k=key(nx);
                    if(db.count(k)) continue;
                    if(da.count(k)){ cout<<d+1+da[k]; return 0; }
                    db[k]=d+1; qb.push(move(nx));
                }
            }
        }
    }
    
}