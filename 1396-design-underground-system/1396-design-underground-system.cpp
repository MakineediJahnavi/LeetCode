class UndergroundSystem {
private:
    unordered_map<int,pair<string,int>> in;
    unordered_map<string,unordered_map<string,vector<int>>> out;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto &[startStation, t0] = in[id];
        out[startStation][stationName].push_back(t-t0);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double avg=0;
        for(auto it:out[startStation][endStation]) {
            avg+=it;
        }
        return avg/out[startStation][endStation].size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */