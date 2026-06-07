#pragma once
#include<string>
class Account
{
protected:
	int id;
	double balance;
public:
	Account(int i,double b);
	virtual ~Account() {};
	void deposit(double amount);
	virtual bool withdraw(double amount);
	double getBalance() const;
	int getId() const ;
	virtual std::string getAccountType() const { return "Standard"; }
};

