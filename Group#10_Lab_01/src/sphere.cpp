#include "Sphere.h"
#include<iostream>
using namespace std;

Sphere::Sphere(string m_name):Shape_3D(m_name)
{
}

Sphere::Sphere(string m_name, float m_radius):Shape_3D(m_name)
{
    radius=m_radius;
}

Sphere::~Sphere()
{
}

void Sphere::draw()
{
    cout<<"Drawing Sphere '"<<this->get_name()<<"'"<<endl;
}
void Sphere::info()
{
    cout<<"I am a Sphere '"<<this->get_name()<<"' of radius : "<<radius<<endl;
    cout<<"I am a 3D Shape"<<endl;
    cout<<"My volume is : "<<calculate_volume()<<" cubic units"<<endl;
}
double Sphere::calculate_volume()
{
    return 1.3333333*3.14*radius*radius*radius;
}
