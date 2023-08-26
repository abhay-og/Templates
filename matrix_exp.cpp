vector<vector<ll>> mult(vector<vector<ll>> A, vector<vector<ll>> B){
    vector<vector<ll>> res(A.size(),vector<ll>(A[0].size(),0));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            for(int k=0;k<A[0].size();k++){
                res[i][j]=(res[i][j]+(A[i][k]*B[k][j])%MOD)%MOD;
            }
        }
    }
    return res;
}
 
vector<vector<ll>> matrix_exp(vector<vector<ll>> &a, ll n){
    vector<vector<ll>> res(a.size(),vector<ll>(a[0].size(),0));
    for(int i=0;i<a.size();i++)res[i][i]=1;
    while(n>0){
        if(n&1)res=mult(res,a);
        a=mult(a,a);
        n>>=1;
    }
    return res;
}
 
