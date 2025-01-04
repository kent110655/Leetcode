class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, k);
    }
    int quickSelect(vector<int>& nums, int start, int end, int k)
    {
        int pivot = nums[start + (end - start)/2];
        int i = start, j = end, t = start;
        while(t <= j)
        {
            if(nums[t] > pivot)
            {
                swap(nums[t], nums[j]);
                j--;
            }
            else if(nums[t] < pivot)
            {
                swap(nums[t], nums[i]);
                i++;
                t++;
            }
            else
            {
                t++;
            }
        }
        if(end - j >= k)
        {
            return quickSelect(nums, j+1, end, k);
        }
        else if(end-i+1 >= k)
        {
            return pivot;
        }
        else
        {
            return quickSelect(nums, start, i-1, k-(end-i+1));
        }
    }
};

/*
Algo3:
Comment:
This solution uses the Quick Select Algorithm. By defining a pivot, a upper bound i, a lower bound j, and a comparison pointer t, we determine the correct position for nums[t] by comparing it with the pivot. If nums[t] is greater than the pivot, we swap nums[t] with nums[j] and decrement j. If nums[t] is less than the pivot, we swap nums[t] with nums[i] and increment both i and t. If nums[t] is equal to the pivot, we simply increment t.
The process partitions the array into three parts, the part whose elements are less than the pivot, the part whose elements are greater than the pivot, the part whose elements are equal to pivot. By comparing k with the three parts, we determine which segment contains the k-th largest element. Then, we recursively apply the same approach to that segment until we find the k-th largest element.
Time Comlexity: 
Ｏ(N) on average
Ｏ(N^2) in the worst case (when the poor pivot selection leads to highly unbalanced partitions)
Space Complexity: Ｏ(1)
*/

/*
Algo 2:
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = -10001, right = 10001;
        while(left+1 < right)
        {
            int mid = left + (right - left)/2;
            auto kThLarge = getKth(nums, mid);
            if(kThLarge <= k)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        return right;
    }

    int getKth(vector<int>& nums, int t)
    {
        int result = 1;
        for(auto n : nums)
        {
            result += (n>t);
        }
        return result;
    }
};

Comment:
This solution uses binary search on value. By defining an upper bound and a lower bound, we perform a binary search to identify the value that corresponds to the k-th largest element in the array.
At each step, we calculate the midpoint 'mid' and use the function 'getKth' to determine what the rank of 'mid' is in the array. Based on the result, we adjust the bound.
If the rank of 'mid' is less than or equal to k, the k-th largest element must be 'mid' or larger, so we should move the upper bound to mid. Otherwise, we adjust the lower bound to mid.
The process continues until the bounds converge, when the upper bound is behind the lower bound.

Time Complexity: Ｏ(N*logC), where N is the cost of the checking the rank of 'mid' per iteration, and the logC is the number of iteration. 
Space Complexity: Ｏ(1), as no addition data structure are used.
*/


/*
Algo 1:
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto i : nums)
        {
            pq.push(i);
        }   
        for(int t = 0; t < k-1; t++)
        {
            pq.pop();
        }
        return pq.top();
    }
};


Comment:
使用Priority Queue。
Time Complexity：Ｏ(nlogn + klogn)
Space Complexity：Ｏ(n)

*/
