class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3) return 0;
		std::sort(nums.begin(), nums.end());
		int res = nums[0] + nums[1] + nums[2];
		for (int i = 0; i< nums.size(); ++i)
		{
			int front = i+1;
			int back = nums.size() - 1;
			while (front < back)
			{
				int sum = nums[front] + nums[back] + nums[i];
				if (sum == target)
					return sum;
				if (abs(res - target) > abs(sum - target))
					res = sum;
				else if (sum < target)
					front++;
				else
					back--;
			}
		}
		return res;
    }
};
