class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long cnt = 0;
        deque<long long> d_min, d_max;

        int i = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            // add nums[j], maintain max/min deque
            while(!d_max.empty() && nums[d_max.back()] < nums[j])
                d_max.pop_back();
            d_max.push_back(j);
            while(!d_min.empty() && nums[d_min.back()] > nums[j])
                d_min.pop_back();
            d_min.push_back(j);

            // check the continuous after add nums[j]
            while(!d_max.empty() && !d_min.empty() && nums[d_max.front()] - nums[d_min.front()] > 2)
            {
                // not continuous, remove left side element, maintain max/min deque
                if(!d_max.empty() && d_max.front() <= i)
                    d_max.pop_front();
                if(!d_min.empty() && d_min.front() <= i)
                    d_min.pop_front();
                i++;
            }
            cnt += j-i+1;
        }
        return cnt;
    }
};

/*
Comment:
We use two deques to maintain a max monotonic deque and min monotonic deque, and the front element in the max deque is the maximum element, and the front element in the min deque is the minimum element. Use two pointer i, j, and i is the left side pointer, and j is the right side pointer. i and j can represent the subarray range. Then we use sliding window to count all continuous subarrays. First, we add new element from right side and maintain the two deques at the same time. Second, we check whether the subarray is continuous or not. If the check result is not continuous, we would remove the left side element and maintain the two deques at the same time. Finally, we add to the count which means the count of subarray which is end with new element j. After calculating the last element, we can get the total count continuous subarray.
Time Complexity:Ｏ(n)
Space Complexity:Ｏ(n)
*/
