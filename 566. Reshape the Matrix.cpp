class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int R = mat.size();
        int C = mat[0].size();
        if(R * C != r * c)
            return mat;
        vector<vector<int>> ans(r, vector<int>(c));
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                ans[i][j] = mat[(i * c + j) / C][(i * c + j) % C];
            }
        }
        return ans;
    }
};
/*
Comment:
矩陣轉換問題
A[row][colomn]
EX: A[2][3]
0 0 0
0 0 0
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
