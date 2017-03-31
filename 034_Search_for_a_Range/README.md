Summary of Binary Search

* 1. search minest value or proper position. 2. search low bound of target
	- range [ ) 
	- condition l < r
	- mid = (l + r) / 2
	- l = mid + 1
	- r = mid
	- value = A[l]
```
        int l = 0, r = A.size();
        int mid = l;
        while(l<r)
        {
            mid = l + (r - l) / 2;
            if (A[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
```

* search upper bound of target
	- range ( ]
	- condition l < r
	- mid = (l + r) / 2 + 1
	- l = mid
	- r = mid - 1
	- value = A[r]
```
        int l = -1, r = A.size() - 1;
        int mid = r;
        while(l<r)
        {
            mid = l + (r - l) / 2 + 1;
            if (A[mid] > target)
                r = mid - 1;
            else
                l = mid;
        }
        return r;
```


