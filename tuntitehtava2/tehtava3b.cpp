#include <iostream>
#include <thread>
#include <mutex>
#include <future>


std::mutex mtx;
int bankAccount = 0;

void deposit(int numDeposits) {

	for (int i = 0; i < numDeposits; i++)
	{
		std::lock_guard<std::mutex> lock(mtx); // lock mutex 
		++bankAccount;
	}
}

void withdraw(int numWithdrawals) {

	for (int i = 0; i < numWithdrawals; i++)
	{
		std::lock_guard<std::mutex> lock(mtx); // lock mutex 
		--bankAccount;
	}
}

int main() {

	int numDeposits = 100000000; // nosto/otto operaatiot per thread
	int numWithdrawals = 100000000;

	auto x = std::async(deposit, numDeposits);
	auto y = std::async(withdraw, numWithdrawals);

	/*depositThread.join();
	withdrawThread.join();*/


	std::cout << "Final bank account balance: " << bankAccount << std::endl;

	return 0;
}