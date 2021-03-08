class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        return a[0]<b[0];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)
            return 0;
        sort(points.begin(),points.end(),cmp);
        int i=1;
        int start=points[0][0];
        int end=points[0][1];
        int count=1;
        while(i<points.size())
        {
            if(points[i][0]>end)    //non-overlapping
            {
                start=points[i][0];
                end=points[i][1];
                count++;
            }
            else    //overlapping --> renew start,end
            {
                start=points[i][0];
                end=min(end,points[i][1]);
            }
            i++;
        }
        return count;
    }
};

/*
Comment:
Greedy algo.
interval的start愈小則共同interval即可容納更多interval
所以先依照各個interval的start由小到大sort
再依序加入interval，更新共同interval的上下限，同時紀錄共同interval的數量count
count即為所求。
*/
