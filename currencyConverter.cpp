#include <iostream>
#include <map>
#include <iomanip>
#include<string>

using namespace std;

int main()
{
    map<string, double> rates;

    // Exchange rates relative to USD
    rates["USD"] = 1.0;
    rates["INR"] = 83.50;
    rates["EUR"] = 0.92;
    rates["GBP"] = 0.78;
    rates["JPY"] = 156.30;
    rates["AUD"] = 1.52;

    string baseCurrency, targetCurrency;
    double amount, convertedAmount;

    cout << "===== CURRENCY CONVERTER =====\n";

    cout << "\nAvailable Currencies:\n";
    cout << "USD - US Dollar\n";
    cout << "INR - Indian Rupee\n";
    cout << "EUR - Euro\n";
    cout << "GBP - British Pound\n";
    cout << "JPY - Japanese Yen\n";
    cout << "AUD - Australian Dollar\n";

    // User input
    cout << "\nEnter Base Currency: ";
    cin >> baseCurrency;

    cout << "Enter Target Currency: ";
    cin >> targetCurrency;

    // Validate currency
    if (rates.find(baseCurrency) == rates.end() ||
        rates.find(targetCurrency) == rates.end())
    {
        cout << "\nInvalid Currency Code!" << endl;
        return 0;
    }

    cout << "Enter Amount: ";
    cin >> amount;

    if(amount < 0)
    {
        cout << "Invalid Amount!" << endl;
        return 0;
    }

    // Conversion formula
    convertedAmount =
        (amount / rates[baseCurrency]) * rates[targetCurrency];

    cout << fixed << setprecision(2);

    cout << "\n===== CONVERSION RESULT =====\n";
    cout << amount << " " << baseCurrency
         << " = "
         << convertedAmount << " "
         << targetCurrency << endl;

    cout << "\nThank You!" << endl;

    return 0;
}