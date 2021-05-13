class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxCnt = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            int p = i;
            int cnt = 0;
            while(nums[p] != -1)
            {
                int tempt = nums[p];
                nums[p] = -1;
                p = tempt;
                cnt++;
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};
/*
Comment:
找最大環的長度
依序跑一遍element的環
把跑過的點改成-1，避免再度跑過
把環的最大長度記錄下來
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 1:
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        unordered_map<int,int> map;
        int longestLen = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            if(map[i])
                continue;
            int slow = i;
            int fast = i;
            int slowCnt = 0;
            int fastCnt = 0;
            while(1)
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
                slowCnt += 1;
                fastCnt += 2;
                map[slow]++;
                map[fast]++;
                if(slow == fast)
                    break;
            }
            longestLen = max(longestLen, fastCnt - slowCnt);
        }
        return longestLen;
    }
};
Comment:
找最大環的長度
利用兩個快慢指針slow fast來找環
並且用hash table紀錄走過的點 避免重複跑
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/
