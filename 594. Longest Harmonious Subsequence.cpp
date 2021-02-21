class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> umap;
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
            umap[nums[i]]++;
        }
        
        for(auto m:umap)
        {
            if(umap.count(m.first+1))
            {
                result = max(result , m.second + umap[m.first+1]);
            }
        }
        return result;
    }
};

/*
Comment:
利用Hash table
1.先把所有element存入hash table --> pair(element,element數目) : O(n)
2.loop跑map中所有的element，確認map中是否有element符合條件，並且更新result值 ：O(n)
Time: O(n)
Space: O(n)

P.S.
1.map中只需確認比element大的其他element，避免重複確認。
2.unordered_map默認element的值為0，所以可以直接用map[s]++來添加element。
3.使用for(auto a:map)來精簡寫法，且a的type為pair。a.first、a.second用法。

*/