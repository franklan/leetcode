class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        
        int back = 0;
        int front = 0;
        while (back < nums.size())
        {
            if (nums[back] == val)
                back++;
            else
            {
                nums[front] = nums[back];
                front++;
                back++;
            }
        }
        return front;
    }
};
