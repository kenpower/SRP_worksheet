// SRP-BankAccount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <fstream>
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
    string id;
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
    BankAccount(const string accountNumber) :id(accountNumber) {}

    void withdraw(float amount, string desc) {
        if (balance - amount < withdrawLimit) {
            cout << "Error: transaction not processed, withdraw limit breached: " << desc << ":" << amount << "\n";
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
        cout << setfill('=');
        cout << setw(49) << "\n";
        cout << "Bank Account Statement for a/c number: " << id << "\n";
        cout << setw(49) << "\n";

        cout << setfill(' ');

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

    void printStatementToHTML(const std::string& filepath) {
        std::ofstream htmlFile(filepath);


        htmlFile << "<!DOCTYPE html>\n<html>\n<head>\n";
        htmlFile << "<title>Bank Account Statement</title>\n";
        htmlFile << "<style>\n";
        htmlFile << "table { width: 100%; border-collapse: collapse; }\n";
        htmlFile << "th, td { border: 1px solid black; padding: 8px; }\n";
        htmlFile << "th { background-color: #f2f2f2; }\n";
        htmlFile << "</style>\n";
        htmlFile << "</head>\n<body>\n";

        htmlFile << "<h2>Bank Account Statement for a/c number: " << id << "</h2>\n";

        htmlFile << "<table>\n";
        htmlFile << "<tr>\n";
        htmlFile << "<th>Description</th><th>Credit</th><th>Debit</th><th>Balance</th>\n";
        htmlFile << "</tr>\n";

        // Transactions
        for (const auto& t : transactions) {
            std::ostringstream amountStream;
            amountStream << std::fixed << std::setprecision(2) << fabs(t.amount);
            htmlFile << "<tr>\n";
            htmlFile << "<td>" << t.description << "</td>";
            if (t.amount < 0) {
                htmlFile << "<td></td>"; // Empty cell for credit
                htmlFile << "<td>" << amountStream.str() << "€</td>"; // Debit amount
            }
            else {
                htmlFile << "<td>" << amountStream.str() << "€</td>"; // Credit amount
                htmlFile << "<td></td>"; // Empty cell for debit
            }
            htmlFile << "<td>" << std::fixed << std::setprecision(2) << t.balanceAfter << "€</td>\n";
            htmlFile << "</tr>\n";
        }

        // Close table
        htmlFile << "</table>\n";

        // End HTML document
        htmlFile << "</body>\n</html>";

        // Close file
        htmlFile.close();
    }

};

int main()
{
    BankAccount ac("124687935");

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

    std::cout << "\n\n\n" << "Web version of statment output to file `statment.html`" << "\n\n\n\n\n";
    ac.printStatementToHTML("statment.html");
}
