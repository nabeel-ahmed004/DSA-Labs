#include "Rectangle.h"
#include<iostream>
using namespace std;

Rectangle::Rectangle(string m_name):Shape_2D(m_name)
{
}

Rectangle::~Rectangle()
{
}

Rectangle::Rectangle(string m_name, double m_length, double m_width):Shape_2D(m_name)
{
    length=m_length;
    width=m_width;
}
void Rectangle::draw()
{
    cout<<"Drawing Rectangle '"<<this->get_name()<<"'"<<endl;
}
void Rectangle::info()
{
    cout<<"I am a Rectangle '"<<this->get_name()<<"' of length : "<<length<<", and width : " <<width<<endl;
    cout<<"I am a 2D Shape"<<endl;
    cout<<"My surface area is : "<<calculate_area()<<" square units"<<endl;
}
double Rectangle::calculate_area()
{
    return length*width;
}
