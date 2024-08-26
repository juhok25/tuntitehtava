#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include <functional>
#include <future>	
#include <algorithm>
#include <execution>



int main() {



	std::vector<int> enemy_hp = { 200, 30, 110, 100, 500 };
	std::for_each(enemy_hp.begin(), enemy_hp.end(), [](int& hp) { hp = (hp > 100) ? hp - 100 : 0;});

	for (const int& hp : enemy_hp) {
		std::cout << hp << " ";
	}

	std::sort(enemy_hp.begin(), enemy_hp.end(), [](int a, int b) { return a > b; });
	std::cout << "\n";

	for (const int& hp : enemy_hp) {
		std::cout << hp << " ";
	}

	return 0;

}