/**
* Coffee Shop Simulation
* By: Stephanie Ali
* Course: Software Design Patterns
* Description: This is a simulation of a Coffee Shop ordering system.
*              The cashier first greets the customer and asks the customer what they would like to order.
*              The customer tells them their choice of drink.
*              The program calculates the total price of the drink.
*              The cashier asks for their name and tells them their grand total.
**/

#include <iostream>
#include <string>
using namespace std;

//------Component----//
class Drink {
public:
    virtual ~Drink() {}
    virtual std::string Operation() const = 0;
    virtual double Cost() const = 0;

};

//------Concrete Components----//
class HouseBlend : public Drink {
public:
    std::string Operation() const override {
        return "HouseBlend with";
    }
    double Cost() const override {
        return 2.00;
    }
};

class DarkRoast : public Drink {
public:
    std::string Operation() const override {
        return "DarkRoast with";
    }
    double Cost() const override {
        return 2.00;
    }
};

class BlondeRoast : public Drink {
public:
    std::string Operation() const override {
        return "BlondeRoast with";
    }
    double Cost() const override {
        return 2.00;
    }
};

class Espresso : public Drink {
public:
    std::string Operation() const override {
        return "Espresso with";
    }
    double Cost() const override {
        return 1.50;
    }
};

//------Decorator----//
class CondimentDecorator : public Drink {
protected:
    Drink* drink_;

public:
    CondimentDecorator(Drink* drink) : drink_(drink) {
    }
    std::string Operation() const override {
        return this->drink_->Operation();
    }
    double Cost() const override {
        return this->drink_->Cost();
    }
};

//------Concrete Decorators----//
class Caramel : public CondimentDecorator {
public:
    Caramel(Drink* drink) : CondimentDecorator(drink) {
    }
    std::string Operation() const override {
        return CondimentDecorator::Operation() + " Caramel,";

    }
    double Cost() const override {
        return CondimentDecorator::Cost() + 0.20;

    }
};

class Vanilla : public CondimentDecorator {
public:
    Vanilla(Drink* drink) : CondimentDecorator(drink) {
    }

    std::string Operation() const override {
        return CondimentDecorator::Operation() + " Vanilla,";
    }
    double Cost() const override {
        return CondimentDecorator::Cost() + 0.20;

    }
};

class Whip : public CondimentDecorator {
public:
    Whip(Drink* drink) : CondimentDecorator(drink) {
    }

    std::string Operation() const override {
        return CondimentDecorator::Operation() + " Whip,";
    }
    double Cost() const override {
        return CondimentDecorator::Cost() + 0.30;

    }
};

class Cinnamon : public CondimentDecorator {
public:
    Cinnamon(Drink* drink) : CondimentDecorator(drink) {
    }

    std::string Operation() const override {
        return CondimentDecorator::Operation() + " Cinnamon,";
    }
    double Cost() const override {
        return CondimentDecorator::Cost() + 0.20;

    }
};

class Whole : public CondimentDecorator {
public:
    Whole(Drink* drink) : CondimentDecorator(drink) {
    }

    std::string Operation() const override {
        return CondimentDecorator::Operation() + " Whole Milk,";
    }
    double Cost() const override {
        return CondimentDecorator::Cost() + 0.50;

    }
};

class Oat : public CondimentDecorator {
public:
    Oat(Drink* drink) : CondimentDecorator(drink) {
    }

    std::string Operation() const override {
        return CondimentDecorator::Operation() + " Oat Milk,";
    }
    double Cost() const override {
        return CondimentDecorator::Cost() + 0.50;

    }
};

//------Client Code----//
void displayDrink(Drink* drink) {
    // ...
    std::cout << "You ordered a: " << drink->Operation();
    std::cout << "\nYour total is: $" << drink->Cost();
    // ...
}

//------Main----//
int main() {
    cout << "Welcome to Starbucks! What can I get started for you today?\n";
    bool running = true;
    while(running){
        std::cout << "Coffees: [1]House Blend ($2.00), [2]Espresso ($1.50), [3]Blonde Roast ($2.00), [4]Dark Roast ($2.00)\n";

        int coffeeChoice;
        int condimentChoice;
        std::cin >> coffeeChoice;

        if(coffeeChoice == 1){
            Drink* drink = new HouseBlend;
            while(true){
                std::cout << "Condiments: [1]Vanilla ($0.20), [2]Caramel ($0.20), [3]Whip ($0.30), [4]Cinnamon ($0.20), [5]Whole Milk ($0.50), [6]Oat Milk ($0.50), [7]Done\n";
                std::cin >> condimentChoice;

                if(condimentChoice == 7){
                    running = false;

                    break;
                }else if(condimentChoice == 1){
                    drink = new Vanilla(drink);

                }else if(condimentChoice == 2){
                    drink = new Caramel(drink);

                }else if(condimentChoice == 3){
                    drink = new Whip(drink);

                }else if(condimentChoice == 4){
                    drink = new Cinnamon(drink);

                }else if(condimentChoice == 5){
                    drink = new Whole(drink);

                }else if(condimentChoice == 6){
                    drink = new Oat(drink);
                }else{
                    std::cout << "Enter a Valid Choice\n";

                }
            }
            std::cout << "\n\n";
            displayDrink(drink);

        }else if(coffeeChoice == 2){
            Drink* drink = new Espresso;
            while(true){
                std::cout << "Condiments: [1]Vanilla ($0.20), [2]Caramel ($0.20), [3]Whip ($0.30), [4]Cinnamon ($0.20), [5]Whole Milk ($0.50), [6]Oat Milk ($0.50), [7]Done\n";
                std::cin >> condimentChoice;

                if(condimentChoice == 7){
                    running = false;

                    break;
                }else if(condimentChoice == 1){
                    drink = new Vanilla(drink);

                }else if(condimentChoice == 2){
                    drink = new Caramel(drink);

                }else if(condimentChoice == 3){
                    drink = new Whip(drink);

                }else if(condimentChoice == 4){
                    drink = new Cinnamon(drink);

                }else if(condimentChoice == 5){
                    drink = new Whole(drink);

                }else if(condimentChoice == 6){
                    drink = new Oat(drink);
                }else{
                    std::cout << "Enter a Valid Choice\n";

                }
            }
            std::cout << "\n\n";
            displayDrink(drink);

        }else if(coffeeChoice == 3){
            Drink* drink = new BlondeRoast;
            while(true){
                std::cout << "Condiments: [1]Vanilla ($0.20), [2]Caramel ($0.20), [3]Whip ($0.30), [4]Cinnamon ($0.20), [5]Whole Milk ($0.50), [6]Oat Milk ($0.50), [7]Done\n";
                std::cin >> condimentChoice;

                if(condimentChoice == 7){
                    running = false;

                    break;
                }else if(condimentChoice == 1){
                    drink = new Vanilla(drink);

                }else if(condimentChoice == 2){
                    drink = new Caramel(drink);

                }else if(condimentChoice == 3){
                    drink = new Whip(drink);

                }else if(condimentChoice == 4){
                    drink = new Cinnamon(drink);

                }else if(condimentChoice == 5){
                    drink = new Whole(drink);

                }else if(condimentChoice == 6){
                    drink = new Oat(drink);
                }else{
                    std::cout << "Enter a Valid Choice\n";

                }
            }
            std::cout << "\n\n";
            displayDrink(drink);

        }else if(coffeeChoice == 4){
            Drink* drink = new DarkRoast;
            while(true){
                std::cout << "Condiments: [1]Vanilla ($0.20), [2]Caramel ($0.20), [3]Whip ($0.30), [4]Cinnamon ($0.20), [5]Whole Milk ($0.50), [6]Oat Milk ($0.50), [7]Done\n";
                std::cin >> condimentChoice;

                if(condimentChoice == 7){
                    running = false;
                    break;
                }else if(condimentChoice == 1){
                    drink = new Vanilla(drink);

                }else if(condimentChoice == 2){
                    drink = new Caramel(drink);

                }else if(condimentChoice == 3){
                    drink = new Whip(drink);

                }else if(condimentChoice == 4){
                    drink = new Cinnamon(drink);

                }else if(condimentChoice == 5){
                    drink = new Whole(drink);

                }else if(condimentChoice == 6){
                    drink = new Oat(drink);
                }else{
                    std::cout << "Enter a valid choice.\n";

                }
            }
            std::cout << "\n\n";
            displayDrink(drink);

        }else{
            std::cout << "Enter a Valid Choice\n";
        }
    }
    return 0;
}
