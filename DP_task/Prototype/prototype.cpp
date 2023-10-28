#include <iostream>
#include <vector>

class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void print() const = 0;
};

class ConcretePrototype : public Prototype {
public:
    ConcretePrototype(int data, std::string name) : data(data), name(name) {}

    ConcretePrototype(const ConcretePrototype& other) : data(other.data), name(other.name) {}

    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    void print() const override {
        std::cout << "Data: " << data << ", Name: " << name << std::endl;
    }

private:
    int data;
    std::string name;
};

class PrototypeManager {
public:
    void registerPrototype(Prototype* prototype) {
        prototypes.push_back(prototype);
    }

    Prototype* createPrototype(int index) {
        if (index >= 0 && index < prototypes.size()) {
            return prototypes[index]->clone();
        }
        return nullptr;
    }

    void cleanupPrototypes() {
        for (Prototype* prototype : prototypes) {
            delete prototype;
        }
        prototypes.clear();
    }

private:
    std::vector<Prototype*> prototypes;
};

int main() {
    PrototypeManager manager;

    manager.registerPrototype(new ConcretePrototype(42, "Prototype 1"));
    manager.registerPrototype(new ConcretePrototype(17, "Prototype 2"));

    Prototype* clone1 = manager.createPrototype(0);
    Prototype* clone2 = manager.createPrototype(1);

    if (clone1 && clone2) {
        clone1->print();
        clone2->print();

        delete clone1;
        delete clone2;
    }

    manager.cleanupPrototypes();

    return 0;
}

