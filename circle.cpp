class Circle
{
public:
//Constructor
    Circle(double x = 0.0, double y = 0.0, double radius = 1.0) : m_x{x}, m_y{y}, 
    m_radius{radius}
    {
        ++s_id;
        std::cout << "Circle has been created\n";
    }
//destructor
    ~Circle(){std::cout << "Circle has been destroyed\n";}

//member functions
    void radius(double radius)
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
    void coordinates(double x, double y)
    {
        m_x = x;
        m_y = y;
    }
    void assign(double x, double y, double radius)
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
