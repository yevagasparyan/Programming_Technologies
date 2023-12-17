#include <iostream>
#include <vector>

class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class Light {
public:
    void turnOn() {
        std::cout << "Light is ON" << std::endl;
    }

    void turnOff() {
        std::cout << "Light is OFF" << std::endl;
    }
};

class TurnOnCommand : public Command {
private:
    Light* light;

public:
    TurnOnCommand(Light* l) : light(l) {}

    void execute() override {
        light->turnOn();
    }

    void undo() override {
        light->turnOff();
    }
};

class TurnOffCommand : public Command {
private:
    Light* light;

public:
    TurnOffCommand(Light* l) : light(l) {}

    void execute() override {
        light->turnOff();
    }

    void undo() override {
        light->turnOn();
    }
};

class RemoteControl {
private:
    Command* command;

public:
    void setCommand(Command* cmd) {
        command = cmd;
    }

    void pressButton() {
        command->execute();
    }

    void pressUndoButton() {
        command->undo();
    }
};

int main() {
    Light light;
    TurnOnCommand turnOn(&light);
    TurnOffCommand turnOff(&light);

    RemoteControl remote;

    remote.setCommand(&turnOn);
    remote.pressButton();

    remote.setCommand(&turnOff);
    remote.pressButton();

    remote.pressUndoButton();

    return 0;
}

