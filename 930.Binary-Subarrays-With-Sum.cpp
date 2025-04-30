class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt = 0;
        unordered_map<int,int> hash;
        int sum = 0;
        hash[0] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(sum - goal >= 0)
            {
                cnt += hash[sum-goal];
            }
            hash[sum]++;
        }
        return cnt;
    }
};

/*
Comment:
使用前墜和，並用hash table紀錄前綴和的element個數。如此即可直接從hash table得出可與目前element配對的對象個數，最終即可得到累積的配對數。
Time Complexity:Ｏ(n)
Space Complexity:Ｏ(n)
*/
