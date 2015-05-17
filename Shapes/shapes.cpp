#include "Shape.h"
#include <vector>
#include <memory>

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    
    shapes.emplace_back(std::unique_ptr<Shape>(new Square(2))); 
    shapes.emplace_back(std::unique_ptr<Shape>(new Circle(2))); 
    shapes.emplace_back(std::unique_ptr<Shape>(new Triangle(2, 2, 2))); 
    shapes.emplace_back(std::unique_ptr<Shape>(shapes[2] -> new_instance_of(3))); 
    shapes.emplace_back(std::unique_ptr<Shape>(shapes[3] -> clone()));
    shapes.emplace_back(std::unique_ptr<Shape>(shapes[4] -> new_instance_of_vector({2, 3, 4}))); 
    shapes.emplace_back(std::unique_ptr<Shape>(shapes[5] -> new_instance_of_initializer_list({3, 4, 5}))); 

    std::size_t n = shapes.size();
    for (std::size_t i = 0; i < n; ++i)
        shapes[i] -> introduce();
    
    return 0;
}
