class Union
{
public:
    vector<ll> _rank,par;
    void initialize(ll n)
    {
        _rank.assign(n+1,1);
        par.assign(n+1,0);
        for(ll i=1; i<=n; i++)
        {
            par[i]=i;
        }
    }
    ll find(ll a)
    {
        if(par[a]==a) return a;
        else return par[a] = find(par[a]);
    }
    void merge(ll a, ll b)
    {
        a = find(a);
        b = find(b);
        if(a==b) return;
        if(_rank[a]<_rank[b]) swap(a,b);
        par[b] = a;
        _rank[a]+=_rank[b];
    }
};