
The importance of binary search algorithm

* search a value in a sorted array
	- Pay attention to [], (), [)
* search minest value in a rotated sorted array
	- ```
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
	```
