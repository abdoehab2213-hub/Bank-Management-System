#pragma once
#include<vector>
#include "Account.h"
#include <string>
using namespace std;
class BankSystem
{
private:
	vector<Account*>accounts;
	const string fileName = "accounts.txt";
	int findAccountIndex(int id) const;
public:
	BankSystem();
	~BankSystem();

	void addAccount(int typeChoice, int id, double initialBalance);
	void displayAllAccounts()const;
	void depositTo(int id, double amount);
	void withdrawFrom(int id, double amount);
	void transfer(int fromId, int toId, double amount);

	void saveToFile() const;
	void loadFromFile();
};

