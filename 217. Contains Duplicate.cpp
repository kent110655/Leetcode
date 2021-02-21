class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> set;
        for(int i=0;i<nums.size();i++)
        {
            if(set.count(nums[i]))
            {
                return true;
            }
            else
            {
                set.insert(nums[i]);
            }
        }
        return false;
    }
};


/*
Comment:
利用Hash table + set

Time: O(n)
Space: O(n)

P.S.
unordered_map: hash table （內部無排序）
set: red-black tree （內部有排序）

set: 每個元素只能有一個
multiset: 每個元素可以多個

set.insert(s)–在集合中插入元素s
set.erase(s)–刪除集合中的元素s
set.size(s)–集合中元素s的數目
set.count(s)-回傳element s 的個數

*/