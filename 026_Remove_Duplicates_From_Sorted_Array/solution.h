class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int old_i = 1;
        int new_i = 1;
        int num = nums[0];
        while (old_i < nums.size()) {
            if (nums[old_i] != num) {
                nums[new_i] = nums[old_i];
                num = nums[old_i];
                new_i++;
            }
            old_i++;
        }
        return new_i;
    }
};
