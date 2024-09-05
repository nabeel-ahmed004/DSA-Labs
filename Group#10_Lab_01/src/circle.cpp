#include "Circle.h"
#include<iostream>
using namespace std;

Circle::Circle(string m_name):Shape_2D(m_name)
{
}

Circle::Circle(string m_name, double m_radius):Shape_2D(m_name)
{
    radius=m_radius;
}

void Circle::draw()
{
    cout<<"Drawing Circle '"<<this->get_name()<<"'"<<endl;
}
void Circle::info()
{
    cout<<"I am a Circle '"<<this->get_name()<<"' of radius : "<<radius<<endl;
    cout<<"I am 2D Shape"<<endl;
    cout<<"My surface area is : "<<calculate_area()<<" square units"<<endl;
}

double Circle::calculate_area()
{
    return 3.14*radius*radius;
}
