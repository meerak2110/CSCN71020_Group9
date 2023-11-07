#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"

char* isTriangle(int side1, int side2, int side3) {
	char* triangle = "";
	if (side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2) {
		triangle = "The three side make a valid triangel\n";

	}
	else {
		triangle = "The tree side do not make a valid triangle\n";
	}
	return triangle;
} 



char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}