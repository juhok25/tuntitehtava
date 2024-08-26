#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include <functional>
#include <future>	
#include <algorithm>
#include <execution>

void takeDamage(int& hp) {
	
	if (hp > 100) {
		hp -= 100;
	}
	else {
		hp = 0;
	}
	
}

int main() {

	

	std::vector<int> enemy_hp = { 200, 30, 110, 100, 500 };
	std::for_each(enemy_hp.begin(), enemy_hp.end(), takeDamage);

	std::sort(enemy_hp.begin(), enemy_hp.end(), [](int a, int b) { return a > b; });
	
	for (const int& hp : enemy_hp) {
		std::cout << hp << " ";
	}

	return 0;

}

