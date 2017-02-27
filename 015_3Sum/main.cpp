#include "solution.h"
#include <iostream>
using namespace std;

template<class T>
void print_vec (vector<T>& vec)
{
	for (auto& it:vec)
		cout<<it<<" ";
	cout<<endl;
}

template<class T>
void print_vvec ( vector<vector<T> > vec)
{
	for (auto& it:vec)
		print_vec(it);
}

int main()
{
	Solution s;
	vector<int> vec{0,0,0,0};
	// std::cout << s.threeSum(vec) << std::endl;
	print_vvec(s.threeSum(vec));

	return 0;
}
