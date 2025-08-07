//Personal Project #2
//Income Budgeting Program
// Joshua Bambe
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Transaction {
    string description;
    double amount;
    bool isIncome;
};

class BudgetProgram {
private:
    vector<Transaction> transactions;
    double balance;
    double savingsGoal;

public:
    BudgetProgram() : balance(0), savingsGoal(0) {}

    void loadData() {
        ifstream file("datasheet.txt");
        string description;
        double amount;
        bool isIncome;

        while (file >> description >> amount >> isIncome) {
            transactions.push_back({ description, amount, isIncome });
            if (isIncome) balance += amount;
            else balance -= amount;
        }
        file.close();
    }

    void saveData() {
        ofstream file("datasheet.txt");
        for (const auto& txn : transactions) {
            file << txn.description << " " << txn.amount << " " << txn.isIncome << "\n";
        }
        file.close();
    }

    void addIncome(double amount, const string& description) {
        transactions.push_back({ description, amount, true });
        balance += amount;
    }

    void addExpense(double amount, const string& description) {
        transactions.push_back({ description, amount, false });
        balance -= amount;
    }

    void setSavingsGoal(double goal) {
        savingsGoal = goal;
    }

    void viewBalance() const {
        cout << "Current Balance: $" << balance << endl << endl;
    }

    void viewSummary() const {
        double totalIncome = 0, totalExpense = 0;
        for (const auto& txn : transactions) {
            if (txn.isIncome) totalIncome += txn.amount;
            else totalExpense += txn.amount;
        }

        cout << "Total Income: $" << totalIncome << endl;
        cout << "Total Expenses: $" << totalExpense << endl;
        cout << "Remaining Balance: $" << balance << endl;
        cout << "Savings Goal: $" << savingsGoal << endl;
        cout << "Progess: $" << (balance - savingsGoal) << endl;
    }

    void showMenu() {
        while (true) {
            int option;
            cout << "----------------------------------------" << endl;
            cout << "---Budgeting Program---" << endl;
            cout << "----------------------------------------" << endl;
            cout << endl;
            cout << "1. Add Income" << endl;
            cout << "2. Add Expense" << endl;
            cout << "3. View Balance" << endl;
            cout << "4. View Summary" << endl;
            cout << "5. Set Saving Goals" << endl;
            cout << "6. Quit" << endl;
            cout << "Enter Option: " << endl;
            cin >> option;

            switch (option) {
            case 1: {
                string description;
                double amount;
                cout << "Enter Income Description: " << endl;
                cin.ignore();
                getline(cin, description);
                cout << "Enter Income Amount: $" << endl;
                cin >> amount;
                addIncome(amount, description);
                cout << "Income Added Sucessfully" << endl;
                break;
            }
            case 2: {
                string description;
                double amount;
                cout << "Enter Expense Description: " << endl;
                cin.ignore();
                getline(cin, description);
                cout << "Enter Expense Amount: $" << endl;
                cin >> amount;
                addExpense(amount, description);
                cout << "Expense Added Sucessfully" << endl;
                break;
            }
            case 3: {
                viewBalance();
                break;
            }
            case 4: {
                viewSummary();
                break;
            }
            case 5: {
                double goal;
                cout << "Enter Savings Goal: " << endl;
                cin >> goal;
                setSavingsGoal(goal);
                break;
            }
            case 6: {
                saveData();
                cout << "Saving Data..." << endl;
                cout << "..." << endl;
                cout << "..." << endl;
                cout << "Data Saved." << endl;
                cout << "Exiting Program..." << endl;
                return;
            default:
                cout << "ERROR" << endl;
                cout << "Invalid Option." << endl;
                cout << "Please Try Again Later" << endl;
            }
            }
        }
    }
};

int main()
{
    BudgetProgram app;
    app.loadData();
    app.showMenu();
    return 0;
}
