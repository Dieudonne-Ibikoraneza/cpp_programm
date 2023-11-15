#include <iostream>
#include <string>
#include "cmath"
using namespace std;

int main() {
    string fullName;
    float initialAmount, interest_rate, payment_time, interest;

    cout << "Enter your full name: ";
    getline(cin, fullName);

    cout << "Enter the initial amount (Principal): ";
    cin >> initialAmount;

    cout << "Enter the interest rate(from 0 to 100): ";
    cin >> interest_rate;

    // Clear the input buffer
    cin.sync();

    cout << "Enter the payment time in years(from 1): ";
    cin >> payment_time;

    if (interest_rate < 0 || interest_rate > 100) {
        cout << "Enter valid values! The interest rate should be from 0 to 100, and payment time should be at least 1 year. Give it another try!";
    } else {
        // Calculate interest based on monthly compounding if payment time is less than 1 year
        if (payment_time < 1) {
            int months = payment_time * 12; // Convert payment time to months
            interest = initialAmount * pow(1 + interest_rate / 100 / 12, months) - initialAmount;
        } else {
            interest = initialAmount * interest_rate * payment_time / 100;
        }

        cout << "When someone like " << fullName
             << ", invests in a bank providing the " << interest_rate
             << "% as the interest rate with the initial amount of " << initialAmount
             << " FRW in " << payment_time
             << ", he/she gets the Interest of " << interest << " FRW" << endl;
    }

    return 0;
}
