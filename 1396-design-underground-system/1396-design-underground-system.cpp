class UndergroundSystem 
{
     unordered_map<string, unordered_map<string,pair<double,double>>>  travel_time;
     unordered_map<int, pair<string,int>> customer;
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        
        customer[id] = pair<string,int>{stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        
        double curr_time = t - customer[id].second;
        string prev_station = customer[id].first;
        
        customer.erase(customer.find(id));
        
        auto &itr = travel_time[prev_station][stationName];
        itr.first += curr_time;
        itr.second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        auto &itr = travel_time[startStation][endStation];
        
        return itr.first / itr.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */