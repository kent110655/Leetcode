class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++)
        {
            int x = i;
            int y = 0;
            int last = matrix[x][y];
            while(x < m && y < n)
            {
                if(last != matrix[x][y])
                    return false;
                x++;
                y++;
            }
        }
        for(int j = 0; j < n; j++)
        {
            int x = 0;
            int y = j;
            int last = matrix[x][y];
            while(x < m && y < n)
            {
                if(last != matrix[x][y])
                    return false;
                x++;
                y++;
            }
        }
        return true;
    }
};
/*
Comment:
分別檢驗matrix[i][0]、matrix[0][j]為起點的斜邊組是否相同
時間複雜度：Ｏ(mn)
空間複雜度：Ｏ(1)
*/
