class segmentTree
{
public:
    segmentTree *left, *right;
    ll start, end;
    ll sum, lazySum;
    ll mn, mx;
    segmentTree(vector<ll> & vect, ll l, ll r)
    {
        start = l;
        end = r;
        if(l==r)
        {
            sum = mx = mn = vect[l];
            lazySum = 0;
        }
        else
        {
            ll mid = l + (r - l)/2;
            left = new segmentTree(vect, l ,mid);
            right = new segmentTree(vect, mid+1, r);
            sum = left->sum + right->sum;
            mn = min(left->mn, right->mn);
            mx = max(left->mx, right->mx);
            lazySum = 0;
        }
    }
    void reCalculate()
    {
        if(lazySum!=0)
        {
            ll curr = lazySum;
            lazySum = 0;  
            sum += curr*(end-start+1); 
            mn+=curr;
            mx+=curr;
            if(start!=end)
            {
                left->lazySum += curr;  
                right->lazySum += curr;
            }
        }
    }
    ll getSum(ll l, ll r)
    {
        reCalculate();
        if(l<=start && r>=end) return sum;
        if(l>end || r<start) return 0;
        return (left->getSum(l,r) + right->getSum(l,r));
    }
    ll getMn(ll l, ll r)
    {
        reCalculate();
        if(l<=start && r>=end) return mn;
        if(l>end || r<start) return LLONG_MAX;
        return min(left->getMn(l,r), right->getMn(l,r));
    }
    ll getMx(ll l, ll r)
    {
        reCalculate();
        if(l<=start && r>=end) return mx;
        if(l>end || r<start) return LLONG_MIN;
        return max(left->getMx(l,r), right->getMx(l,r));
    }
    void update(ll l, ll r, ll add)
    {
        reCalculate();
        if(l>end || r<start) return;
        if(l<=start && r>=end)
        {
            sum += (end-start+1)*add;
            mn+=add;
            mx+=add;
            if(start!=end)
            {
                (left->lazySum)+=add;
                (right->lazySum)+=add;
            }
            return;
        }
        if(start!=end)
        {
            left->update(l,r,add);
            right->update(l,r,add);
        }
        sum = left->sum + right->sum;
        mn = min(left->mn, right->mn);
        mx = max(left->mx, right->mx);
    }
};