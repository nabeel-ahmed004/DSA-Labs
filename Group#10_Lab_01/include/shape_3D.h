#ifndef SHAPE_3D_H
#define SHAPE_3D_H

#include <Shape.h>

#include<string>
using namespace std;

class Shape_3D : public Shape
{
    public:
        Shape_3D(string m_name);
        //destructor
        virtual ~Shape_3D();
        //remaining methods
        virtual double calculate_volume() = 0;
        virtual void info();

    protected:

    private:

};

#endif // SHAPE_3D_H
