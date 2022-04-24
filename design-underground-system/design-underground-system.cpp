class UndergroundSystem {
public:
    map<string,map<string,pair<int,double>>>station;
    map<int,pair<string,int>>mp;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        station[mp[id].first][stationName].first += t-mp[id].second;
        station[mp[id].first][stationName].second++;
        
        mp.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return station[startStation][endStation].first/station[startStation][endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */