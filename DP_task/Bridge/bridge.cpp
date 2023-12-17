#include <iostream>

class DrawingAPI {
public:
    virtual void drawCircle(double x, double y, double radius) = 0;
};

class Shape {
protected:
    DrawingAPI* drawingAPI;

public:
    Shape(DrawingAPI* api) : drawingAPI(api) {}

    virtual void draw() = 0;
    virtual void resizeByPercentage(double percentage) = 0;
};

class DrawingAPI1 : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) override {
        std::cout << "API1 Drawing Circle at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }
};

class DrawingAPI2 : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) override {
        std::cout << "API2 Drawing Circle at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }
};

class Circle : public Shape {
private:
    double x, y, radius;

public:
    Circle(double x, double y, double radius, DrawingAPI* api)
        : Shape(api), x(x), y(y), radius(radius) {}

    void draw() override {
        drawingAPI->drawCircle(x, y, radius);
    }

    void resizeByPercentage(double percentage) override {
        radius *= (1.0 + percentage / 100.0);
    }
};

int main() {
    DrawingAPI1 api1;
    DrawingAPI2 api2;

    Circle circle1(1, 2, 3, &api1);
    Circle circle2(5, 7, 11, &api2);

    circle1.draw();
    circle2.draw();

    circle1.resizeByPercentage(10);
    circle2.resizeByPercentage(20);

    circle1.draw();
    circle2.draw();

    return 0;
}

