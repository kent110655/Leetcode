class Solution {
public:
    int mySqrt(int x) {
        if(x<=1)
            return x;
        int left=0;
        int right=x;
        int mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(mid == x/mid)
                return mid;
            else if(mid > x/mid)
                right=mid-1;
            else
                left=mid+1;
        }
        return right;
    }
};

/*
Binary search
*/

/*
algo 1:
class Solution {
public:
    int mySqrt(int x) {
        int ans = sqrt(x);
        return ans;
    }
};
*/
