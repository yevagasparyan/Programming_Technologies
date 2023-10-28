#include <iostream>

class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() {
        std::cout << "Draw Circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() {
        std::cout << "Draw Square" << std::endl;
    }
};

class Color {
public:
    virtual void fill() = 0;
};

class Red : public Color {
public:
    void fill() {
        std::cout << "Fill with Red color" << std::endl;
    }
};

class Blue : public Color {
public:
    void fill() {
        std::cout << "Fill with Blue color" << std::endl;
    }
};

class AbstractFactory {
public:
    virtual Shape* createShape() = 0;
    virtual Color* createColor() = 0;
};

class RedCircleFactory : public AbstractFactory {
public:
    Shape* createShape() {
        return new Circle();
    }

    Color* createColor() {
        return new Red();
    }
};

class BlueSquareFactory : public AbstractFactory {
public:
    Shape* createShape() {
        return new Square();
    }

    Color* createColor() {
        return new Blue();
    }
};

int main() {
    AbstractFactory* redCircleFactory = new RedCircleFactory();
    Shape* redCircle = redCircleFactory->createShape();
    Color* redColor = redCircleFactory->createColor();

    redCircle->draw();
    redColor->fill();

    AbstractFactory* blueSquareFactory = new BlueSquareFactory();
    Shape* blueSquare = blueSquareFactory->createShape();
    Color* blueColor = blueSquareFactory->createColor();

    blueSquare->draw();
    blueColor->fill();

    delete redCircle;
    delete redColor;
    delete blueSquare;
    delete blueColor;

    return 0;
}

