class MapSum {
public:
    unordered_map<string, int> map;
    vector<MapSum*> Next;
    int val_ = 0;
    /** Initialize your data structure here. */
    MapSum():Next(26,nullptr) {}
    void insert(string key, int val) {
        MapSum* p = this;
        int diff = val - map[key];
        for(auto c: key)
        {
            if(!p->Next[c - 'a'])
                p->Next[c - 'a'] = new MapSum();
            p = p->Next[c - 'a'];
            p->val_ += diff;
        }
        map[key] = val;
    }
    
    int sum(string prefix) {
        MapSum* p = this;
        for(auto c: prefix)
        {
            if(!p->Next[c - 'a'])
                return NULL;
            p = p->Next[c- 'a'];
        }
        return p->val_;
    }
};
/*
Comment:
利用Trie來實作。
把每個sum紀錄在Trie的每個Node中，經過時累加紀錄。
為了更新Insert時的新key，所以用hash table紀錄目前有的key與值
當已經有的key要更新，先求出diff再來更新即可。
*/
/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
