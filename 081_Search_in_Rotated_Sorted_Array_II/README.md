Summary of Binary Search in Rotated Sorted Array 

First of all, use a () to get the minest number

if A[l] == A[mid] == A[r], then use o(n) method to search


Then use [] binary search with offset to search target

```
	if (A.empty()) return false;
	// ( ), pay attention to out of range
	// pay attention to judgement, left first, and then right
	int l = 0, r = A.size() - 1;
	int mid = l;
	
	while (A[l] >= A[r])
	{
		if (r - l == 1 || r == l)
		{
			mid = r;
			break;
		}
		mid = l + (r - l) / 2;
		if (A[mid] == A[l] && A[l] == A[r])
		{
			mid = descend(A, l, r);
			break;
		}
		else if (A[mid] >= A[l])
			l = mid;
		else if (A[mid] <= A[r])
			r = mid;
		cout<<l<<" "<<r<<" "<<mid<<endl;
	}
	int offset = mid;
	cout<<"offset:"<<offset<<endl;
	// []
	l = 0, r = A.size() - 1;
	while (l <= r)
	{
		mid = l + (r - l) / 2;
		int p = (mid + offset) % A.size();
		if (A[p] == target)
			return true;
		else if (A[p] < target)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return false;
}
int descend(vector<int>& A, int l,int r) {
	for (int i = l; i< r; ++i)
	{
		if (A[i] > A[i+1])
			return i+1;
	}
	return l;
}
};
```
