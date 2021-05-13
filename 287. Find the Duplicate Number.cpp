class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int N = nums.size();
        int slow = 0;
        int fast = 0;
        while(1)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)
                break;
        }
        int p = 0;
        while(1)
        {
            slow = nums[slow];
            p = nums[p];
            if(slow == p)
                break;
        }
        return slow;
    }
};
/*
Algo 3:
Comment:
利用快慢指針找環，且環的起始點即為重複點
(不會有非重複數字在正確位置出不去的環，因為此種數字根本不會走到。)
(此外因為從0開始，且數字裡面沒有0，所以不會一開始就選到正確位置數字。)
當slow,fast等於時，此時位置處於環中的某一點
A---->B---->C
      |     |
      D<----E
假設slow,fast停在環中的E
假設AB長度為x, BCE長度為y, EDB長度為z
當slow fast同在一點時
各自路徑長：
slow = x + y
fast = x + 2y + z
因為fast速度為slow的兩倍
-> 2(x+y) = x+2y+z
-> x = z
-> AB長度 = EDB長度
所以另外找一個速度同slow的p從0出發
p,slow同速前進會在環的起始點相遇，即為重複者。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 2 :
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int N = nums.size();
        int left = 1;
        int right = N - 1;
        int mid;
        int cnt = 0;
        while(left < right)
        {
            mid = left + (right - left) / 2;
            cnt = 0;
            for(auto n : nums)
            {
                if(n <= mid)
                    cnt++;
            }
            if(cnt > mid)
                right = mid;
            else 
                left = mid+1;
        }
        return left;
    }
};
Comment:
利用Binary Search
找出mid以後，計算cnt:有幾個小於等於mid
因為如果沒有重複，則<=mid的數量必<=mid
所以cnt比mid大，代表重複數字小於等於mid
反之cnt比mid小或等於，代表重複數字大於mid
以此條件Binary Search尋找
時間複雜度：Ｏ(nlogn)
空間複雜度：Ｏ(1)
*/

/*
Algo 1:
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i-1] == nums[i])
                return nums[i];
        }
        return -1;
    }
};
Comment:
先sort再找重複
時間複雜度：Ｏ(nlogn)
空間複雜度：Ｏ(1)
*/
