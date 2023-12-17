#include <iostream>

class Context;

class State {
public:
    virtual void handle(Context& context) = 0;
};

class ConcreteStateA : public State {
public:
    void handle(Context& context) override;
};

class ConcreteStateB : public State {
public:
    void handle(Context& context) override;
};

class Context {
private:
    State* currentState;

public:
    Context() : currentState(nullptr) {}

    void setState(State* state) {
        currentState = state;
    }

    void request() {
        if (currentState) {
            currentState->handle(*this);
        } else {
            std::cout << "No state set." << std::endl;
        }
    }
};

void ConcreteStateA::handle(Context& context) {
    std::cout << "ConcreteStateA handling request. Transitioning to ConcreteStateB." << std::endl;
    context.setState(new ConcreteStateB());
    delete this;
}

void ConcreteStateB::handle(Context& context) {
    std::cout << "ConcreteStateB handling request. Transitioning back to ConcreteStateA." << std::endl;
    context.setState(new ConcreteStateA());
    delete this;
}

int main() {
    Context context;

    context.setState(new ConcreteStateA());
    context.request();

    context.request();

    return 0;
}

