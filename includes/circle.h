#ifndef CIRCLE_H
#define CIRCLE_H
#include <math.h>
class Circle
{
public:
//Constructor
    Circle(double x = 0.0, double y = 0.0, double radius = 1.0);
//destructor
    ~Circle(){}

//member functions
    void radius(double radius);
    void coordinates(double x, double y);
    void assign(double x, double y, double radius);
//static functions
    static double center_distance(Circle& cir1, Circle& cir2)
    {
        return sqrt(pow(cir1.m_x - cir2.m_x, 2) + pow(cir1.m_y - cir2.m_y, 2));
    }

    static bool is_in_contact(Circle& cir1, Circle& cir2)
    {
        return Circle::center_distance(cir1, cir2) <= cir1.m_radius + cir2.m_radius;
    }
private:
    static int s_id;
    double m_x{};
    double m_y{};
    double m_radius{};
};
int Circle::s_id{0};
#endif