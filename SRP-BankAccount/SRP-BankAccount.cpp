// SRP-BankAccount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <list>

using namespace std;

struct Transaction {
    string description;
    float amount;
    float balanceAfter;
};

class BankAccount {
    list<Transaction> transactions;
    float balance = 0;
    float withdrawLimit = -500;
    float overdraftInterestRate = 0.15;

    void processTransaction(string desc, float amount) {
        balance += amount;
        Transaction t{ desc, amount, balance };
        transactions.push_back(t);
    }
public:
    void withdraw(float amount, string desc) {
        if (balance - amount < withdrawLimit) {
            cout << "Error: transaction not processed, withdraw limit breached:" << desc << amount << "\n";
            return;
        }
        processTransaction(desc, -amount);
    }

    void lodgment(float amount, string desc) {
        processTransaction(desc, amount);
    }

    void chargeInterest() {
        if (balance < 0) {
            float interest = balance * overdraftInterestRate;
            processTransaction("Interest charged", interest);
        }
    }

    void printStatement() {

        int descipColWidth = 30;
        int amountColWidth = 12;
        cout << "Bank Account Statement\n";
        cout << "======================\n";

        cout << left << setw(descipColWidth) << ""
            << right << setw(amountColWidth) << "Credit" << right << setw(amountColWidth) << "Debit" << setw(amountColWidth) << "Balance" << "\n";
        cout << left << setw(descipColWidth) << ""
            << right << setw(amountColWidth) << "------" << right << setw(amountColWidth) << "-----" << setw(amountColWidth) << "-------" << "\n";


        for (auto& t : transactions) {
            // setw(30) sets the width of the description column to 30 characters, 
            // setfill to ensure that the extra space is filled with periods on the right side of the description text.
            // and setw(8) sets the width of the amount column to 8 characters, 
            // including the space for the euro sign and decimal places. 
            // The fixed and setprecision(2) ensure that
            // the amount is always displayed with two decimal places

            ostringstream amount;
            amount << std::fixed << std::setprecision(2) << t.amount;
       
            cout << left << setfill('.') << setw(descipColWidth)<< t.description << setfill(' ')
                << right << setw(amountColWidth)  << (t.amount < 0 ? amount.str() : "")
                << right << setw(amountColWidth)  << (t.amount >= 0 ? amount.str() : "")
                << right << setw(amountColWidth) << fixed << setprecision(2) << t.balanceAfter << "\n";
        }

    }
};

int main()
{
    BankAccount ac;

    ac.lodgment(1000, "Salary");
    ac.chargeInterest();
    ac.lodgment(550, "Xmas Bonus");
    ac.withdraw(400, "Hotels.com");
    ac.withdraw(300, "Tesco");
    ac.withdraw(700, "Rent");
    ac.withdraw(300, "ATM");
    ac.chargeInterest();
    ac.lodgment(1000, "Salary");
    ac.withdraw(350, "Tesco");
    ac.withdraw(2000, "Car purchase");
    ac.withdraw(700, "Rent");
    ac.chargeInterest();
    ac.lodgment(1000, "Salary");


    ac.printStatement();


}
