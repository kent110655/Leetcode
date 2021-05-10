class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int r = 0;
        int c = n-1;
        while(r < m && c >= 0)
        {
            if(matrix[r][c] > target)
                c--;
            else if(matrix[r][c] < target)
                r++;
            else
                return true;
        }
        return false;
    }  
};
/*
Commnet:
從右上角開始搜尋target
當比target大的時候，左移(colomn--)
當比target小的時候，下移(row++)
時間複雜度：Ｏ(n+m)
空間複雜度：Ｏ(1)
*/
