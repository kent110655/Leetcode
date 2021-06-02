class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int major = nums[0];
        for(auto n : nums)
        {
            major = (cnt == 0) ? n : major;
            cnt = (major == n) ? cnt + 1 : cnt - 1;
        }
        return major;
    }
};
/*
Algo 3:
Comment:
使用Boyer-Moore Majority Vote Algorithm
每次從陣列中找出一對不同的元素，將它們從陣列中刪除，直到遍歷完整個陣列。由於這道題已經說明一定存在一個出現次數超過一半的元素，所以遍歷完陣列後陣列中一定會存在至少一個元素，即是所求。
利用兩個變數major,cnt
major: 當前的majority element
cnt: 當前majority的個數
若cnt==0，則代表之前的major全與相異的element抵銷，所以替換major成當下的element
若當下的element為major，則把major個數cnt+1
若當下的element非major，則把major個數cnt-1 (相異數抵銷)
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 1:
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int half = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + half, nums.end());
        return nums[half];
    }
};
Comment:
利用nth_element：將第k大的element放到第k的位置
因過半的element必會佔據中間的位置，所以找中間的位置即可。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
