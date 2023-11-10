#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#include "triangleSolver.h"

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
				(side1 == side3 && side1 != side2))
			{
				printf("The three sides make a valid triangle\nType: Isosceles triangle\n");
			}
			else {
				printf("The three sides make a valid triangle\nType: Scalene triangle\n");
			}
			//return result;
		}
	}
	else /*if(side1 + side2 < side3 && side2 + side3 < side1 && side1 + side3 < side2)*/{
		triangle = "The three sides do not make a valid triangle";
	}
	//else {
	//	triangle = "The three sides do not make a valid triangle";

	//}
	return triangle;
}
