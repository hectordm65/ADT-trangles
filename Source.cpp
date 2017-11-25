#include <iostream>
#include <string>

#include "Triangle.h"

using namespace std;
Triangle::Triangle()	//default triangle
{
	SideA = 3.0;
	SideB = 4.0;
	SideC = 5.0;
}

Triangle::Triangle(const double A, const double B, const double C)
{
	SideA = A;		//makes the triangle that is given by the client
	SideB = B;
	SideC = C;

	bool NewTriangle;	//checks for valid triangle

	NewTriangle = TriangleChecker();
	
	if (NewTriangle == false)	//if the sides given are not a triangle this will set the default sides
	{
		SideA = 3.0;
		SideB = 4.0;
		SideC = 5.0;

		cout << "Hey, this isn't a triangle. I'm going to set it to set your triangle to 3, 4, 5.";
	}
	else if (NewTriangle == true)	//if the sides given are a triangle the program will use the sides given
	{
		cout << "I like this triangle." << endl;
	}
}

double Triangle::getSideA() const
{
	return(SideA);	//method to get SideA
}

double Triangle::getSideB() const
{
	return(SideB);	//method to get SideB
}

double Triangle::getSideC() const
{
	return(SideC); //method to get SideC
}

bool Triangle::TriangleChecker() const
{
	double a, b, c = 0;

	a = getSideA();
	b = getSideB();
	c = getSideC();
	//checks for valid triangle
	if ((c >= a + b) || (a >= b + c) || (b >= c + a) || a <= 0 || b <= 0 || c <= 0)
	{	//one side cannot be bigger than the sum of any other 2 triangles nor can any side be equal to or less than 0
		return false;
	}
	else
	{	//if the triangle sides are usable, this will return true
		return true;
	}
}

double Triangle::area() const
{	//this will find the area of the triangle
	double s = 0;

	double Area = 0;

	double A = 0;
	double B = 0;
	double C = 0;

	A = getSideA();
	B = getSideB();
	C = getSideC();

	s = (A + B + C) / 2;
	//this is herons method to find the area of the triangle
	Area = sqrt(s * (s - A) * (s - B) * (s - C));

	return Area;
}

bool Triangle::isRight() const
{
	double A = 0;
	double B = 0;
	double C = 0;

	A = getSideA();
	B = getSideB();
	C = getSideC();
	
	if ((C * C) == (B * B) + (A * A))
	{//if side c squared is equal to side b square plus side a squared it will be defined as a right triangle
		return true;
	}
	else if ((A * A) == (B * B) + (C * C))
	{//if side a squared is equal to side b square plus side c squared it will be defined as a right triangle
		return true;
	}
	else if ((B * B) == (C * C) + (A * A))
	{//if side b squared is equal to side c square plus side a squared it will be defined as a right triangle
		return true;
	}
	else
	{//anything else, the triangle will not be a right triangle
		return false;
	}
	
}

bool Triangle::isEquilateral() const
{
	double A = 0;
	double B = 0;
	double C = 0;

	A = getSideA();
	B = getSideB();
	C = getSideC();

	if (A == B && B == C)
	{//if all the sides are equal to each other the triangle will be defined as an equilateral triangle
		return true;
	}
	else
	{//anything else the triangle will not be an equilateral triangle
		return false;
	}
}

bool Triangle::isIsosceles() const
{
	double A = 0;
	double B = 0;
	double C = 0;

	A = getSideA();
	B = getSideB();
	C = getSideC();
	//if the triangle has 2 sides that equal each other and the remaining side is not equal to the other
	//2 sides this will be defined as an isosceles triangle
	if (A == B && A != C)
	{
		return true;
	}
	else if (B == C && A != C)
	{
		return true;
	}
	else if (C == A && B != C)
	{
		return true;
	}
	else
	{//anything else will not be defined as an isosceles triangle
		return false;
	}
}