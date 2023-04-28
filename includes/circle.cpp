#include "circle.h"
#include <iostream>
#include <math.h>

//Constructor
    Circle::Circle(double x, double y, double radius) : m_x{x}, m_y{y}, 
    m_radius{radius}
    {
        ++s_id;
        std::cout << "Circle has been created\n";
    }
//destructor
    Circle::~Circle(){std::cout << "Circle has been destroyed\n";}

//member functions
    void Circle::radius(double radius)
    {
        if(radius <= 0)
        {
            std::cout << "Radius of circle #" << s_id << " is not valid\n";
        }
        else
        {
            m_radius = radius;
        }
    }
    void Circle::coordinates(double x, double y)
    {
        m_x = x;
        m_y = y;
    }
    void Circle::assign(double x, double y, double radius)
    {
        if(radius <= 0)
        {
            std::cout << "Radius of circle #" << s_id << " is not valid\n";
        }
        else
        {
            m_radius = radius;
        }        
        coordinates(x,y);
    }
int Circle::s_id{0};
