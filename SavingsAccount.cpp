#include "SavingsAccount.h"
#include<iostream>
using namespace std;

SavingsAccount::SavingsAccount(int i, double b, double minBal):Account(i,b)
{
	minBalance = minBal;
}
bool SavingsAccount::withdraw(double amount)
{
	if (balance - amount < minBalance) {
		cout<< "Error: Cannot withdraw. Account " << id << " must maintain a minimum balance of $" << minBalance << "\n";
		return false;
	}
	balance -= amount;
	return true;
}
