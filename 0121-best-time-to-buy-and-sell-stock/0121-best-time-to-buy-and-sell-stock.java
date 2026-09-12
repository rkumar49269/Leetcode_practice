class Solution {
    public int maxProfit(int[] prices) {
       int n = prices.length;
       int maxi = 0;
       int bestBuy = prices[0];

       for(int i = 1; i < n; i++){
        if(prices[i] > bestBuy){
            maxi = Math.max(maxi, prices[i] - bestBuy);
        }
        bestBuy = Math.min(bestBuy, prices[i]);
       }
       return maxi;
    }
}