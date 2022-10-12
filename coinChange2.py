class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        coins.sort(reverse=True)
        
        @lru_cache(maxsize=None)
        def f(i,amount):
            if amount == 0 : return 1
            if amount < 0  or i>=len(coins): return 0
            return f(i,amount-coins[i]) + f(i+1,amount)
        
        return f(0,amount)
