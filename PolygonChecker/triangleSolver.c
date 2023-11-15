#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "triangleSolver.h"

//this function validates weather the inputs for the sides make up a triangle
//if they do, its will state what type of triangle it is.
char* isTriangle(int side1, int side2, int side3) {
	char* triangle = "";
	if (side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2) {
		triangle = "The three sides make a valid triangle";

		char* analyzeTriangle(int side1, int side2, int side3); {
			char* result = "";
			if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
				result = "Not a triangle";
			}
			else if (side1 == side2 && side1 == side3) {
				printf("The three sides make a valid triangle\nType: Equilateral triangle\n");
			}
			else if ((side1 == side2 && side1 != side3) ||
				(side1 == side3 && side1 != side2) || (side2 == side3 && side2 != side1))
			{
				printf("The three sides make a valid triangle\nType: Isosceles triangle\n");
			}
			else {
				printf("The three sides make a valid triangle\nType: Scalene triangle\n");
			}
			
		}
	}
	else {
		triangle = "The three sides do not make a valid triangle";
	}
	return triangle;
}
//this function is not getting called in the main.c
//it is extracted from the function above to help with the testing
char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Type: Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) ||
		(side1 == side3 && side1 != side2) ||
		(side2 == side3 && side2 != side1))
	{
		result = "Type: Isosceles triangle";
	}
	else {
		result = "Type: Scalene triangle";
	}
	return result;
}