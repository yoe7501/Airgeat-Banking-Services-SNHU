    // Yoel Marquez
    // 4/7/24
    // CS-210
    // Project 2


#pragma once
#ifndef BANKING_H
#define BANKING_H
#include <string>

using std::string;
using namespace std;

class Banking{
    public:
        int NumYears;
        double 
            InitialInvestment,
            MonthlyDeposit,
            InterestRate,
            BeginningBalance,
            Interest,
            ClosingBalance;
        Banking();
        Banking(double initialInvestment, double monthlyDeposit, double interestRate, int numYears);
        //set
        void setInitialInvestment(double);
        void setNumYears(int);
        void setMonthlyDeposit(double);
        void setInterestRate(double);
        //get
        int getNumYears();
        double getInitialInvestment();
        double getMonthlyDeposit();
        double getInterestRate();
        //used "M" for months to create the month added interest seperate.
        void displayBalances();
        void displayBalancesM();
        void calcBalance(); 
        void calcBalanceM(int i);
        void updateBalances(); // updates the closing balance into the next year (opening amount)




};

#endif