class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int frequentMax=0;
        unordered_map<int,int> counts;
        for(auto u:nums)
        {
            counts[u]++;
            frequentMax = max(frequentMax,counts[u]);
        }
        
        vector<vector<int> > buckets(frequentMax+1);
        for(auto e:counts)
        {
            buckets[e.second].push_back(e.first);
        }
        
        vector<int> ans;
        int freq = frequentMax;
        while(ans.size()!=k)
        {
            for(auto g:buckets[freq])
                ans.push_back(g);
            freq--;
        }
        return ans;
    }
};

/*
comment:
利用Bucket Sort。
1. 把每個數字的frequence存入unordered_map counts中，且記錄下其中的最大frequence。
2. 創一個大小為(Maxfrequence+1)的vector buckets，用來存各frequence的數字。(buckets的第w個元素即代表frequence=w的vector)
3. 把buckets由尾端(freq大的一端)依序加入ans，直到ans中的element數＝k。
4. ans即為所求。
時間複雜度：
1.unordered_map 的 insetion:Ｏ(n)
2.Ｏ(n)
3.Ｏ(n)
-->Ｏ(n)
空間複雜度：Ｏ(n)
*/
