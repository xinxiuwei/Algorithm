

/*.................
风口之下，猪都能飞。当今中国股市牛市，真可谓“错过等七年”。 给你一个回顾历史的机会，
已知一支股票连续n天的价格走势，以长度为n的整数数组表示，数组中第i个元素（prices[i]）
代表该股票第i天的股价。 假设你一开始没有股票，但有至多两次买入1股而后卖出1股的机会，
并且买入前一定要先保证手上没有股票。若两次交易机会都放弃，收益为0。
设计算法，计算你能获得的最大收益。 输入数值范围：2<=n<=100,0<=prices[i]<=100 



....................*/
/*
解题思路：
        利用动态规划的思想。 
        首先从左往右扫描，先计算出子序列[0,...,i]中的最大利润，
        用一个vector<int>类型Max保存下来，时间是O(n)。第二步是从右往左逆向扫描，
        计算子序列[i,...,n-1]上的最大利润，加到Max[i]中，时间是O(n)，
        最后遍历Max[i]，找出其中最大值就是最大收益，
        这一步也是O(n)。 所以最后算法的复杂度就是O(n)的。


*/

class Solution {
public:
    /**
     * 计算你能获得的最大收益
     * 
     * @param prices Prices[i]即第i天的股价
     * @return 整型
     */
    int calculateMax(vector<int> prices) {
        
        vector<int> Max(prices.size(),0);
        int prices_min=prices[0];
        int prices_max=prices[prices.size()-1];
        int profit=0;
        for(int i=0;i<prices.size();++i)
            {
            
            profit=max(profit,(prices[i]-prices_min));
            prices_min=min(prices_min,prices[i]);
            Max[i]=profit;
        }
        profit=0;
        for(int i=prices.size()-1;i>=0;--i)
            {
            profit=max(profit,(prices_max-prices[i]));
            Max[i]+=profit;
            prices_max=max(prices_max,prices[i]);
        }
        profit=0;
        for(int i=0;i<prices.size();i++)
            {
            profit=max(Max[i],profit);
        }
        return profit;

    }
};