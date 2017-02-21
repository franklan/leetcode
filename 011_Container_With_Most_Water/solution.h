class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, cur = 0;
        int start = 0, end = height.size() - 1;
        while (start < end)
        {
            if (height[start] < height[end])
            {
                cur = (end - start) * height[start];
                start++;
            }
            else
            {
                cur = (end - start) * height[end];
                end--;
            }
            res = std::max(res, cur);
        }
        return res;
    }
};
