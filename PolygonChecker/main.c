#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include"RectangleChecker.h"
#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();
		Point points[4];

		switch (shapeChoice)
		{
//for rectangle
		case 2:
			printf("Enter the coordinates of four points to check if they form a rectangle.\n");
			
			for (int i = 0; i < 4; ++i) {
				printf("Enter x-coordinate for point %d: ", i + 1);
				scanf_s("%lf", &points[i].x);

				printf("Enter y-coordinate for point %d: ", i + 1);
				scanf_s("%lf", &points[i].y);
			}
			
			Point corners[4];

			// Input points from the user or elsewhere

			// Call the connectCorners function to determine corners
			connectCorners(points, corners);

			// Use the corners array to check for rectangle properties or perform other operations
			if (isRectangle(corners)) {
				printf("The given points form a rectangle.\n");
				 
				double distance = calculateDistance(corners[0],corners[1]);
				printf("Distance: %.2f units\n", distance);
				// Calculate and print perimeter
				double perimeter = calculatePerimeter(corners);
				printf("Perimeter: %.2f units\n", perimeter);

				// Calculate and print area
				double area = calculateArea(corners);
				printf("Area: %.2f units^2\n", area);
			}
			else {
				printf("The given points do not form a rectangle.\n");
			}
			break;

			//for triangle
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			char* triangle = isTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			
			char* angleResult = calculateTriangleAngles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], triangle);
			printf_s("\n%s\n", angleResult);
			break;

			//to exit the program
		case 0:
			printf("________________\n");
			printf("|Exiting Program|");
			printf("\n----------------");


			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome(){
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("2. Rectangle\n");
	printf_s("1. Triangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}


