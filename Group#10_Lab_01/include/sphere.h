#ifndef SPHERE_H
#define SPHERE_H

#include <Shape_3D.h>


class Sphere : public Shape_3D
{
    public:
        //parametrized constructor
        Sphere(string m_name);
        Sphere(string m_name, float m_radius);
        //destructor
        virtual ~Sphere();
        //remaining methods
        virtual void draw();
        virtual void info();
        virtual double calculate_volume();

    protected:

    private:
        double radius;
};

#endif // SPHERE_H
