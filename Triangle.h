#include <iostream>
#include <string>

using namespace std;

class Triangle{
public:

	Triangle();
	Triangle(const double, const double, const double);

	double getSideA() const;

	double getSideB() const;
	
	double getSideC() const;

	double area() const;
	
	bool isRight() const;

	bool isEquilateral() const;

	bool isIsosceles() const;

private:

	double SideA, SideB, SideC;

	bool TriangleChecker() const;
};

