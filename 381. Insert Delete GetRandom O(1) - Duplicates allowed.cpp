class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> hash;
    vector<int> index;
    RandomizedCollection() {
    }
    
    bool insert(int val) {
        bool result = true;
        if(hash.find(val) != hash.end())
            result = false;
        index.push_back(val);
        int lastIndex = index.size()-1;
        hash[val].insert(lastIndex);

        return result;
    }
    
    bool remove(int val) {
        bool result = true;
        if(hash.find(val) == hash.end())
            return false;
        
        int removeIndex = *hash[val].begin();
        int lastIndex = index.size()-1;
        int lastNodeValue = index[lastIndex];

        // 把要remove的element與最後一個element換位置，並更新hash表
        swap(index[removeIndex], index[lastIndex]);
        hash[val].erase(removeIndex);
        hash[val].insert(lastIndex);
        hash[lastNodeValue].erase(lastIndex);
        hash[lastNodeValue].insert(removeIndex);
        
        // 移除vector最後一個element，並且更新hash表
        hash[val].erase(lastIndex);
        index.pop_back();
        if(hash[val].size() == 0)
            hash.erase(val);

        return result;
    }
    
    int getRandom() {
        int randomIndex = rand() % index.size();
        return index[randomIndex];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

 /*
 Comment:
 We use a vector to store the element in order to get a random element. And we use a hash table which is an unordered_map, and the key of the hash table is the value of vector element, and the value of the hash table is an unordered_set in order to record the index of element in the vector. Then, we step by step implement the three functions.
 First, in the insert function, we simply add the element into vector and update the hash table.
 Next, in the remove function, in order to the request of spending Ｏ(1) to remove element, we cannot simply erase the element which action spends Ｏ(n). So we could swap the remove element and the last element in the vector, and then we could pop_back the last element spending Ｏ(1).  At the same time, we should update the hash table when we swapped the elements include the set of remove element and the set of the last element. Now, the element to remove has been moved to the last position in the vector. Finally, we could remove the last element and update the hash table.
 Finally, in the getRandom function, we could simply get the random index in the vector and get the value at that index.
 Time Complexity: Ｏ(1)
 Space Complexity: Ｏ(n)
 */
