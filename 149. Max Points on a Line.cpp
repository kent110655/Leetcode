class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxCnt = 0;
        int cnt = points.size();
        if(cnt == 1)
            return 1;
        for(int i = 0; i < cnt; i++)
        {
            unordered_map<string, int> slope;
            int duplicateCnt = 0;
            for(int j = 0; j < cnt; j++)
            {
                if(points[i] == points[j])
                {
                    duplicateCnt++;
                    continue;
                }
                string s = getSlope(points[i],points[j]);
                slope[s]++;
                maxCnt = max(maxCnt, slope[s] + duplicateCnt);
            }
        }
        return maxCnt;
    }

    string getSlope(vector<int> p1, vector<int> p2)
    {
        int dx = p2[0]-p1[0];
        int dy = p2[1]-p1[1];

        if(dx == 0)
            return "v";
        if(dy == 0)
            return "h";

        int d = gcd(dx, dy);
        int x = dx/d;
        int y = dy/d;
        if(x < 0)
        {
            x *= -1;
            y *= -1;
        }

        return to_string(x) + "/" + to_string(y);
    }
};
/*
Comment:
1. 以一個point來當基準點，連線其他點取得斜率，並且存在hash table之中紀錄數量
2. 斜率取得：以gcd取得最大公因數，約分得到斜率，並且考慮正負號
3. 重複點：考慮其他點與基準點重複的情況，額外紀錄並在比較次數時加上計算
Time Complexity: Ｏ(n^2) (gcd：Ｏ(logn))
Space Complexity: Ｏ(n)
*/
