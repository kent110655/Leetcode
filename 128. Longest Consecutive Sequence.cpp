class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        int result = 0;
        int currentlen = 0;
        int tempt = 0;
        for(auto i:nums)
        {
            uset.insert(i);
        }
        for(auto t:uset)
        {
            if(uset.count(t-1)==0)
            {
                tempt = t;
                currentlen = 1;
                while(uset.count(tempt+1)!=0)
                {
                    currentlen++;
                    tempt++;
                }
                result=max(result,currentlen);
            }
        }
        return result;
    }
};

/*
Comment:
利用Hash table + 小技巧
因為題目要求O(n)以內，所以必定是用Hash table
1.把element放入hash table  :O(n)
2.loop map，找出各區段連續數的最小值的element
3.從各區段的最小值element往上數，紀錄下此區段的長度，並且更新result。
2.3 :O(n)

Time:
    O(n) + O(n) = O(n)
Space:
    O(n)
*/