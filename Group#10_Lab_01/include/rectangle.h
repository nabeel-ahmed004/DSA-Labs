#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <Shape_2D.h>


class Rectangle : public Shape_2D
{
    public:
        //parametrized constructor
        Rectangle(string m_name);
        Rectangle(string m_name, double m_length, double m_width);
        //destructor
        virtual ~Rectangle();
        //remaining methods
        virtual void draw();
        virtual void info();
        virtual double calculate_area();

    protected:

    private:
        double length, width;
};

#endif // RECTANGLE_H
