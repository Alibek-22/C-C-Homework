#include <iostream>
#include "point.hpp"
using std::cout, std::endl;

class Circle
{
private:
    Point center;
    float radius;

public:
    Circle(const Point& center, float radius) : center(center), radius(radius) 
    {
        if (radius < 0) {
            this->radius = 0;
        }
    }

    Circle() : center(Point(0, 0)), radius(1) {}

    Circle(const Circle& circle) : center(circle.center), radius(circle.radius) {}

    Point getCenter() const { return center; }
    float getRadius() const { return radius; }

    void setCenter(const Point& newCenter) { center = newCenter; }
    void setRadius(float newRadius) 
    { 
        radius = (newRadius < 0) ? 0 : newRadius;
    }

    float area() const 
    {
        return 3.1415926535f * radius * radius;
    }

    float distance(const Point& p) const 
    {
        float dx = p.x - center.x;
        float dy = p.y - center.y;
        float distToCenter = std::sqrt(dx * dx + dy * dy);
        
        float result = distToCenter - radius;
        return (result < 0) ? -result : result;
    }

    bool isColliding(const Circle& c) const 
    {
        float dx = center.x - c.center.x;
        float dy = center.y - c.center.y;
        float distSquared = dx * dx + dy * dy;
        float sumRadii = radius + c.radius;
        
        return distSquared <= sumRadii * sumRadii;
    }

    void move(const Point& p) 
    {
        center = center + p;  
    }
};

int main()
{
    Point p = {7, -1};
    Point q = {-4, 2};
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "p + q = " << p + q << endl;

    Circle a({4, 1}, 3);
    Circle b;

    cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << endl; 
    cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << endl;

    cout << "Area of a = " << a.area() << endl;
    cout << "Distance from point p to circle a = " << a.distance(p) << endl;

    cout << "Collisions:" << endl;
    if (a.isColliding(b))
        cout << "Yes, a is colliding b" << endl;
    else
        cout << "No, a isn't colliding b" << endl;

    cout << "Moving b by {1, 1}:" << endl;
    b.move({1, 1});
    if (a.isColliding(b))
        cout << "Yes, a is colliding b" << endl;
    else
        cout << "No, a isn't colliding b" << endl;
}
