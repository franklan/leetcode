
#1 Guarantee 1st array length larger than 2nd
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()<nums2.size()) 
        {
            return findMedianSortedArrays(nums2, nums1);
        }
    }        
            
            
#2 Binary Search with no Boundary Check


        int left = 0, right = m, half = (m + n +1) /2;
        int num1 = 0, num2 = 0;
        int i,j;
        while (left <= right)
        {
            i = (left+right)/2;
            j = half - i;
            if (nums2[j-1] > nums1[i]) left = i + 1;
            else if (nums2[j] < nums1[i-1]) right = j -1;
            else
            {
                num1 = max(nums1[i-1],nums2[j-1]);
                break;
            }
        }
        if (((m + n) & 1)) return num1;
        
        else num2 = min(nums1[i],nums2[j]);
        return (num1 + num2) / 2.;
        
        
        
#3 Add Boundary Check
        
        // if (nums2[j-1] > nums1[i]) left = i + 1;
        if (i<m && j>0 && nums2[j-1] > nums1[i]) left = i + 1;
        // else if (nums2[j] < nums1[i-1]) right = j -1;
        else if (i>0 && j<n && nums2[j] < nums1[i-1]) right = j -1;
        ...
        // num1 = max(nums1[i-1],nums2[j-1]);
        if (i == 0) num1 = nums2[j-1];
        else if (j == 0) num1 = nums1[i-1];
        else num1 = max(nums1[i-1],nums2[j-1]);        
        
        
