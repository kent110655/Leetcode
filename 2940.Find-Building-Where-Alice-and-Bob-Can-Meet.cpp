class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        for(int i = 0; i < queries.size(); i++)
        {
            sort(queries[i].begin(), queries[i].end());
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(),
            [](vector<int>& a, vector<int>& b){
                return a[1] > b[1];
                });
        
        vector<int> result(queries.size());
        map<int,int> m;
        int h = heights.size()-1;
        for(auto& q : queries)
        {
            while(h >= q[1])
            {
                while(!m.empty() && m.begin()->first <= heights[h])
                {
                    m.erase(m.begin());
                }
                m[heights[h]] = h;
                h--;
            }
            if(q[0] == q[1] || heights[q[0]] < heights[q[1]])
            {
                result[q[2]] = q[1];
                continue;
            }
            
            auto iter = m.upper_bound(max(heights[q[0]], heights[q[1]]));
            result[q[2]] = iter == m.end() ? -1 : iter->second;
        }
        return result;
    }
};

/*
Comment:
This problem is about finding, for each query (a, b), the first building to the right of b that is taller than both heights[a] and heights[b]. The key is not just finding a building that's tall enough, but also the leftmost one that fits the criteria.
To do this efficiently, we process the heights array from right to left and maintain an ordered structure that keeps only the "useful" buildings — those that are taller and appear earlier (i.e., to the left) than the ones already stored. If a new building is taller than those already in the structure, we remove the shorter ones because they’ll never be part of any optimal solution; they’re not tall enough and they’re further to the right.
So we sort the queries. Let the queries be in descending order of the right index (b). Then we process each query one by one, adding buildings from right to left up to the right index of the current query, while maintaining the ordered structure.
This guarantees that our structure is both height-increasing and index-increasing, meaning that when we use upper_bound to search for a height greater than the target (max(heights[a], heights[b])), the index we get is guaranteed to be the leftmost valid one.
We also take care of special cases: when a == b, or when heights[a] <= heights[b], we can return b directly, since b itself already satisfies the condition.
So the whole strategy is to preprocess efficiently, maintain a structure that filters out unhelpful candidates, and use binary search (upper_bound) to answer each query quickly.

queries size: q, heights size: n
Time Complexity:
queries sort: Ｏ(qlogq) + map insert/delete part: Ｏ(nlogn) + map upper_bound part: Ｏ(qlogn)
-> Ｏ(qlogq + nlogn + qlogn) 
Space Complexity:Ｏ(q+n)
*/
