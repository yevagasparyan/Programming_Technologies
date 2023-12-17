#include <iostream>
#include <vector>
#include <algorithm>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

class ConcreteObserver : public Observer {
private:
    std::string name;

public:
    ConcreteObserver(const std::string& n) : name(n) {}

    void update(const std::string& message) override {
        std::cout << "Observer " << name << " received message: " << message << std::endl;
    }
};

class Subject {
public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers(const std::string& message) = 0;
};

class ConcreteSubject : public Subject {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers(const std::string& message) override {
        for (Observer* observer : observers) {
            observer->update(message);
        }
    }
};

int main() {
    ConcreteSubject subject;

    ConcreteObserver observer1("Observer1");
    ConcreteObserver observer2("Observer2");
    ConcreteObserver observer3("Observer3");

    subject.addObserver(&observer1);
    subject.addObserver(&observer2);
    subject.addObserver(&observer3);

    subject.notifyObservers("Hello observers!");

    subject.removeObserver(&observer2);

    subject.notifyObservers("Observers updated!");

    return 0;
}

