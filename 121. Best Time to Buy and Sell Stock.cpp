class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=0;
        for(auto u:prices)
        {
            minPrice=min(minPrice, u);
            maxProfit=max(maxProfit,u-minPrice);
        }
        return maxProfit;
    }
};

/*
algo 1:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dif=0;
        int difMax=0;
        for(int i=1;i<prices.size();i++)
        {
            dif=max(dif+prices[i]-prices[i-1], 0);
            difMax=max(difMax,dif);
        }
        return difMax;
    }
};

Comment:
dif代表第i個element賣出所獲得的最大profit
difMax紀錄所有element賣出所獲得的diff中的最大值
*/

/*
algo 2:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> minPrice(prices.size());
        vector<int> maxProfit(prices.size());
        minPrice[0]=prices[0];
        maxProfit[0]=0;
        for(int i=1;i<prices.size();i++)
        {
            minPrice[i]=min(minPrice[i-1],prices[i]);
            maxProfit[i]=max(maxProfit[i-1], prices[i]-minPrice[i]);
        }
        return maxProfit[prices.size()-1];
    }
};

Comment:
利用DP
minPrice紀錄最小price
maxProfit紀錄最大profit
maxProfit[n-1]即所求。
*/

/*
algo 3:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=0;
        for(auto u:prices)
        {
            minPrice=min(minPrice, u);
            maxProfit=max(maxProfit,u-minPrice);
        }
        return maxProfit;
    }
};

Comment:
不用紀錄所有階段的minPrice跟maxProfit，只需紀錄最後的maxProfit。
買進price必為此階段最小price
所以掃一遍所有prices，求出每個賣出price所獲得的profit
紀錄每個階段最小的price，並且分別紀錄最大profit。
*/
