class Solution {
public:
    static bool compare(vector<int>& a,vector<int>& b)
    {
        return  a[1]<b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==1 || intervals.size()==0)
            return 0;
        sort(intervals.begin(),intervals.end(),compare);
        int count=0;
        int top = intervals[0][1];
        int i=1;
        while(i<intervals.size())
        {
            if(intervals[i][0]<top)
            {
                count++;
            }
            else
            {
                top = intervals[i][1];
            }
            i++;
        }
        return count;
    }
};




/*
Comment:
Greedy algo.
當取的interval結尾小的時候，後面的空間就更大可以塞更多的interval。
所以先把intervals由結尾小到結尾大sort。
再依序由結尾小加入，更新結尾(top)
紀錄開始點<目前結尾的interval數量count，count即為所求。
*/
