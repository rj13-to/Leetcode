class MyCalendarThree {
public:
    multiset<pair<int,int>>ms;
    MyCalendarThree() {
        ms.clear();
    }
    
    int book(int start, int end) {
        ms.insert({start,1});
        ms.insert({end,-1});
        int tot = 0;
        int k = 0;
        for(auto it = ms.begin();it!= ms.end();it++)
        {
            k += (*it).second;
            tot = max(tot,k);
        }
        return tot;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */