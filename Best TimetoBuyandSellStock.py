class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_profit=0
        current=prices[0]

        for i in range(0,len(prices)):
            current=min(current,prices[i])
            max_profit=max(max_profit,prices[i]-current)
        return max_profit
