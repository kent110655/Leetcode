class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int end = INT_MIN;
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            end = max(end, arr[i]);
            if(i == end)
                cnt++;
        }
        return cnt;
    }
};
/*
Comment:
掃一遍arr，一邊更新end值
end:此chunk邊界至少要到index = end
若成功掃到end邊界則代表此chunk完成(cnt++)
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
