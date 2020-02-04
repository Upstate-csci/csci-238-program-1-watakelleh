/********
 Author: Wata Kelleh
 Program: Money class - program assignment #1
 Due Date: February 3, 2020
 Purpose: programming money
 ********/
#include "money.h"

 // convert current currency values to a string
string Money::toString() {

    cout << hundreds << " hundreds " << tens << " tens " << fives << " fives " << ones << " ones " << quarters
        << " quarters" << dimes << " dimes " << nickels << " nickels " << pennies << "pennies";

    return "";
}

// format amount as a local currency and return
string Money::toCurrency(double amount) {
    stringstream ss;
    ss.imbue(locale(""));

    ss << showbase << put_money(amount * 100);

    return ss.str();

}




// convert currency to float
// read currency values from stdin and compute value
// return results
string Money::processChange() {
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> pennies;
    // adds the total amount of money
    total = static_cast<double>(hundreds) * 100 + static_cast<double>(tens) * 10 + static_cast<double>(fives) * 5 + static_cast<double>(ones) * 1 +
        static_cast<double>(quarters) * 0.25 + static_cast<double>(dimes) * 0.1 + static_cast<double>(nickels) * 0.05 + static_cast<double>(pennies) * 0.01;
    cout << toString() << " = " << toCurrency(total);

    return "";
}

// read from stdin and process float command
// convert float to change
// return results
string Money::processFloat() {

    float amountInt; 

    hundred = amountInt / 100;
    int var1 = static_cast<int>(amountInt) % 100;
    tens = var1 / 10;
    var1 = var1 % 10;
    fives = var1 / 5;
    var1 = var1 % 5;
    ones = var1 / 1;
    var1 = var1 % 1;
    var1 = static_cast<int>(amountInt * 100) % 100; // changes to an int
    int var2 = var1;
    quarters = var2 / 25;
    var2 = var2 % 25;
    dimes = var2 / 10;
    var2 = var2 % 10;
    nickels = var2 / 5;
    var2 = var2 % 5;
    pennies = var2 / 1;
    var2 = var2 % 1;

    cout << toString() << " = " <<  toCurrency(amountInt);
    return "";
}

// read from stdin and process check command
// convert float to dollar words & cents
// return results
string Money::processCheck() {
    return "";
}

// read from stdin and process change-float command
// read float of customer payment
// read float of transaction cost
// calculate difference and compute change values
// return the results
string Money::processChangeFloat() {
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> pennies;

    int amountInt, cost;
    double result = amountInt - cost;
    hundreds = result / 100;
    int var1 = result % 100;
    tens = var1 / 10;
    var1 = va1 % 10;
    fives = var1 / 5;
    var1 = var1 % 5;
    ones = var1 / 1;
    var1 = var1 % 1;
    var1 = static_cast<int>(result * 100) % 100; // changes to an int
    int var2 = var1;
    quarters = var2 / 25;
    var2 = static_cast<int>(var2) % 25;
    dimes = var2 / 10;
    var2 = static_cast<int>(var2) % 10;
    nickels = var2 / 5;
    var2 = static_cast<int>(var2) % 5;
    pennies = var2 / 1;
    var2 = static_cast<int>(var2) % 1;

    cout << "change back on " << toCurrency(amountInt) << " for purchase of " << toCurrency(cost) << " is "
        << toCurrency(result) << " which is " << toString();

    return "";
}

// read from stdin and process change-change command
// read change of customer payment
// read float of transaction cost
// calculate difference and compute change values
// output the results
string Money::processChangeChange() {
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> pennies; //input
    total = static_cast<double>(hundreds) * 100 + static_cast<double>(tens) * 10 + static_cast<double>(fives) * 5 + static_cast<double>(ones) * 1 +
        static_cast<double>(quarters) * 0.25 + static_cast<double>(dimes) * 0.1 + static_cast<double>(nickels) * 0.05 + static_cast<double>(pennies) * 0.01;

    float amountInt;
    cin >> cost;
    double result = total - cost;
    hundred = result / 100;
    int var1 = static_cast<int>(result) % 100;
    tens = var1 / 10;
    varl = var1 % 10;
    fives = var1 / 5;
    varl = var1 % 5;
    ones = var1 / 1;
    var1 = var1 % 1;
    var1 = static_cast<int>(result * 100) % 100; // changes to an int
    int var2 = var1;
    quarters = var2 / 25;
    var2 = static_cast<int>(var2) % 25;
    dimes = var2 / 10;
    var2 = static_cast<int>(var2) % 10;
    nickels = var2 / 5;
    var2 = static_cast<int>(var2) % 5;
    pennies = var2 / 1;
    var2 = static_cast<int>(var2) % 1;

    // output
    cout << "change back on " << toCurrency(total) << " for purchase of " << toCurrency(cost) << " is "
        << toCurrency(result) << " which is " << toString();

    return "";
}
