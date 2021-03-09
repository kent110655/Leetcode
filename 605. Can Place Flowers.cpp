class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.insert(flowerbed.end(),0);
        for(int i=1;i<flowerbed.size()-1;i++)
        {
            if(flowerbed[i-1]!=1 && flowerbed[i+1]!=1 && flowerbed[i]==0)
            {
                count++;
                flowerbed[i]=1;
            }
        }
        return count>=n;
    }
};

/*
Comment:
使用Greedy
盡可能壓縮空間去種植。
在flowerbed前後各插入一個0以便判斷邊緣旁邊無植物。
時間複雜度：Ｏ(n)
*/
