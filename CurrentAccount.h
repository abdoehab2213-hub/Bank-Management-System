#pragma once
#include "Account.h"
using namespace std;
class CurrentAccount : public Account
{
private:
	double overdraftFee;
public:
	CurrentAccount(int i, double b, double fee = 2.0);
	bool withdraw(double amount)override;
	string getAccountType()const override { return "current"; }

};

