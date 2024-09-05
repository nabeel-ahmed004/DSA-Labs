#include "Shape.h"
#include<iostream>

using namespace std;

Shape::Shape(string m_name)
{
    name=m_name;
}

string Shape::get_name()
{
    return name;
}

Shape::~Shape()
{
    //dtor;
}
