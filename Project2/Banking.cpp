    // Yoel Marquez
    // 4/7/24
    // CS-210
    // Project 2

#include "Banking.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

Banking::Banking(){ // default constructor
    NumYears = 0;
    InitialInvestment = 0.0;
    MonthlyDeposit = 0.0;
    InterestRate = 0.0;
    BeginningBalance = 0.0;
    Interest = 0.0;
    ClosingBalance = 0.0;
}
//constructor with full parameters
Banking::Banking(double initialInvestment, double monthlyDeposit, double interestRate, int numYears) { 
    this->NumYears = numYears;
    this->InitialInvestment = initialInvestment;
    this->MonthlyDeposit = monthlyDeposit;
    this->InterestRate = interestRate / 100;
    BeginningBalance = initialInvestment;
    Interest = 0.0;
    ClosingBalance = 0.0;
}

//setters
void Banking::setInitialInvestment(double initialInvestment){
    this->InitialInvestment = initialInvestment;
}

void Banking::setNumYears(int numYears){
    this->NumYears = numYears;
}

void Banking::setMonthlyDeposit(double monthlyDeposit){
    this->MonthlyDeposit = monthlyDeposit;
}

void Banking::setInterestRate(double interestRate){
    this->InterestRate = interestRate;
}
//getters
int Banking::getNumYears(){
    return NumYears;
}
double Banking::getInitialInvestment(){
    return InitialInvestment;
}
double Banking::getMonthlyDeposit(){
    return MonthlyDeposit;
}
double Banking::getInterestRate(){
    return InterestRate;
}

// Methods

void Banking::updateBalances(){
    BeginningBalance = ClosingBalance; //update the last year progression
}

//calculator
void Banking::calcBalance(){
    Interest = BeginningBalance * InterestRate;
    Interest = round(Interest * 100) / 100;
    ClosingBalance = BeginningBalance + Interest;
}

// NO MONTHLY uses loop go through year and makes use of 2 other methods
void Banking::displayBalances(){ 
    int i;
    cout << "      " << "Balance and Interst Without Additional Monthly Deposits" << "         " << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << " Year                       Year End Balance                         Year End Earned Interest  " << endl;
    for(i = 1; i <= NumYears; i++){
        calcBalance();//recalculates new closing balance and interest
        cout << i << "                    " << ClosingBalance << "                   " << Interest << " " << endl;
        cout << endl;
        updateBalances(); // update values from the last year
    }
    displayBalancesM(); // starts the Month Menu
}

//compound interest calculation with months
void Banking::calcBalanceM(int i){
    
    ClosingBalance = InitialInvestment * pow(1 + InterestRate/12, 12 * i) + MonthlyDeposit * ((pow(1 + InterestRate/12, 12 * i) - 1) / (InterestRate/12));
    ClosingBalance = round(ClosingBalance * 100) / 100;
    Interest = ClosingBalance - (BeginningBalance + (MonthlyDeposit * 12));

}

//makes use of loops again and 2 other methods
void Banking::displayBalancesM(){
    int i;
    cout << "      " << "Balance and Interest With Additional Monthly Deposits" << "         " << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << " Year                   Year End Balance                         Year End Earned Interest  " << endl;
    for(i = 1; i <= NumYears; i++){
        calcBalanceM(i);
        cout << i << "                       " << ClosingBalance << "                      " << Interest << " " << endl;
        cout << endl;
        updateBalances();
    }
}


