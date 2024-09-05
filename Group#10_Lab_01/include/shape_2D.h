#ifndef SHAPE_2D_H
#define SHAPE_2D_H

#include <Shape.h>

#include<string>
using namespace std;

class Shape_2D : public Shape
{
    public:
        //parametrized constructor
        Shape_2D(string m_name);
        //destructor
        virtual ~Shape_2D();
        //remaining methods
        virtual double calculate_area() = 0;
        virtual void info();

    protected:

    private:
};

#endif // SHAPE_2D_H
