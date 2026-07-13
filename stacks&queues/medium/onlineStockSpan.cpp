/*
Problem: Online Stock Span 
Platform: LeetCode #901
Difficulty: Medium 

Approach:
1. Follow the approach for the previous greater element.
2. For every next operation, pop out the smaller or equal elements and the span is (current index- index of pge).

Time Complexity: O(2N)
Space Complexity: O(N)

Date Solved: 2026-07-13 
*/

class StockSpanner {
public:
    stack <pair<int, int>> st;
    int idx=-1;
    StockSpanner() {
        idx=-1;
        while (!st.empty()){
            st.pop();
        }        
    }
    
    int next(int price) {
        idx++;
        while (!st.empty() && st.top().first<=price){
            st.pop();
        }
        int ans= idx- (st.empty()? -1: st.top().second);
        st.push({price, idx});
        return ans;        
    }
};

