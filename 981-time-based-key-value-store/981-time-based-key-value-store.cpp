class TimeMap {
public:    
    unordered_map<string,map<int,string, greater<int>>>m;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
            //auto &p = m[key];
            auto ind = m[key].lower_bound(timestamp);
            if(ind == m[key].end()) return "";
            return ind->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */