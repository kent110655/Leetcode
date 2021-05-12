class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(2);
        for(auto n : nums)
        {
            if(nums[abs(n) - 1] < 0)
                ans[0] = abs(n);
            else
                nums[abs(n) - 1] *= -1;
        }
        for(int j = 0; j < N; j++)
        {
            if(nums[j] > 0)
                ans[1] = j + 1;
        }
        return ans;
    }
};
/*
Algo 4:
Comment:
掃一遍nums
把掃過的值代表的位置的值變為負數
如果發現位置上的值已經是負數，則此位置代表的數字即為重複者
再掃一遍nums，唯一的正數的位置即為缺失者
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 3:
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(2);
        for(int i = 0; i < N; i++)
        {
            while(nums[i] != i+1)
            {
                if(nums[nums[i]-1] == nums[i])
                {
                    ans[0] = nums[i];
                    break;
                }
                swap(nums, i, nums[i]-1);
            }
        }
        for(int j = 0; j < N; j++)
        {
            if(nums[j] != j + 1)
            {
                ans[1] = j + 1;
                break;
            }
        }
        return ans;
    }
    void swap(vector<int>& nums, int a, int b)
    {
        int tempt = nums[a];
        nums[a] = nums[b];
        nums[b] = tempt;
    }
};
Comment:
掃一遍nums
不停地把nums[i]的值換到正確的位置，直到所有位置正確
即將換到的位置上已有正確值，即為重複者
最後再掃一遍nums，有位置的值不正確的就是缺失者
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 2:
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int N = nums.size();
        vector<bool> element(N+1,false);
        vector<int> ans(2);
        for(auto n : nums)
        {
            if(element[n] == true)
                ans[0] = n;
            element[n] = true;
        }
        for(int i = 1; i <= N; i++)
        {
            if(element[i] == false)
            {
                ans[1] = i;
                break;
            }
        }
        return ans;
    }
};
Comment:
設置一個大小為N+1的vector<bool>
v[i]：i是否有出現過
跑一遍loop更新vector找出重複者
再跑一遍loop找出缺失者
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/

/*
Algo 1:
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int N = nums.size();
        int cnt = 1;
        vector<int> ans(2);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < N; i++)
        {
            if(nums[i] != cnt)
            {
                if(nums[i] == cnt - 1)
                {
                    ans[0] = nums[i];
                    cnt--;
                }
                else
                {
                    ans[1] = cnt;
                    cnt = nums[i];
                }
            }
            cnt++;
        }
        ans[1] = (ans[1] == 0) ? nums[N-1] + 1 : ans[1];
        return ans;
    }
};
Comment:
sort排序nums
再以cnt代表應該要出現的數字
以此找出重複與缺失的數字。
時間複雜度：Ｏ(nlogn)
空間複雜度：Ｏ(1)
*/
