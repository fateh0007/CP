#include <bits/stdc++.h>
using namespace std;

static string pack(const vector<int>& a){
    string s; s.resize(a.size());
    for(size_t i=0;i<a.size();++i) s[i]=char(a[i]);
    return s;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int E; if(!(cin>>E)) return 0;
    vector<pair<int,int>> cur(E), expE(E);
    set<int> nodes;
    for(int i=0;i<E;i++){cin>>cur[i].first>>cur[i].second; nodes.insert(cur[i].first); nodes.insert(cur[i].second);}
    for(int i=0;i<E;i++){cin>>expE[i].first>>expE[i].second; nodes.insert(expE[i].first); nodes.insert(expE[i].second);}
    vector<int> id(nodes.begin(),nodes.end());
    int N=id.size();
    unordered_map<int,int> toIdx;
    for(int i=0;i<N;i++) toIdx[id[i]]=i;

    vector<vector<int>> G(N), H(N);
    vector<vector<int>> adjG(N, vector<int>(N,0)), adjH(N, vector<int>(N,0));
    for(auto &e:cur){int u=toIdx[e.first], v=toIdx[e.second]; if(!adjG[u][v]){G[u].push_back(v); G[v].push_back(u); adjG[u][v]=adjG[v][u]=1;}}
    for(auto &e:expE){int u=toIdx[e.first], v=toIdx[e.second]; if(!adjH[u][v]){H[u].push_back(v); H[v].push_back(u); adjH[u][v]=adjH[v][u]=1;}}

    vector<int> order(N); iota(order.begin(),order.end(),0);
    sort(order.begin(),order.end(),[&](int a,int b){return G[a].size()>G[b].size();});

    vector<int> mapGH(N,-1), usedH(N,0);
    vector<vector<int>> isos;
    function<void(int)> dfsIso = [&](int k){
        if(k==N){isos.push_back(mapGH); return;}
        int u=order[k];
        for(int v=0; v<N; v++){
            if(usedH[v]) continue;
            if(G[u].size()!=H[v].size()) continue;
            bool ok=true;
            for(int i=0;i<k && ok;i++){
                int uu=order[i], vv=mapGH[uu];
                if(adjG[u][uu] != adjH[v][vv]) ok=false;
            }
            if(!ok) continue;
            usedH[v]=1; mapGH[u]=v; dfsIso(k+1); usedH[v]=0; mapGH[u]=-1;
        }
    };
    dfsIso(0);
    if(isos.empty()){ cout<<-1<<"\n"; return 0; }
    map<int,int> mp;
    int sum = 0;
    for(int i=0;i<E;i++){
        sum+=i;
        mp[i] = sum;
    }
    vector<vector<int>> cycles;
    vector<vector<int>> g = G;
    for(auto& v:g) sort(v.begin(),v.end());
    for(int s=0;s<N;s++){
        for(int t: g[s]) if(t>s){
            vector<int> st; st.push_back(s); st.push_back(t);
            vector<int> vis(N,0); vis[s]=1; vis[t]=1;
            function<void(int,int,vector<int>&,vector<int>&)> dfs=[&](int u,int p,vector<int>& path, vector<int>& used){
                for(int w: g[u]){
                    if(w==s && path.size()>=3){ cycles.push_back(path); continue; }
                    if(w<=s || w==p) continue;
                    if(!vis[w]){
                        vis[w]=1; path.push_back(w);
                        dfs(w,u,path,used);
                        path.pop_back(); vis[w]=0;
                    }
                }
            };
            vector<int> used(N,0);
            vector<int> path=st;
            dfs(t,s,path,used);
        }
    }

    vector<vector<int>> gen;
    for(auto &cy:cycles){
        vector<int> idxs;
        for(int v:cy) idxs.push_back(v);
        gen.push_back(idxs);
        reverse(idxs.begin(),idxs.end());
        gen.push_back(idxs);
    }
    if(gen.empty()){
        cout<<(isos[0]==vector<int>(N)?0:-1)<<"\n";
        return 0;
    }

    vector<int> start(N); iota(start.begin(),start.end(),0);
    queue<vector<int>> q;
    unordered_map<string,int> dist;
    string s0=pack(start); dist[s0]=0; q.push(start);

    auto apply=[&](const vector<int>& st,const vector<int>& cyc){
        vector<int> t=st; int m=cyc.size();
        for(int i=0;i<m;i++) t[cyc[(i+1)%m]]=st[cyc[i]];
        return t;
    };

    vector<string> targets;
    for(auto &f: isos){
        vector<int> lab(N);
        for(int u=0;u<N;u++) lab[u]=f[u];
        targets.push_back(pack(lab));
    }
    unordered_set<string> targetSet(targets.begin(),targets.end());
    int best=INT_MAX;

    while(!q.empty()){
        auto curState=q.front(); q.pop();
        string key=pack(curState);
        if(targetSet.count(key)) best=min(best,dist[key]);
        if(dist[key]>=best) continue;
        for(auto &cy: gen){
            auto nx=apply(curState,cy);
            string k=pack(nx);
            if(!dist.count(k)){
                dist[k]=dist[key]+1;
                q.push(nx);
            }
        }
    }
    set<int> st;
    for(int i=0;i<E;i++){
        st.insert(i);
    }
    if(best==INT_MAX) cout<<-1<<"\n"; else cout<<best<<"\n";
}