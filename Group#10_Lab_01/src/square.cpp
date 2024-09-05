#include "Square.h"
#include<iostream>
using namespace std;

Square::Square(string m_name):Shape_2D(m_name)
{
}

Square::~Square() {}

Square::Square(string m_name, double m_side):Shape_2D(m_name)
{
    side=m_side;
}

void Square::draw()
{
    cout<<"Drawing Square '"<<this->get_name()<<"'"<<endl;
}

void Square::info()
{
    cout<<"I am a Rectangle '"<<this->get_name()<<"' of side : "<<side<<endl;
    cout<<"I am a 2D Shape"<<endl;
    cout<<"My surface area is : "<<calculate_area()<<" square units"<<endl;
}

double Square::calculate_area()
{
    return side*side;
}
