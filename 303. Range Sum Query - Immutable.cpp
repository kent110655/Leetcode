class NumArray {
private:
    vector<int>* sum;
public: 
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sum = new vector<int>(n);
        sum->at(0)=nums[0];
        for(int i=1;i<n;i++)
        {
            sum->at(i)=sum->at(i-1)+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0)
            return sum->at(right);
        else
            return sum->at(right)-sum->at(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

/*
Comment:
sum[i]=sum[i-1]+nums[i]
sum of left to right＝sum[right]-sum[left-1]
*/
