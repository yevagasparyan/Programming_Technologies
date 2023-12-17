#include <iostream>
#include <string>

class Handler {
public:
    virtual void handleRequest(const std::string& request) = 0;
    virtual void setNextHandler(Handler* nextHandler) = 0;
};

class ConcreteHandler1 : public Handler {
private:
    Handler* nextHandler;

public:
    void handleRequest(const std::string& request) override {
        if (request == "Handler1") {
            std::cout << "ConcreteHandler1 handling the request." << std::endl;
        } else if (nextHandler != nullptr) {
            std::cout << "ConcreteHandler1 passing the request to the next handler." << std::endl;
            nextHandler->handleRequest(request);
        } else {
            std::cout << "ConcreteHandler1 cannot handle the request." << std::endl;
        }
    }

    void setNextHandler(Handler* handler) override {
        nextHandler = handler;
    }
};

class ConcreteHandler2 : public Handler {
private:
    Handler* nextHandler;

public:
    void handleRequest(const std::string& request) override {
        if (request == "Handler2") {
            std::cout << "ConcreteHandler2 handling the request." << std::endl;
        } else if (nextHandler != nullptr) {
            std::cout << "ConcreteHandler2 passing the request to the next handler." << std::endl;
            nextHandler->handleRequest(request);
        } else {
            std::cout << "ConcreteHandler2 cannot handle the request." << std::endl;
        }
    }

    void setNextHandler(Handler* handler) override {
        nextHandler = handler;
    }
};

int main() {
    ConcreteHandler1 handler1;
    ConcreteHandler2 handler2;

    handler1.setNextHandler(&handler2);

    handler1.handleRequest("Handler1");
    handler1.handleRequest("Handler2");
    handler1.handleRequest("Handler3");

    return 0;
}

