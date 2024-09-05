#ifndef CIRCLE_H
#define CIRCLE_H

#include <Shape_2D.h>


class Circle : public Shape_2D
{
    public:
        //parametrized constructor
        Circle(string m_name);
        Circle(string m_name, double m_radius);
        //remaining methods
        virtual void draw();
        virtual void info();
        virtual double calculate_area();

    protected:

    private:
        double radius;
};

#endif // CIRCLE_H
