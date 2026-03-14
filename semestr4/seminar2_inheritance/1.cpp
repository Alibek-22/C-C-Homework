#include <iostream>
#include <cmath>
#include <numbers> // для std::numbers::pi



struct Vector2f
{
    float x, y;
};

Vector2f operator+(Vector2f left, Vector2f right)
{
    Vector2f result = {left.x + right.x, left.y + right.y};
    return result;
}

Vector2f operator*(Vector2f left, float right)
{
    Vector2f result = {left.x * right, left.y * right};
    return result;
}

Vector2f operator*(float left, Vector2f right)
{
    Vector2f result = {left * right.x, left * right.y};
    return result;
}

Vector2f& operator+=(Vector2f& left, Vector2f right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}

float getDistance(Vector2f a, Vector2f b)
{
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

std::ostream& operator<<(std::ostream& out, Vector2f right)
{
    out << "(" << right.x << ", " << right.y << ")";
    return out;
}

// Базовый класс Shape, содержащий общие для всех фигур поля и методы
class Shape
{
private:
    Vector2f mPosition;

public:
    Shape() : mPosition({0, 0}) {}
    
    Vector2f getPosition() const
    {
        return mPosition;
    }
    
    void setPosition(Vector2f newPosition)
    {
        mPosition = newPosition;
    }
    
    void move(Vector2f change)
    {
        mPosition = mPosition + change;
    }
};

// Класс Circle, наследующий от Shape
class Circle : public Shape
{
private:
    float mRadius;

public:
    Circle(float radius) : mRadius(radius)
    {
    }
    
    float calculatePerimeter()
    {
        return 2 * std::numbers::pi * mRadius;
    }
};

// Класс Rectangle, наследующий от Shape
class Rectangle : public Shape
{
private:
    float mWidth;
    float mHeight;

public:
    Rectangle(float width, float height) : mWidth(width), mHeight(height)
    {
    }
    
    float calculatePerimeter()
    {
        return 2 * (mWidth + mHeight);
    }
};

// Класс Triangle, наследующий от Shape
class Triangle : public Shape
{
private:
    Vector2f mPointA;
    Vector2f mPointB;
    Vector2f mPointC;

public:
    Triangle(Vector2f pointA, Vector2f pointB, Vector2f pointC) 
        : mPointA(pointA), mPointB(pointB), mPointC(pointC)
    {
    }
    
    float calculatePerimeter()
    {
        return getDistance(mPointA, mPointB) + getDistance(mPointB, mPointC) + getDistance(mPointC, mPointA);
    }
};

int main()
{
    // Создаем объекты фигур
    Circle circle(10.0f);
    Rectangle rectangle(100.0f, 200.0f);
    Triangle triangle({5.0f, 2.0f}, {-7.0f, 5.0f}, {4.0f, 4.0f});
    
    // Выводим периметры фигур
    std::cout << "Circle perimeter: " << circle.calculatePerimeter() << std::endl;
    std::cout << "Rectangle perimeter: " << rectangle.calculatePerimeter() << std::endl;
    std::cout << "Triangle perimeter: " << triangle.calculatePerimeter() << std::endl;
    
    // Выводим начальные позиции
    std::cout << "\nInitial positions:" << std::endl;
    std::cout << "Circle position: " << circle.getPosition() << std::endl;
    std::cout << "Rectangle position: " << rectangle.getPosition() << std::endl;
    std::cout << "Triangle position: " << triangle.getPosition() << std::endl;
    
    // Тестируем метод move
    std::cout << "\nMoving shapes:" << std::endl;
    circle.move({10.0f, 20.0f});
    rectangle.move({-5.0f, 5.0f});
    triangle.move({3.0f, -2.0f});
    
    // Выводим новые позиции
    std::cout << "New circle position: " << circle.getPosition() << std::endl;
    std::cout << "New rectangle position: " << rectangle.getPosition() << std::endl;
    std::cout << "New triangle position: " << triangle.getPosition() << std::endl;
    
    return 0;
}
