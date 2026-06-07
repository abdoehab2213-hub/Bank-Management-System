#include "BankSystem.h"
#include<iostream>
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include <fstream>
#include <sstream>

using namespace std;

BankSystem::BankSystem()
{
	loadFromFile();
}
BankSystem::~BankSystem()
{
	saveToFile();
	for (Account* acc : accounts) {
		delete acc;
	}
}


int BankSystem::findAccountIndex(int id)const {
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i]->getId() == id) {
			return i;
		}
	}
	return -1;
}

void BankSystem::addAccount(int typeChoice, int id, double initialBalance) {
	if (findAccountIndex(id) != -1) {
		cout << "Error: Account with ID " << id << " already exists!\n";
		return;
	}

	if (typeChoice == 1) {
		accounts.push_back(new SavingsAccount(id, initialBalance));
		cout << "Savings Account " << id << " created successfully.\n";
	}
	else if (typeChoice == 2) {
		accounts.push_back(new CurrentAccount(id, initialBalance));
		cout << "Current Account " << id << " created successfully.\n";
	}
	else {
		cout << "Invalid Account Type!\n";
	}
}
void BankSystem::displayAllAccounts()const {
	cout << "\n=== Bank Accounts List ===\n";
	for (const auto& acc : accounts) {
		cout << "ID: " << acc->getId()<< " | Type: " << acc->getAccountType() << " | Balance: $" << acc->getBalance() << "\n";
	}
	cout << "--------------------------\n";
}
void BankSystem::depositTo(int id, double amount) {
	int index = findAccountIndex(id);
	if (index != -1) {
		accounts[index]->deposit(amount);
		cout << "Deposited $" << amount << " to Account " << id << ".\n";
	}
	else {
		cout << "Account not found!\n";
	}
}
void BankSystem::withdrawFrom(int id, double amount) {
	int index = findAccountIndex(id);
	if (index != -1) {
		if (accounts[index]->withdraw(amount)) {
			cout << "Withdrew $" << amount << " from account " << id << ".\n";
		}
	}
	else {
		cout << "Account not found!\n";
	}
}
void BankSystem::transfer(int fromId, int toId, double amount) {
	int fromIndex = findAccountIndex(fromId);
	int toIndex = findAccountIndex(toId);
	if (fromIndex == -1 || toIndex == -1) {
		cout << "One or both accounts not found!\n";
		return;
	}
	if (accounts[fromIndex]->withdraw(amount)) {
		accounts[toIndex]->deposit(amount);
		cout << "Successfuly transferred $" << amount << " from account " << fromId << "to account " << toId << ".\n";
	}
}

void BankSystem::saveToFile() const {
	ofstream outFile(fileName);
	if (!outFile) {
		cout << "Error saving to file!\n";
		return;
	}
	for (const auto& acc : accounts) {
		outFile << acc->getAccountType() << "," << acc->getId() << "," << acc->getBalance() << "\n";
	}
	outFile.close();
}

void BankSystem::loadFromFile() {
	ifstream inFile(fileName);
	if (!inFile) return; 
	string line, type;
	int id;
	double balance;

	while (getline(inFile, line)) {
		stringstream ss(line);
		string idStr, balStr;

		getline(ss, type, ',');
		getline(ss, idStr, ',');
		getline(ss, balStr, ',');

		id = stoi(idStr);
		balance = stod(balStr);

		if (type == "Savings") {
			accounts.push_back(new SavingsAccount(id, balance));
		}
		else if (type == "Current") {
			accounts.push_back(new CurrentAccount(id, balance));
		}
	}
	inFile.close();
}