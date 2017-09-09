class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        vector<int> index;
        heights.push_back(0);
        
        for (int i = 0; i < heights.size(); ++i)
        {
            while(!index.empty() && heights[index.back()] >= heights[i])
            {
                int h = heights[index.back()];
                index.pop_back();
                
                int sidx = index.size() > 0 ? index.back() : -1;
                if(h * (i-sidx-1) > res)
                    res = h * (i-sidx-1);
            }
            index.push_back(i);
        }
        return res;
    }
};
