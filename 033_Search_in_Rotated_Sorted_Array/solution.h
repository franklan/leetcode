#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        
        int left = 0, right = nums.size() - 1;
		int mid = left;
        while (nums[left] >= nums[right])
        {
			cout<<"left:"<<left<<" right:"<<right<<endl;
			if (right - left == 1 || right == left)
			{
				mid = right;
				break;
			}
			mid = (left + right) / 2;
			if (nums[mid] > nums[right])
				left = mid;
			else
				right = mid;
        }
		int min = mid;
		cout<<"target:"<<target<<"  min:"<<min<<endl;
		left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			cout<<"left:"<<left<<" right:"<<right<<endl;
			mid = (left + right) / 2;
			int p = (mid + min) % nums.size();
			if (nums[p] == target)
				return p;
			if (nums[p] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
        return -1;
    }
};
