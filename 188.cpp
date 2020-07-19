/*
Refers to: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/54118/C%2B%2B-Solution-with-O(n-%2B-klgn)-time-using-Max-Heap-and-Stack

plit the prices array into several consecutive ascending segments, with valley and peak index denoting the start and end point.
use a stack to process these segments into all possible profits.
employ a max heap to find the max k profits as the result.

Suppose we are facing two segments (v1,p1) and (v2, p2) under the limit v1 < p1
< v2 < p2, we would have two possible operations:
    buy at v1, sell at p1; buy at v2, sell at p2 ( p1 - v1 + p2 - v2 )
    buy at v1, sell at p2 ( p2 - v1 )

prices[v2] <= prices[v1]

    it’s obvious that we’d better make two transactions: p1-v1 and p2-v2, and
    v2 is more possible to make bigger profit. So, we pop out (v1,p1) from the
    stack.
prices[v2] > prices[v1]

    prices[p2] < prices[p1] We’d better use two transactions p1-v1 and p2-v2,
    and v1 is still more possible to make bigger profit. So, we keep (v1,p1) in
    the stack.
    prices[p2] >= prices[p1] We are not sure about using one or two
    transactions to get higher profit, so we push two possible results into the
    profits array. Here comes the key point: we push p2-v1 and p1-v2 into
    profits array. Why? If we could only use one transaction, p2-v1 is what we
    want, and if with two transactions, p2-v1 + p1-v2 is also the max profit.

Example:
prices #=> [ 1, 3, 2, 4 ]

# we could get
(v1, p1): (0 ,1)
(v2, p2): (2, 3)

# then push two possible profits
profits << prices[p2] - prices[v1]
profits << prices[p1] - prices[v2]

profits #=> [3, 1]

# If k is 1, the top profits is 3
# If k is 2, the top profits is 3+1
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        // find each valley/peak pair and output k largest profit
        int n=prices.size(), ret=0, v=0, p=0;
        vector<int> profits;
        stack<pair<int,int>> vp_pairs;
        while (p<n) {
            for (v=p; v<n-1 && prices[v]>=prices[v+1]; ++v);
            for (p=v+1; p<n && prices[p]>=prices[p-1]; ++p);
            // determine whether "v1"<p1<"v2"<p2 or not
            while(!vp_pairs.empty()&&prices[vp_pairs.top().first]>prices[v]) {
                int profit = prices[vp_pairs.top().second-1] -
                             prices[vp_pairs.top().first];
                profits.push_back(profit);
                vp_pairs.pop();
            }
            // [v1,p2] or [v1,p1]+[v2,p2]
            while(!vp_pairs.empty()&&prices[vp_pairs.top().second-1]<=prices[p-1]) {
                int different = prices[vp_pairs.top().second-1]-prices[v];
                profits.push_back(different);
                v=vp_pairs.top().first;
                vp_pairs.pop();
            }
            vp_pairs.push(make_pair(v,p));
        }
        while (!vp_pairs.empty()) {
            int profit = prices[vp_pairs.top().second - 1] -
                         prices[vp_pairs.top().first];
            profits.push_back(profit);
            vp_pairs.pop();
        }
        if (k>=profits.size()) {
            ret = accumulate(profits.begin(),profits.end(),0);
        }
        else {
            // pickup nth element: O(N)
            nth_element(profits.begin(), profits.begin()+profits.size()-k, profits.end());
            ret = accumulate(profits.begin()+profits.size()-k,profits.end(),0);
        }
        return ret;
    }
};

class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        /*
            Recall BestTimetoBuyandSellStock series problem.
            1 transaction: find min/max
            unlimited transaction: find each local min
            2 transactions: oneBuy/oneSale/twoBuy/twoSale
            k transactions: try to expand above approach.
        */
        // T:O(nk), S:O(k)
        vector<int> best_buy(k+1,INT_MAX); //cost
        vector<int> best_sale(k+1,0); //profit

        for (int price:prices) {
            for (int i=1; i<=k; ++i) {
                best_buy[i]=min(price-best_sale[i-1], best_buy[i]);
                best_sale[i]=max(price-best_buy[i], best_sale[i]);
            }
        }
        return best_sale[k];
    }
};
