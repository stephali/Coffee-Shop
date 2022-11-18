/*
Coffee Shop Simulation
By: Stephanie Ali
Course: Software Design Patterns
Description: This is a simulation of a Coffee Shop ordering system.
             The cashier first greets the customer and asks the customer what they would like to order.
             The customer tells them their choice of drink.
             The program calculates the total price of the drink.
             The cashier asks for their name and tells them their grand total.
 */

#include <iostream>
#include <string>
using namespace std;

int main(){
    // Display menu
    cout << "--Menu--\n" <<
    "Brewed Coffees: House Blend, Dark Roast, Blonde Roast\n" <<
    "Lattes: Espresso\n" <<
    "Milks: Whole, Oat\n" <<
    "Flavors: Caramel, Vanilla\n" <<
    "Toppings: Whip, Cinnamon\n\n"
    ;

    // Take customer's order
    cout << "Welcome to Starbucks! What can I get started for you today?\n";
    string drinkChoice;
    cin >> drinkChoice;

    // Ask for customer's name
    cout << "You ordered a " << drinkChoice << ". May I have your name?\n";
    string customerName;
    cin >> customerName;

    // Give customer's total
    double total = 5.00;
    cout << "Thank you " << customerName << ". Your total is $" << total << ".\n";

    return 0;
}