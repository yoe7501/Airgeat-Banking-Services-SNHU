    // Yoel Marquez
    // 4/7/24
    // CS-210
    // Project 2


#include <iostream>
#include <cmath>
#include "Banking.h"
#include "Banking.cpp"
void displayMenu(){ // display default menu
  cout << "********** Data Input ************\n";
  cout << "Initial Investment Amount: \n";
  cout << "Monthly Deposit: \n";
  cout << "Annual Interest: \n";
  cout << "Number of years: \n";
  cout << "Press any key to continue\n";
}
void getInput( double& initialInvestment, double& monthlyDeposit, double& interestRate, int& numYears){ //received input from the user apart from the main function
    cout <<"Initial Investment Amount:" << endl;
    cin >> initialInvestment ;
    cout << "Monthly Deposit: " << endl;
    cin >> monthlyDeposit ;
    cout << "Annual Interest: " << endl;
    cin >> interestRate;
    cout << "Number of year: " << endl;
    cin >> numYears;
}

int main(){
    
    int numYears = 0;
    double initialInvestment = 0.0;
    double monthlyDeposit = 0.0;
    double interestRate = 0.0;
    int num = 1;
    
    displayMenu(); // display default menu
    while (num == 1){ // as long as num is 1 loop continues
    getInput(initialInvestment, monthlyDeposit, interestRate, numYears); //receive input from user

    Banking user(initialInvestment, monthlyDeposit, interestRate, numYears); // use input to initialize the object

    
    user.displayBalances(); // start the recursive loops in the object
    cout << "Enter 1 if you want to enter another set if not enter another key" << endl;
    cin >> num ;
    }
    





    return 0;
}