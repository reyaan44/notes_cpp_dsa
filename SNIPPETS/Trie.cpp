class node // characters are present on edges in tries
{   
public:
    ll curr;    // current occurrences
    node* next[26];
    node()
    {
        curr = 0;
        for(ll i=0; i<26; i++)
            next[i] = NULL;
    }
    void insert(ll idx, string &s)  // insert string
    {
        curr++;
        if(idx==s.length())
            return;
        if(next[s[idx]-'a']==NULL)
            next[s[idx]-'a'] = new node();
        next[s[idx]-'a']->insert(idx+1,s);
    }
    ll search(ll idx, string &s) // total prefixes
    {
        if(idx==s.length())
            return curr;
        if(next[s[idx]-'a']==NULL)
            return 0;
        else
            return next[s[idx]-'a']->search(idx+1,s);
    }
    bool remove(ll idx, string &s)   // remove string
    {
        curr--;
        if(curr==0)
            return 0;
        if(idx==s.length())
            return 1;
        if(next[s[idx]-'a']!=NULL)
        {
            bool check = next[s[idx]-'a']->remove(idx+1,s);
            if(!check)
                next[s[idx]-'a'] = NULL;
        }
        return 1;
    }
};