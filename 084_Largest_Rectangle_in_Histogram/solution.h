class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        int maxArea = 0;
        if (A.empty()) return maxArea;
        stack<int> s;
        A.push_back(0);
        
        for (int i = 0; i < A.size(); ++i)
        {
            while (!s.empty() && A[s.top()] > A[i])
            {
                int h = A[s.top()];
                s.pop();
                
                int index = s.empty() ? -1 : s.top();
                if (h * (i - 1 - index) > maxArea)
                    maxArea = h * (i - 1 - index);
            }
            s.push(i);
        }
        return maxArea;
    }
};
