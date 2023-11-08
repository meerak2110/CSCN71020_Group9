#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include"triangleSolver.h"
#include"main.h"
#include<string.h>
#include <stdlib.h>

//#define M_PI 3.14159265358979323846


char* calculateTriangleAngles(int side1, int side2, int side3, char* triangle) {

    //char* answer = triangle;
    char* angleResult = "";
    if (strcmp(triangle, "The three sides make a valid triangle") == 0) {
        double alpha_rad = acos((side2 * side2 + side3 * side3 - side1 * side1) / (2.0 * side2 * side3));
        double beta_rad = acos((side3 * side3 + side1 * side1 - side2 * side2) / (2.0 * side3 * side1));
        double gamma_rad = acos((side1 * side1 + side2 * side2 - side3 * side3) / (2.0 * side1 * side2));

        double alpha_deg = alpha_rad * 180.0 / M_PI;
        double beta_deg = beta_rad * 180.0 / M_PI;
        double gamma_deg = gamma_rad * 180.0 / M_PI;

        printf("These side lengths form a triangle with angles: %.2lf, %.2lf, %.2lf (degrees)\n", alpha_deg, beta_deg, gamma_deg);
    }
    else if(strcmp(triangle, "The three sides do not make a valid triangle") == 0) {
        printf("The three sides do not make a valid triangle\nCould not form angles from a non-existant triangle.\n");
    }
    else {
        printf("ERROR: strncpy error\n");
    }
    return angleResult;
}