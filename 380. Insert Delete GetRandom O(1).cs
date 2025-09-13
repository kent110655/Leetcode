class RandomizedSet {
public:
    unordered_map<int,int> hash;
    vector<int> index;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(hash.find(val) != hash.end())
            return false;
        index.push_back(val);
        hash[val] = index.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(hash.find(val) == hash.end())
            return false;
        hash[index.back()] = hash[val];
        swap(index[hash[val]], index.back());
        index.pop_back();
        hash.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % hash.size();
        return index[randomIndex]; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


 /*
 Comment:
 Owing to the demand of the question which insert, remove, getRandom should be Ｏ(1). I exclude the hash set because the getRamdom action would not be Ｏ(1). So we use a vector to store the val, and then use a hash map which stores val and index of vector. Next, we implement the three function one by one. In insert action, we would verify whether the val existed or not, and update the vector and hashmap. In remove action, we can't use simply use erase function to remove the element in the vector because the erase action would be Ｏ(n). So we swap the val and the last element, and then we pop the last element. Simultaneously, we would update the hashmap.In getRamdom action, we get ramdom index of vector and return it.

 Time Complexity:Ｏ(1)
 Space Complexity:Ｏ(n)
 */
