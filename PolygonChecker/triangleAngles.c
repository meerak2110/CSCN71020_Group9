#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>
#include"triangleSolver.h"
#include"main.h"
#include<string.h>
#include <stdlib.h>


//this function calculates the angles in the triangle only if the inputs make a valid triangle
char* calculateTriangleAngles(int side1, int side2, int side3, char* triangle) {
    char* result = (char*)malloc(256);
    if (strcmp(triangle, "The three sides make a valid triangle") == 0) {
        double alpha_rad = acos((side2 * side2 + side3 * side3 - side1 * side1) / (2.0 * side2 * side3));
        double beta_rad = acos((side3 * side3 + side1 * side1 - side2 * side2) / (2.0 * side3 * side1));
        double gamma_rad = acos((side1 * side1 + side2 * side2 - side3 * side3) / (2.0 * side1 * side2));

        double alpha_deg = alpha_rad * 180.0 / M_PI;
        double beta_deg = beta_rad * 180.0 / M_PI;
        double gamma_deg = gamma_rad * 180.0 / M_PI;

        sprintf(result, "These side lengths form a triangle with angles: %.2lf, %.2lf, %.2lf (degrees)", alpha_deg, beta_deg, gamma_deg);
    }
    else {
        sprintf(result, "The three sides do not make a valid triangle\nCould not form angles from a non-existent triangle.");
    }

    return result;
}

