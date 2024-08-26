#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include <functional>
#include <future>
#include <algorithm>
#include <execution>



int main() {

	const size_t size = 100000; 
	std::vector<int> vec(size);
	std::iota(vec.begin(), vec.end(), 0);
	

	std::for_each(std::execution::par, vec.begin(), vec.end(), [](int& n) { n += 1; });
	//std::for_each(std::execution::seq, vec.begin(), vec.end(), [](int& n) { n += 1; });
	//std::for_each(std::execution::par_unseq, vec.begin(), vec.end(), [](int& n) { n+=1; });
	
	
	//for (int x : vec) // print 
	//	printf("%d\n", x);

	return 0;
}