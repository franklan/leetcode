class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n-3; ++i)
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if (nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for (int j = i +1; j<n-2; ++j)
            {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                if (nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if (nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int front = j+1;
                int back = n -1;
                while (front < back)
                {
                    int sum = nums[i]+nums[j]+nums[front]+nums[back];
                    if (sum < target)
                        front++;
                    else if (sum > target)
                        back--;
                    else
                    {
                        res.push_back(vector<int>{nums[i],nums[j],nums[front],nums[back]});
                        do {front++;} while(front < back && nums[front] == nums[front-1]);
                        do {back--;} while(front < back && nums[back] == nums[back+1]);
                        // while (front < back && nums[front] == nums[front+1]) front++;
                        // TODO Should Be while (front < back && nums[front] == nums[temp[2]]) front++;
                        // while (front < back && nums[back] == nums[back-1]) back--;
                    }
                }
            }
        }
        return res;
    }
};
