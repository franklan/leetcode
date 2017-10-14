class Solution {
public:
    int maximalRectangle(vector<vector<char>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int rows = A.size();
        int cols = A[0].size();
        int maxRectangle = 0;
        
        vector<int> array(cols + 1, 0);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (A[i][j] > '0') array[j]++;
                else array[j] = 0;
            }
            int cur = largestRectangleArea(array);
            if (cur > maxRectangle)
                maxRectangle = cur;
        }

        return maxRectangle;
    }
private:
    int largestRectangleArea(vector<int>& A) {
        int maxArea = 0;
        if (A.empty()) return maxArea;
        stack<int> s;
        // A.push_back(0);
        
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
