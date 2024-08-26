#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include <functional>
#include <future>

void sum_part(const std::vector<int>& vec, size_t start, size_t end, long long& result) {
	result = std::accumulate(vec.begin() + start, vec.begin() + end, 0LL);
}

int main() {

	unsigned int n = std::thread::hardware_concurrency();
	std::cout << n << " concurrent threads are supported. \n";

	const size_t size = 5000000; // 50 milj
	const int num_parts = 4; // 4 osaan


	std::vector<int> vec(size);
	std::iota(vec.begin(), vec.end(), 1); // t‰ytet‰‰n vektori arvoilla 1,2,3,4... jne

	std::vector<long long> results(num_parts, 0);

	size_t part_size = size / num_parts;
	std::vector<std::thread> threads;


	// taulukon jako osiin, 
	for (int i = 0; i < num_parts; i++)
	{
		size_t start = i * part_size;
		size_t end = (i == num_parts - 1) ? size : start + part_size;
		// threads.emplace_back(sum_part, std::cref(vec), start, end, std::ref(results[i]));
		async(sum_part, std::cref(vec), start, end, std::ref(results[i]));
	}

	for (auto& th : threads) {
		th.join();
	}

	// lasketaan kaikkien osien summat yhteen
	long long total_sum = std::accumulate(results.begin(), results.end(), 0LL);

	std::cout << "Taulukon summa on: " << total_sum << std::endl;
	return 0;

}