class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n = v.size();
        stack<int>stk;

        int mx = 0;
        //O(N) 1 pass 
        //monotonic stack - has increasing values indices 

        for (int i = 0; i <= n; i++) {
            //top of stack is greater than cur element
            while (!stk.empty() && (i == n || v[i] <= v[stk.top()] ) ) { //reason we have (i==n): when we cross n-1 index , there can be some elements left in stack which didn't find nse yet(so they are not popped) for them nse is n , that nse it gets by i=n(rest all is same)

                int curElement = v[stk.top()];
                stk.pop();

                //so cur idx becomes the next smaller idx of stk.top()
                int nseIdx = i;
                //prev smaller element of stk.top() is 2nd element from top,i.e top() after 1 pop()
                int pseIdx = stk.empty() ? -1 : stk.top();

                int curArea = curElement * (nseIdx - pseIdx - 1);
                mx = max(mx , curArea);
            }
            stk.push(i);
        }
        return mx;
    }
};