#ifndef SHAPE_H
#define SHAPE_H

#include<string>
using namespace std;

class Shape
{
    public:
        //default constructor
        Shape();
        //parametrized constructor
        Shape(string m_name);
        //destructor
        virtual ~Shape();
        //remaining methods
        virtual void draw() = 0;
        virtual void info() = 0;
        string get_name();

    protected:

    private:
        string name;
};

#endif // SHAPE_H
