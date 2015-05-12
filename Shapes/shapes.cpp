#include "Shape.h"

const size_t n = 7;

int main() {
    Shape **shapes= new Shape *[n];
    
    shapes[0] = new Square(2); 
    shapes[1] = new Circle(2); 
    shapes[2] = new Triangle(2, 2, 2); 
    shapes[3] = shapes[2] -> new_instance_of(3); 
    shapes[4] = shapes[3] -> clone();
    shapes[5] = shapes[4] -> new_instance_of_vector({2, 3, 4}); 
    shapes[6] = shapes[5] -> new_instance_of_initializer_list({3, 4, 5}); 

    for (std::size_t i = 0; i < n; ++i)
        shapes[i] -> introduce();
    
    for (std::size_t i = 0; i < n; ++i)
        delete shapes[i];

    delete [] shapes;
    return 0;
}
