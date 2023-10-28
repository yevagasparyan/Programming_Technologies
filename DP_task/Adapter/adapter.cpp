#include <iostream>

// Legacy Rectangle with a different interface
class LegacyRectangle {
public:
    int getArea() {
        return width * height;
    }

    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }

private:
    int width;
    int height;
};

// Modern Rectangle interface
class ModernRectangle {
public:
    virtual int calculateArea() = 0;
};

// Adapter class to make ModernRectangle work with LegacyRectangle interface
class RectangleAdapter : public ModernRectangle {
public:
    RectangleAdapter(int width, int height) {
        legacyRect.setWidth(width);
        legacyRect.setHeight(height);
    }

    int calculateArea() override {
        return legacyRect.getArea();
    }

private:
    LegacyRectangle legacyRect;
};

int main() {
    LegacyRectangle legacyRect;
    legacyRect.setWidth(5);
    legacyRect.setHeight(10);

    std::cout << "Legacy Rectangle Area: " << legacyRect.getArea() << std::endl;

    ModernRectangle* modernRect = new RectangleAdapter(3, 7);

    std::cout << "Modern Rectangle Area: " << modernRect->calculateArea() << std::endl;

    delete modernRect;

    return 0;
}

