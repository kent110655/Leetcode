class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return 0;
        int dif, difLast, difCount=0;
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            dif=nums[i+1]-nums[i];
            if(difLast==dif)
            {
                difCount++;
            }
            else
            {
                difLast=dif;
                ans+=(1+(difCount-1))*(difCount-1)/2;
                difCount=1;
            }
        }
        if(difCount>=2)
        {
            ans+=(1+(difCount-1))*(difCount-1)/2;
        }
        return ans;
    }
};

/*
Comment:
dif[i+1]=nums[i+1]-nums[i];
再看dif有幾段重複的element，分別算可以有多少subarry
*/
