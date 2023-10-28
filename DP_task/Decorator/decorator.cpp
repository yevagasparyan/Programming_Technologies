#include <iostream>

class Coffee {
public:
    virtual int cost() const = 0;
};

class SimpleCoffee : public Coffee {
public:
    int cost() const override {
        return 5;
    }
};

class CoffeeDecorator : public Coffee {
public:
    CoffeeDecorator(Coffee* coffee) : coffee_(coffee) {}

    int cost() const override {
        return coffee_->cost();
    }

private:
    Coffee* coffee_;
};

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    int cost() const override {
        return CoffeeDecorator::cost() + 2;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    int cost() const override {
        return CoffeeDecorator::cost() + 1;
    }
};

int main() {
    Coffee* coffee = new SimpleCoffee();
    std::cout << "Cost of simple coffee: $" << coffee->cost() << std::endl;

    Coffee* coffeeWithMilk = new MilkDecorator(coffee);
    std::cout << "Cost of coffee with milk: $" << coffeeWithMilk->cost() << std::endl;

    Coffee* coffeeWithMilkAndSugar = new SugarDecorator(coffeeWithMilk);
    std::cout << "Cost of coffee with milk and sugar: $" << coffeeWithMilkAndSugar->cost() << std::endl;

    delete coffee;
    delete coffeeWithMilk;
    delete coffeeWithMilkAndSugar;

    return 0;
}

