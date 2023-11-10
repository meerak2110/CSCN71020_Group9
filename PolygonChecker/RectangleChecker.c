#include <stdio.h>
#include <math.h>
#include "main.h"
typedef struct {
    double x;
    double y;
} Point;

double calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int isRectangle(Point lines[4]) {
    // Check if the given lines form a rectangle
    double lengths[4] = { 0.0 };
    for (int i = 0; i < 4; ++i) {
        lengths[i] = calculateDistance(lines[i], lines[(i + 1) % 4]);
    }

    for (int i = 0; i < 4; ++i) {
        if (lengths[i] != lengths[(i + 2) % 4]) {

        return 0;
        }
    }
    return 1;
}

double calculatePerimeter(Point lines[4]) {
    double perimeter = 0.0;
    for (int i = 0; i < 4; ++i) {
        perimeter += calculateDistance(lines[i], lines[(i + 1) % 4]);
    }
    return perimeter;
}

double calculateArea(Point lines[4]) {
    double side1 = calculateDistance(lines[0], lines[1]);
    double side2 = calculateDistance(lines[1], lines[2]);
    return side1 * side2;
}


void connectCorners(Point points[4], Point corners[4]) {
    // Sort points based on x-coordinate
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i - 1; j++) {
            if (points[j].x > points[j + 1].x) {
                // Swap points
                Point temp = points[j];
                points[j] = points[j + 1];
                points[j + 1] = temp;
            }
        }
    }

    // Sort points based on y-coordinate
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i - 1; j++) {
            if (points[j].y > points[j + 1].y) {
                // Swap points
                Point temp = points[j];
                points[j] = points[j + 1];
                points[j + 1] = temp;
            }
        }
    }

    // Now points are sorted based on both x and y coordinates

    // Assign corners based on top-left, top-right, bottom-left, and bottom-right points
    corners[0] = points[0];
    corners[1] = points[1];
    corners[2] = points[3];
    corners[3] = points[2];

    // Connect corners to form the lines
    for (int i = 0; i < 4; ++i) {
        points[i] = corners[i];
    }
    points[3] = corners[0];
}
