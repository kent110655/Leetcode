class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])
            {
                count++;
                if(i-2>=0 && nums[i-2]>nums[i])
                {
                    nums[i]=nums[i-1];
                }
                else
                {
                    nums[i-1]=nums[i];
                }
            }
            if(count>1)
                return false;
        }
        return true;
    }
};

/*
Comment:
找遞減的部分，再辨識要修改哪一個element
分兩種情況：
當nums[i-2]>nums[i]改後者，其餘情況改前者
*/
