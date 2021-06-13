int shortestSubarray(vector<int> vect, int k) 
    {
        int ans = vect.size()+1;
        deque<int> dq;
        for (int i = 0; i < vect.size(); i++) 
        {
            if (i > 0)
                vect[i] += vect[i - 1];
            if (vect[i] >= k)
                ans = min(ans,i+1);
            while (dq.size() > 0 && vect[i] - vect[dq.front()] >= k)
            {
                ans = min(ans,i-dq.front());
                dq.pop_front();
            }
            while (dq.size() > 0 && vect[i] <= vect[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        return ans <= vect.size() ? ans : -1;
    }