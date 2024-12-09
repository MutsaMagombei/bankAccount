#include <iostream>
using namespace std;
// function to create a new account
void createAccount(string &name, int &accountNumber, double &balance) {
  // ask user for name
  cout << "Please enter your name: " << endl;
  // store answer in variable
  cin >> name;
  // ask user for account number
  cout << "Please enter your 10 digit account number: " << endl;
  // store answer in variable
  cin >> accountNumber;
  // ask user for initial deposit
  cout << "Please enter your initial deposit (amount must be greater than 0): R";
  cin >> balance;
  cout << "\n\n";
  // ensure that amount is greater than 0
  while (balance <= 0) {
    cout << "Initial deposit must be greater than R0, please try again: R";
    cin >> balance;
  }
  };

void depositMoney(double &balance) {
  double depositAmount;
  // ask user how much they would like to depoit into account
  cout << "Please enter the amount you would like to deposit (amount must be "
          "greater than 0): R";
  cin >> depositAmount;
  // ensure that amount is greater than 0
  while (depositAmount <= 0) {
    cout << "Deposit amount must be greater than R0, please try again: R";
    cin >> depositAmount;
  }
  //add the deposit amount to the balance
  balance = balance + depositAmount;
  //confirmation of deposit
  cout << "You have deposited R" << depositAmount << " into your account\n\n" << endl;
};

void withdrawMoney(double &balance) {
  double withdrawAmount;
  // show user how much is currently in the account
  cout << "You currently have R" << balance << " in your account." << endl;
  // ask user how much they would like to withdraw from account
  cout << "Please enter the amount you would like to withdraw (up to R"
       << balance << "): R";
  cin >> withdrawAmount;
  // ensure that amount is less than or equal to balance but greater than 0
  while (withdrawAmount <= 0 || withdrawAmount > balance) {
    if (withdrawAmount <= 0) {
      cout << "Withdrawal amount must be greater than R0, please try again: R"
           << endl;
    } else if (withdrawAmount > balance) {
      cout << "Withdrawal amount cannot be greater than R" << balance
           << ", please try again: R";
    }
    cin >> withdrawAmount;
  }
  // deduct withdrawal amount from balance
  balance = balance - withdrawAmount;
  // confirm withdrawal amount
  cout << "You have withdrawn R" << withdrawAmount << " from your account."
       << endl;
  cout << "Your current balance is R" << balance << endl;
  cout << "\n\n";
};

void checkBalance(double &balance) {
  // show user how much is currently in the account
  cout << "You currently have R" << balance << " in your account.\n\n" << endl;
}

void displayAccountDetails(const string &name, const int &accountNumber,
                           const double &balance) {
  // show account holder's name
  cout << "Account holder's name: " << name << endl;
  // show account number
  cout << "Account number: " << accountNumber << endl;
  // show current account balance
  cout << "Current balance: R" << balance << endl;
  cout << "\n\n";
}

int main() {
  int choice = 0;
  bool quit = false;
  // declare name in main function
  string name;
  // declare accountNumber in main function
  int accountNumber;
  // declare balance in main function
  double balance;
  do {
    cout << "1. Create Account" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Display Account Details" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice (1 - 6): ";
    cin >> choice;

    switch (choice) {
    case 1:
      // if user chooses 1, call createAccount function
      cout << "\n\n--Creating account your account--" << endl;
      createAccount(name, accountNumber, balance);
      break;
    case 2:
      // if user chooses 2, call depositMoney function
      cout << "\n\n--Depositing money into your account--" << endl;
      depositMoney(balance);
      break;
    case 3:
      // if user chooses 3, call withdrawMoney function
      cout << "\n\n--Withdrawing money from your account--" << endl;
      withdrawMoney(balance);
      break;
    case 4:
      // if user chooses 4, call checkBalance function
      cout << "\n\n--Checking your account balance--" << endl;
      checkBalance(balance);
      break;
    case 5:
      // if user chooses 5, call function displayAccountDetails
      cout << "\n\n--Displaying account details--" << endl;
      displayAccountDetails(name, accountNumber, balance);
      break;
    case 6:
      // if user chooses 6, set quit to true
      cout << "\n\n--Thank you for banking with us, Goodbye!--" << endl;
      quit = true;
      break;

    default:
      // if user chooses anything other than 1-6, display error message
      cout << "\n\nInvalid option entered, please choose a value between 1 and 6."
           << endl;
    }
  } while (!quit);
}