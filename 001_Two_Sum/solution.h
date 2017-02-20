class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        vector<int> sorted_nums(nums);
        std::sort(sorted_nums.begin(), sorted_nums.end());
        int start = 0;
        int end = sorted_nums.size() - 1;
        while (sorted_nums[start] + sorted_nums[end] != target && start < end)
        {
            if (sorted_nums[start] + sorted_nums[end] > target)
                end--;
            else if (sorted_nums[start] + sorted_nums[end] < target)
                start++;
        }
        if (sorted_nums[start] + sorted_nums[end] == target)
        {
            for (int i = 0; i < nums.size(); ++i)
            {
                if (sorted_nums[start] == nums[i] || sorted_nums[end] == nums[i])
                    res.push_back(i);
            }
        }
        return res;
    }
};
