class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>v;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        else
        {
            mp[val]=v.size();
            v.push_back(val);
            return 1;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        if(mp.size()>1)
        {
            v[mp[val]]=v.back();
            mp[v.back()] = mp[val];
            mp.erase(val);
            v.pop_back();
            return 1;
        }
        else
        {
            mp.clear();
            v.clear();
            return 1;
        }
    }
    
    int getRandom() {
        return v[(int)rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */