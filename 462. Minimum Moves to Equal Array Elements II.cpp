class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int cnt = 0;
        int target = 0;
        int mid = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        target = nums[mid];
        for(auto t : nums)
        {
            cnt += abs(target - t);
        }
        return cnt;
    }
};
/*
Comment:
利用C++的nth_element：將第k大的元素放在第k個位置
找出中位數。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 1:
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int cnt = 0;
        int target = 0;
        sort(nums.begin(), nums.end());
        target = nums[nums.size() / 2];
        for(auto t : nums)
        {
            cnt += abs(target - t);
        }
        return cnt;
    }
};
Comment:
相遇問題，求中位數。
先sort再求中位數。
時間複雜度：Ｏ(nlogn)
空間複雜度：Ｏ(1)
*/
