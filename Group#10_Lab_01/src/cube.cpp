#include "Cube.h"
#include<iostream>
using namespace std;

Cube::Cube(string m_name):Shape_3D(m_name)
{
}

Cube::Cube(string m_name, double m_side):Shape_3D(m_name)
{
    side=m_side;
}

Cube::~Cube()
{
}

void Cube::draw()
{
    cout<<"Drawing Cube '"<<this->get_name()<<"'"<<endl;
}
void Cube::info()
{
    cout<<"I am a Cube'"<<this->get_name()<<"' of side : "<<side<<endl;
    cout<<"I am a 3D Shape"<<endl;
    cout<<"My volume is : "<<calculate_volume()<<" cubic units"<<endl;
}
double Cube::calculate_volume()
{
    return side*side*side;
}
