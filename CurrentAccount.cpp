#include "CurrentAccount.h"
#include<iostream>
using namespace std;

CurrentAccount::CurrentAccount(int i, double b, double fee):Account(i,b)
{
	overdraftFee = fee;
}

bool CurrentAccount::withdraw(double amount)
{
	double totalAmount = amount + overdraftFee;
	if (totalAmount > balance) {
		cout << "Error: Not enough money (including a $" << overdraftFee << " transaction fee).\n";
		return false;
	}
	balance -= totalAmount;
	return true;
}
