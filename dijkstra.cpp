void dijkstra(ll s,vector<ll>&p,vector<ll>&d){//returns dist,par vectors
    d.assign(n+1,INF);
    p.assign(n+1,-1);
    d[s]=0;
    set<pair<ll,ll>> q;
    q.insert({1ll,s});
    while(q.size()){
        ll v=q.begin()->second;
        q.erase(q.begin());
        for(auto &[dest,dist]:graph[v]){
            if(d[v]+dist<d[dest]){
                q.erase({d[dest],dest});
                d[dest]=d[v]+dist;
                p[dest]=v;
                q.insert({d[dest],dest});
            }
        }
    }
}
