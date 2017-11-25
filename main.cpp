// CSC 2430 Triangle Lab
// Written by: Hector Dominguez-Maceda
// Example main() test program OUTLINE - customize to complete lab requirements
#include <iostream>
#include <string>
using namespace std;

#include "Triangle.h"

//                                      const parameter by reference
void printTriangleDetails(string label, const Triangle &tri) {
	cout << label << " triangle: [";
	cout << tri.getSideA() << ", "
		 << tri.getSideB() << ", "
		 << tri.getSideC() << "]" << endl;
	cout << "The area of your Triangle is " << tri.area() << endl;
	
	if (tri.isRight())
		cout << "  Triangle is a right triangle" << endl;
	else
		cout << "  Triangle is not a right triangle" << endl;

	if (tri.isEquilateral())
		cout << "  Triangle is a equilateral triangle" << endl;
	else
		cout << "  Triangle is not a equilateral triangle" << endl;

	if (tri.isIsosceles())
		cout << "  Triangle is a isoceles triangle" << endl;
	else
		cout << "  Triangle is not a isoceles triangle" << endl;

	cout << endl;
}

int main() {
	system("cls");

	cout << "CSC2430 Triangle Lab: Written by Hector Dominguez-Maceda\n" << endl;
	Triangle t1;			// Default triangle
	printTriangleDetails("Default", t1);

	Triangle t2(5, 4, 3);		// convert constructor
	printTriangleDetails("t2(5, 4, 3)", t2);

	Triangle t3(4, 5, 3);
	printTriangleDetails("t3(4, 5, 3)", t3);

	Triangle t4(4, 6, 4);
	printTriangleDetails("t4(4, 6, 4)", t4);

	Triangle t5(2, 4, 2); 		// Invalid side combination
	printTriangleDetails("t5(2, 4, 2)", t5);

	t5 = t4; 				// Assignment of triangle objects
	printTriangleDetails("Assigned t5=t4", t5);

	t5 = Triangle(3, 3, 3); 	// Create a Triangle object "on the fly"
	printTriangleDetails("On-The-Fly assigned Triangle(3, 3, 3)", t5);

	t5 = Triangle(t5.getSideA(), 4, t5.getSideC());	// change 2nd side of t5
	printTriangleDetails("Changed sideB", t5);

	// etc, etc, etc
	// Code up several additional "test" examples that
	//    illustrate the correct operation of the Triangle object.

	return(0);
}
