class RandomizedSet {
public:
        vector<int> vec;
        unordered_map<int,int>mp;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(!mp.count(val)){
            vec.push_back(val);
            mp[val]=vec.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.count(val)){
            int inx = mp[val];
            vec[inx] = vec[vec.size()-1];
            mp[vec[inx]]=inx;
            mp.erase(val);
            vec.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};
