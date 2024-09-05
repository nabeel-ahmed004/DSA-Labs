#ifndef CUBE_H
#define CUBE_H

#include <Shape_3D.h>


class Cube : public Shape_3D
{
    public:
        //parametrized constructor
        Cube(string m_name);
        Cube(string m_name, double m_side);
        //destructor
        virtual ~Cube();
        //remaining methods
        virtual void draw();
        virtual void info();
        virtual double calculate_volume();

    protected:

    private:
        double side;
};

#endif // CUBE_H
