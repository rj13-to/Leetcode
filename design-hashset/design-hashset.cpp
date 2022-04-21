class MyHashSet {
public:
    const static int size = 1e6+5;
    int arr[size]={0};
    MyHashSet() 
    {
        
    }
    
    void add(int key) 
    {
        arr[key] = 1;
    }
    
    void remove(int key) 
    {
        if(arr[key]) arr[key]--;
    }
    
    bool contains(int key) {
        return arr[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */