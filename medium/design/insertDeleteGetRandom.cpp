class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_set<int> mySet;
    
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool inserted = false;
        
        if (!mySet.count(val)){
            inserted = true;
            mySet.insert(val);
        }
        
        return inserted;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool removed = false;
        
        if (mySet.count(val)){
            removed = true;
            mySet.erase(val);
        }
        
        return removed;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        vector<int> temp(mySet.begin(), mySet.end());
        int index = rand() % temp.size();
        return temp[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
