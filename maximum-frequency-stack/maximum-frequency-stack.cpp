class FreqStack {
public:
    map<int,multiset<int>>mp;
    int arr[(int)1e5];
    map<int,vector<int>>frq;
    int k = 0;
    FreqStack() {
        mp.clear();
        frq.clear();
        memset(arr,0,sizeof(arr));
        k=0;
    }
    
    void push(int val) 
    {
        arr[k] = val;
        frq[val].push_back(k);
        int size = frq[val].size();
        if( size != 1)
        {
            int f = frq[val][size-2];
            if(mp[size-1].size() > 1)
                mp[size-1].erase(mp[size-1].lower_bound(f));
            else mp.erase(size-1);
            
        }
        mp[size].insert(k);
        k++;
    }
    
    int pop() 
    {
        int f =  *mp.rbegin()->second.rbegin();
        
        if(mp.rbegin()->second.size() > 1)
        {
            (mp.rbegin()->second).erase(prev(mp.rbegin()->second.end()));
        }
        else 
        {
            mp.erase(prev(mp.end()));
        }
        if(frq[arr[f]].size() == 1) frq.erase(arr[f]);
        else
        {
            frq[arr[f]].pop_back();
            mp[frq[arr[f]].size()].insert(frq[arr[f]].back());
        }
        return arr[f];
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */