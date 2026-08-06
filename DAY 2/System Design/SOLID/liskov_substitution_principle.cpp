#include <iostream>
#include <vector>
#include <typeinfo>
#include <stdexcept>

using namespace std;

class DepositOnlyAccount
{
public:
    virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public DepositOnlyAccount
{
public:
    virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public WithdrawableAccount
{
private:
    double balance;

public:
    SavingsAccount()
    {
        balance = 0;
    }

    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited Amount: " << amount << endl;
        cout << "New Balance in Savings Account: " << balance << endl;
    }

    void withdraw(double amount) override
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrewn Amount: " << amount << endl;
            cout << "New balance in Savings account: " << balance << endl;
        }

        else
        {
            cout << "Insufficient funds in SavingsAccount" << endl;
        }
    }
};

class CurrentAccount : public WithdrawableAccount
{
private:
    double balance;

public:
    CurrentAccount()
    {
        balance = 0;
    }

    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited Amount: " << amount << endl;
        cout << "New Balance in Current Account: " << balance << endl;
    }

    void withdraw(double amount) override
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrewn Amount: " << amount << endl;
            cout << "New balance in Current Account: " << balance << endl;
        }
    }
};

class FixedDepositAccount : public DepositOnlyAccount
{
private:
    double balance;

public:
    FixedDepositAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited Amount: " << amount << endl;
        cout << "New balance in fixed deposit account: " << balance << endl;
    }
};

class BankClient
{
private:
    vector<WithdrawableAccount *> withdrawableAccounts;
    vector<DepositOnlyAccount *> depositOnlyAccounts;

public:
    BankClient(vector<WithdrawableAccount *> withdrawableAccounts,
               vector<DepositOnlyAccount *> depositOnlyAccounts)
    {
        this->withdrawableAccounts = withdrawableAccounts;
        this->depositOnlyAccounts = depositOnlyAccounts;
    }

    void processTransactions()
    {
        for (auto acc : withdrawableAccounts)
        {
            acc->deposit(1000);
            acc->withdraw(500);
        }

        for (auto acc : depositOnlyAccounts)
        {
            acc->deposit(5000);
        }
    }
};

int main()
{
    vector<WithdrawableAccount *> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingsAccount());
    withdrawableAccounts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount *> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedDepositAccount());

    BankClient *client = new BankClient(withdrawableAccounts, depositOnlyAccounts);
    client->processTransactions();

    return 0;
}

/*
Liskov Substitution principle states that the methods of the parent class must be substitutable by the child classes.

In the above example without LSP, there would be no DepositOnlyAccount, and so the FixedDepositAccount would then had to inherit the WithdrawableAccount. But FixedDepositAccount would not be able to use the withdraw method as withdrawing is not allowed. Temporary solution would be to add if else blocks in BankClient class, but then that would mean violating the Open Close Principle.

Hence, the best solution would be to segregate the DepositOnlyAccount abstract class and then use that interface to further inherit it into the FixedDepositAccount.
*/
