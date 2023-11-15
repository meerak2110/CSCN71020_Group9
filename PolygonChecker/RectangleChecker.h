#pragma once
typedef struct {
    double x;
    double y;
} Point;

double calculateDistance(Point p1, Point p2);
int isRectangle(Point lines[4]);
double calculatePerimeter(Point lines[4]);
double calculateArea(Point lines[4]);
void connectCorners(Point corners[4], Point lines[4]);