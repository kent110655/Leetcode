class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int capacity = 0; //min capacity
        int sum = 0; // max capacity
        for(int i = 0 ; i < weights.size(); i++)
        {
            capacity = max(capacity, weights[i]);
            sum += weights[i];
        }
        int left = capacity-1;
        int right = sum+1;
        while(left+1 < right)
        {
            int mid = left + (right - left)/2;
            int cur_day = 1;
            int cur_weight = 0;
            for(int i = 0 ; i < weights.size(); i++)
            {
                cur_weight += weights[i];
                // ship is over weight
                if(cur_weight > mid)
                {
                    cur_day++;
                    cur_weight = weights[i];
                    if(cur_day > days)
                    {
                        break;
                    }
                }
            }
            // over limited days, capacity should be bigger
            if(cur_day > days)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        return right;
    }
};

/*
Comment:
1. 先找出capacity的範圍(最大值最小值)：最大值=weights總和, 最小值=weights最大element
2. 利用Binary Search找出符合條件的最小capacity
3. 每決定一個mid，就要以此capacity=mid的假設來算需要多少days才能裝完。策略為Greedy，按順序能裝就裝，裝到超過capacity後換下一天。如此可得知在此capacity的假設下需要用幾天裝完。
4. 比較花費天數即可得知目前的capacity(mid)需要增加還是減少。
Time Complexity：Ｏ(n) + Ｏ(nlogn)
Space Complexity：Ｏ(1)
*/
