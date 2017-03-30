#include "solution.h"

int main()
{
	// int array[] = {4,5,6,7,8,0,1,2};
	int array[] = {1};
	std::vector<int> v(array, array + sizeof(array)/sizeof(int));
	Solution s;

	cout<<s.search(v, 4)<<endl;
	cout<<s.search(v, 5)<<endl;
	cout<<s.search(v, 6)<<endl;
	cout<<s.search(v, 7)<<endl;
	cout<<s.search(v, 8)<<endl;
	cout<<s.search(v, 0)<<endl;
	cout<<s.search(v, 1)<<endl;
	cout<<s.search(v, 2)<<endl;

	return 0;
}
