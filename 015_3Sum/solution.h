#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        if (nums.size() < 3) return res;
        std::sort(nums.begin(), nums.end());
        
		for (int i = 0; i < nums.size(); ++i)
        {
			int target = -nums[i];
			int back = nums.size()-1, front = i+1;
			while (front < back)
			{
				int sum = nums[front] + nums[back];
				if (sum < target)
					front++;
				else if (sum > target)
					back--;
				else
				{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[front]);
                    temp.push_back(nums[back]);
                    res.push_back(temp);
					while (front < back && nums[front] == temp[1]) front++;
					while (front < back && nums[back] == temp[2]) back--;
				}
			}
           while (i < nums.size()-1 && nums[i] == nums[i+1]) ++i;
        }
        return res;
    }
};
