ll kruskals(vector<vector<ll>>edges,LCA &L,set<vector<ll>>&s,ll n){
    stable_sort(edges.begin(),edges.end());
    DSU D(n);
    int cnt=0;
    ll mst_cost=0;
    for(auto &z:edges){
        if(cnt==n-1)break;
        ll u=z[1],v=z[2],w=z[0];
        if(D.find(u)==D.find(v))continue;
        cnt++;
        L.g[u].push_back({v,w});
        L.g[v].push_back({u,w});
        s.insert({min(u,v),max(u,v),w});
        D.unio(u,v);
        mst_cost+=w;
    }
    return mst_cost;
}
