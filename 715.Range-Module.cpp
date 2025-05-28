class RangeModule {
public:
    map<int,int> map;
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto iter = map.lower_bound(left);
        if(iter != map.begin())
        {
            --iter;
            if(iter-> second < left)
            {
                ++iter;
            }
        }
        int add_l = left;
        int add_r = right;
        while(iter != map.end() && iter->first <= right)
        {
            add_l = min(add_l, iter->first);
            add_r = max(add_r, iter->second);
            iter = map.erase(iter);
        }
        map[add_l] = add_r;
    }
    
    bool queryRange(int left, int right) {
        auto iter = map.upper_bound(left);
        if(iter == map.begin())
            return false;
        --iter;
        return iter->second >= right; 
    }
    
    void removeRange(int left, int right) {
        auto iter = map.lower_bound(left);
        if(iter != map.begin())
        {
            --iter;
            if(iter->second < left)
            {
                ++iter;
            }
        }

        vector<pair<int,int>> toAdd;
        while(iter != map.end() && iter->first <= right)
        {
            if(iter->first < left)
            {
                toAdd.emplace_back(iter->first, left);
            }
            if(iter->second > right)
            {
                toAdd.emplace_back(right, iter->second);
            }
            iter = map.erase(iter);
        }
        for(auto [x,y] : toAdd)
        {
            map[x] = y;
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */

 /*
 Comment:
 Use a map to store intervals. All intervals stored in the map are non-overlapping and sorted by their start point.
 In addRange part, I want to find first possibly overlapping interval. I use map.lower_bound(left) function to get the interval which is equal or bigger than left. Then, If the iterator is not at the beginning, we check whether the previous interval overlaps with left, and adjust accordingly. Then, we iterate over and erase all intervals that overlap with [left, right), while tracking the minimum start and maximum end to merge. Finally, we insert the merged interval back into the map.
 In removeRange part, we locate the first overlapping interval using the same logic. We iterate over and remove all overlapping intervals. If any part of an existing interval lies outside [left, right), we save those parts (before left or after right) into a temporary list. Finally, we reinsert those non-overlapping sub-intervals back into the map.
 In queryRange part, I use map.upper_bound(left) to locate the interval whose start is just after left. We then check the previous interval to see if it covers the entire range [left, right). This is done by verifying if its end value is greater than or equal to right.
 Time Complexity: 
 addRange/removeRange: Ｏ(logn) + Ｏ(n) = Ｏ(n)
 query: Ｏ(logn)
 Space Complexity: Ｏ(n)
 */
