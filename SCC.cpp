struct SCC{
    ll n,m;
    vector<vector<ll>> g,rg,cg,components;
    vector<bool> vis;
    vector<ll> order,component,roots,indeg,outdeg;
 
    void rsz(){
        g.resize(n+1);
        cg.resize(n+1);
        rg.resize(n+1);
    }
 
    void dfs1(ll v){
        vis[v]=1;
        for(auto &z:g[v]){
            if(!vis[z])dfs1(z);
        }
        order.push_back(v);
    }
 
    void dfs2(ll v,ll root){
        vis[v]=1;
        roots[v]=root;
        component.push_back(v);
        for(auto &z:rg[v]){
            if(!vis[z])dfs2(z,root);
        }
    }
 
    void init_SCC(){
        vis.assign(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i])dfs1(i);
        }
        vis.assign(n+1,0);
        reverse(order.begin(),order.end());
        roots.assign(n+1,-1);
        for(auto &z:order){
            if(!vis[z]){
                dfs2(z,z);
                components.push_back(component);
                component.clear();
            }
        }
        cg.resize(n+1);
        indeg.assign(n+1,0);
        outdeg=indeg;
        for(auto &z:order){
            for(auto &x:g[z]){
                if(roots[z]==roots[x])continue;
                cg[roots[z]].push_back(roots[x]);
                indeg[roots[x]]++;
                outdeg[roots[z]]++;
            }
        }
    }
};
