#pragma once

#define _USE_MATH_DEFINES 

#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <initializer_list>

class Shape {
public:
    virtual double area() const = 0;

    virtual double perimetr() const = 0;

    virtual std::string get_class_name() const = 0;    

    void introduce() const {
        std::cout << "Shape: " << this -> get_class_name() << std::endl
            << "Area: " << this -> area() << std::endl
            << "Perimetr: " << this -> perimetr() << std::endl;
    }

    virtual Shape *clone() const = 0;

    virtual Shape *new_instance_of(double a) const = 0;

    virtual Shape *new_instance_of_vector(std::vector<double> const & a) const = 0;

    virtual Shape *new_instance_of_initializer_list(std::initializer_list<double> a) const = 0;

    virtual ~Shape() = default;
};

class Square : public Shape {
public:
    Square(double side) : a(side) {}

    virtual double area() const override final {
        return a * a;
    }

    virtual double perimetr() const override final {
        return 4 * a;
    }

    virtual std::string get_class_name() const override final {
        return "square";
    }

    virtual Square *clone() const override final {
        return new Square(*this);
    }

    virtual Square *new_instance_of(double a) const override final {
        return new Square{a};
    }

    virtual Square *new_instance_of_vector(std::vector<double> const & a) const override final {
        return new Square{a[0]};
    }

    virtual Square *new_instance_of_initializer_list(std::initializer_list<double> a) const override final {
        return new Square{2};
    }

    virtual ~Square() = default;

private:
    double a;
};

class Circle : public Shape {
public:
    Circle(double radius) : r(radius) {}

    virtual double area() const override final {
        return M_PI  * r * r;
    }

    virtual double perimetr() const override final {
        return 2 * M_PI * r;
    }

    virtual std::string get_class_name() const override final {
        return "circle";
    }

    virtual Circle *clone() const override final {
        return new Circle(*this);
    }

    virtual Circle *new_instance_of(double a) const override final {
        return new Circle{a};
    }

    virtual Circle *new_instance_of_vector(std::vector<double> const & a) const override final {
        return new Circle{a[0]};
    }

    virtual Circle *new_instance_of_initializer_list(std::initializer_list<double> a) const override final {
        return new Circle{1};
    }

    virtual ~Circle() = default;

    private:
    double r;
};

class Triangle : public Shape {
public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}

    virtual double area() const override final {
        double p = this -> perimetr() / 2;

        return std::sqrt(p * (p - a) * (p - b) * (p - c));
    }

    virtual double perimetr() const override final {
        return a + b + c;
    }

    virtual std::string get_class_name() const override final {
        return "triangle";
    }

    virtual Triangle *clone() const override final {
        return new Triangle(*this);
    }

    virtual Triangle *new_instance_of(double a) const override final {
        return new Triangle{a, a, a};
    }

    virtual Triangle *new_instance_of_vector(std::vector<double> const & a) const override final {
        return new Triangle{a[0], a[1], a[2]};
    }

    virtual Triangle *new_instance_of_initializer_list(std::initializer_list<double> a) const override final {
        return new Triangle{*a.begin(), *(a.begin() + 1), *(a.begin() + 2)};
        //return new Triangle{1, 1 , 1};
    }

    virtual ~Triangle() = default;

private:
    double a;
    double b;
    double c;
};
