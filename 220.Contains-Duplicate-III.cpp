class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<long long> set;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > indexDiff)
            {
                set.erase(set.lower_bound((long long)nums[i-indexDiff-1]));
            }
            auto iter = set.lower_bound((long long)nums[i] - valueDiff);
            if(iter != set.end() && abs(*iter - (long long)nums[i]) <= valueDiff)
            {
                return true;
            }
            set.insert((long long)nums[i]);
        }
        return false;
    }
};

/*
Comment:
需要維護一個sliding windows，保持windows內的元素index維持與當前element index有indexDiff的距離
同時比較windows內element有符合 now - valueDiff < windows element < now + valueDiff
為了方便取得且有排序的window，使用multiset。
Time Complexity:Ｏ(nlog(indexDiff)), multiset: Ｏ(logn)
Space Complexity:Ｏ(indexDiff)
*/
