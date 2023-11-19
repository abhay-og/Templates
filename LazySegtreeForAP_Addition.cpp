struct segtree{
    ll sz;
    vector<ll> t,a,d;
    segtree(vector<ll>&v){
        sz=v.size();
        t.assign(4*sz,0);
        a=d=t;
        build(0,0,sz-1,v);
    }
    void build(ll node_pos,ll lx,ll rx,vector<ll>&v){
        if(rx==lx){
            t[node_pos]=v[lx];
            return;
        }
        ll mid=(lx+rx)/2;
        build(2*node_pos+1,lx,mid,v);
        build(2*node_pos+2,mid+1,rx,v);
        t[node_pos]=t[2*node_pos+1]+t[2*node_pos+2];
    }
    void propogate(ll node_pos,ll lx,ll rx){
        if(rx==lx || (a[node_pos]==0 && d[node_pos]==0))return;
        ll mid=(lx+rx)/2;
        a[2*node_pos+1]+=a[node_pos];
        d[2*node_pos+1]+=d[node_pos];
        a[2*node_pos+2]+=a[node_pos]+(mid-lx+1)*d[node_pos];
        d[2*node_pos+2]+=d[node_pos];
        t[2*node_pos+1]+=(mid-lx+1)*a[node_pos]+d[node_pos]*(((mid-lx+1)*(mid-lx))/2);
        t[2*node_pos+2]+=(rx-mid)*a[node_pos]+d[node_pos]*((((rx-lx+1)*(rx-lx))/2) -(((mid-lx+1)*(mid-lx))/2));
        a[node_pos]=d[node_pos]=0;
    }
    void update(ll l,ll r,ll A,ll D){
        update(0,0,sz-1,l,r,A,D);
    }
    void update(ll node_pos,ll lx,ll rx,ll l,ll r,ll A,ll D){
        propogate(node_pos,lx,rx);
        if(lx>r || rx<l)return;
        if(lx>=l && rx<=r){
            a[node_pos]=A;
            d[node_pos]=D;
            t[node_pos]+=(rx-lx+1)*A+D*(((rx-lx)*(rx-lx+1))/2);
            return;
        }
        ll mid=(lx+rx)/2;
        update(2*node_pos+1,lx,mid,l,r,A,D);
        update(2*node_pos+2,mid+1,rx,l,r,A+max(0LL,(min(mid,r)-max(l,lx)+1))*D,D);
        t[node_pos]=t[2*node_pos+1]+t[2*node_pos+2];
    }
    ll get(ll pos){
        return get(0,0,sz-1,pos);
    }
    ll get(ll node_pos,ll lx,ll rx,ll pos){
        propogate(node_pos,lx,rx);
        if(rx==lx)return t[node_pos];
        ll mid=(lx+rx)/2;
        if(pos<=mid)return get(2*node_pos+1,lx,mid,pos);
        return get(2*node_pos+2,mid+1,rx,pos);
    }
};
