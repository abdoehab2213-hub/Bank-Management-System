#include "Account.h"
#include<iostream>
using namespace std;
Account::Account(int i,double b)
{
	id = i;
	balance = b;
}
void Account::deposit(double amount)
{
	balance += amount;
}
bool Account::withdraw(double amount)
{
	if (amount > balance)
	{
		cout << "not enough money" << endl;
		return false;
	}
	else {
		balance -= amount;
		return true;
	}
}
double Account::getBalance() const{
	return balance;
}

int Account::getId()const
{
	return id;
}
