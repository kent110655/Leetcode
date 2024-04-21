class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0;
        int j = 0;
        vector<vector<int>> result;
        while(i < firstList.size() && j < secondList.size())
        {
            if(firstList[i][1] < secondList[j][0])
            {
                // no intersectoion
                i += 1;
            }
            else if(firstList[i][0] > secondList[j][1])
            {
                // no intersectoion
                j += 1; 
            }
            else
            {
                vector<int> target = {max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])};
                result.push_back(target);

                if(firstList[i][1] < secondList[j][1])
                {
                    i += 1;
                }
                else
                {
                    j += 1;
                }
            }
        }
        return result;
    }
};

/*
comment:
使用兩個pointer i, j 來代表firstList,secondList之中的區塊
依區塊start, end來判斷重疊區域並記錄在result, 並依情況決定要讓其一前進到下一個區塊

Time Complexity：Ｏ(Max(m,n))
Space Complexity：Ｏ(1)
*/
