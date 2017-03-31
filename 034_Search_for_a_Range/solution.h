class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) return res;
        int left = 0, right = nums.size() - 1;
        int mid = left;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
            cout<<"mid:"<<mid<<" l:"<<left<<" r:"<<right<<endl;
        }
        if (nums[left]!=target) return res;
        else res[0] = left;
        
        right = nums.size() - 1;
        while (left < right)
        {
            mid = left + (right - left) / 2 + 1;
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid;
            cout<<"mid:"<<mid<<" l:"<<left<<" r:"<<right<<endl;
        }
        res[1] = right;
        return res;
    }
};
