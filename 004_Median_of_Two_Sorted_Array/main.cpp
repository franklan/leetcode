#include "solution.h"
#include <iostream>

int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	vector<int> v2;
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	Solution s;
	std::cout<<s.findMedianSortedArrays(v1, v2)<<std::endl;
	return 0;
}
