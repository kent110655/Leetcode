class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int> umap;
        for(int i =0; i<nums.size(); i++)
        {
            if(umap.find(target-nums[i]) != umap.end())
            {
                return {i,umap[target-nums[i]]};
            }
            else
            {
                umap[nums[i]]=i;
            }
        }
        return {};
    }
};

/*
comment:
利用 hash table (unordered_map)

1.尋找hash table中是否有符合的element
2.若有符合，return。
3.若沒有符合，把新element加入hash table。
4.重複1~3

Time: O(n)
Space: O(n)

P.S.
Hash table:
    Time:
        建立：O(n)
        尋找：O(1)
    Space:
        O(n)

unordered_map : hash table
map : red-black tree

*/