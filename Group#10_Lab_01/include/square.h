#ifndef SQUARE_H
#define SQUARE_H

#include <Shape_2D.h>


class Square : public Shape_2D
{
    public:
        //parametrized constructor
        Square(string m_name);
        Square(string m_name, double m_side);
        //destructor
        virtual ~Square();
        //remaining methods
        virtual void draw();
        virtual void info();
        virtual double calculate_area();

    protected:

    private:
        double side;
};

#endif // SQUARE_H
