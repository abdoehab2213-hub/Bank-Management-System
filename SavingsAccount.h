#pragma once
#include "Account.h"
using namespace std;
class SavingsAccount : public Account
{
private:
	double minBalance;
public:
	SavingsAccount(int i, double b, double minBal=100.0);
	bool withdraw(double amount)override;
	string getAccountType()const override { return "savings"; }
	double getMinBalance() const { return minBalance; }
};

