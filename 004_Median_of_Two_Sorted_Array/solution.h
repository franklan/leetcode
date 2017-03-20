#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()>nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);

		// m should < n
        int m = nums1.size();
        int n = nums2.size();
        if (n == 0) return (m & 1) ? nums1[(m-1)/2] : (double(nums1[m/2-1])+nums1[m/2])/2;
 
        int left = 0, right = m, half = (m + n +1) /2;
        int num1 = 0, num2 = 0;
        int i = (left+right)/2;
        int j = half - i;
        while (left <= right)
        {
            i = (left+right)/2;	// cursor in array1
            j = half - i;		// cursor in array2
            cout<<"111 "<<"i:"<<i<<" j:"<<j<<endl;
            if (i < m && j>0 && nums2[j-1] > nums1[i]) left = i + 1;
            else if (i > 0 && j<n && nums2[j] < nums1[i-1]) right = i -1;
            else
            {
				cout<<"222 "<<"i:"<<i<<" j:"<<j<<endl;
                if (i == 0) num1 = nums2[j-1];
                else if (j == 0) num1 = nums1[i-1];
                else num1 = max(nums1[i-1],nums2[j-1]);
				
				if (((m + n) & 1)) return num1;
				if (i == m) num2 = nums2[j];
				else if (j == n) num2 = nums1[i];
				else num2 = min(nums1[i],nums2[j]);
				return (num1 + num2) / 2.0;
            }
        }
		cout<<"333 "<<"i:"<<i<<" j:"<<j<<endl;
        if (((m + n) & 1)) return num1;
        if (i == m) num2 = nums2[j];
        else if (j == n) num2 = nums1[i];
        else num2 = min(nums1[i],nums2[j]);
        return (num1 + num2) / 2.0;
    }
};
