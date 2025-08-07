## Income Budgeting Program
A C++ console application to help users track their income and expenses, set savings goals, and view budget summaries. All data is saved to a local file.

## Features
- Add income entries with descriptions
- Add expense entries with descriptions
- View current balanace
- View income/expense summaries
- Set a savings goal and track progress
- Auto-load and saves data from/to datasheet.txt

## Project Structure
main.cpp - Main logic behind application |
datasheet.txt - Data file that stores all transactions

## How It Works
The program uses a simple text-based menu system to interact with the user. All transactions are stored in memory and saved to a file for use between sessions.

Each transation includes:
- Description
- Amount
- Income or Expense

The program automatically calculates:
- Total Income
- Total Expenses
- Remaining Balance
- Savings Goal Progress
  
## Getting Started
Prerequisites
- A C++ complier

How to Run the Program
1. Clone the repository:
   ```bash
   git clone https://github.com/Joshua-Bambe/income-budgeting-program.git
   cd income-budgeting-program

2. Compile the Program:
   g++ main.cpp -o budget

3. Run the Program

## Notes
- Data is saved in plain text format using whitespace-separated values
- Ensure you don't delete datasheet.txt if you want to preserve transaction history.
- Only texted-based
  
## About Developer
This income budgeting program was created by Joshua Bambe, an 18 year old aspiring software engineer and current computer science student at Southern Methodist University. Passionate about front-end desgin, back-end development, UI/UX, and artificial intelligence integration for the better of the entire world.
