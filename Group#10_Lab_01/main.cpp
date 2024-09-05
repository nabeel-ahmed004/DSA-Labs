#include <iostream>

#include<Shape.h>
#include<Circle.h>
#include<Rectangle.h>
#include<Square.h>
#include<Cube.h>
#include<Sphere.h>

using namespace std;

int main()
{
    const int Shapes_count = 10;
    Shape *Shapes[Shapes_count];
    Shapes[0] = new Circle("Circle 1", 5.0);
    Shapes[1] = new Square("Square 1", 4.0);
    Shapes[2] = new Rectangle("Rectangle 1", 6.0, 4.0);
    Shapes[3] = new Sphere("Sphere 1", 3.0);
    Shapes[4] = new Cube("Cube 1", 2.0);
    Shapes[5] = new Circle("Circle 2", 6.0);
    Shapes[6] = new Square("Square 2", 5.0);
    Shapes[7] = new Rectangle("Rectangle 2", 7.0, 5.0);
    Shapes[8] = new Sphere("Sphere 2", 4.0);
    Shapes[9] = new Cube("Cube 2", 3.0);

    cout<<"Drawing the Shapes"<<endl;
    for(int i=0; i<Shapes_count; i++)
        Shapes[i]->draw();
    cout<<endl;

    cout<<"Getting Shapes Info"<<endl;
    for(int i=0; i<Shapes_count; i++)
    {
        Shapes[i]->info();
        cout<<endl;
    }

    return 0;
}
