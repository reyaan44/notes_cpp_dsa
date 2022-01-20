class segmentTree
{
public:
    segmentTree *left, *right;
    ll start, end;
    ll mn,mx,sum;
    segmentTree(vector<ll> & vect, ll l, ll r)
    {
        start = l;
        end = r;
        if(l==r)
        {
            sum = vect[l];
            mx = vect[l];
            mn = vect[l];
        }
        else
        {
            ll mid = l + (r - l)/2;
            left = new segmentTree(vect, l ,mid);
            right = new segmentTree(vect, mid+1, r);
            mn = min(left->mn, right->mn);
            mx = max(left->mx, right->mx);
            sum = left->sum + right->sum;
        }
    }
    ll minimum(ll l, ll r)
    {
        if(l<=start && r>=end)
        {
            return mn;
        }
        if(l>end || r<start)
        {
            return LLONG_MAX;
        }
        return min(left->minimum(l,r), right->minimum(l,r));
    }
    ll maximum(ll l, ll r)
    {
        if(l<=start && r>=end) return mx;
        if(l>end || r<start) return LLONG_MIN;
        return max(left->maximum(l,r), right->maximum(l,r));
    }
    ll addition(ll l, ll r)
    {
        if(l<=start && r>=end) return sum;
        if(l>end || r<start) return 0;
        return (left->addition(l,r) + right->addition(l,r));
    }
    void update(ll pos, ll key)
    {
        if(start == end && start == pos)
        {
            mn = key;
            return;
        }
        ll mid = start + (end-start)/2;
        if(pos<=mid) left->update(pos, key);
        else right->update(pos, key);
        mn = min(left->mn, right->mn);
    }
};