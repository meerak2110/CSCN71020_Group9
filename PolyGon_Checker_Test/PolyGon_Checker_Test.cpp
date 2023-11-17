#include "pch.h"
#include "CppUnitTest.h"
typedef struct {
	double p1;
	double p2;
} Point;
extern "C" double calculateDistance(Point p1, Point p2);
extern "C" int isRectangle(Point lines[4]);
extern "C" double calculatePerimeter(Point lines[4]);
extern "C" double calculateArea(Point lines[4]);
extern "C" void connectCorners(Point points[4], Point corners[4]);

extern "C" char* calculateTriangleAngles(int side1, int side2, int side3, char* triangle);
extern "C" char* isTriangle(int side1, int side2, int side3);
extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C"  char* calculateTriangleAngles(int side1, int side2, int side3, char* triangle);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolyGonCheckerTest
{
	TEST_CLASS(PolyGonCheckerTest)
	{
	public:
		//testing the functionality isRectangle
		TEST_METHOD(isRectangle_Test1) {
			Point lines[4] = { {0, 0}, {0, 1}, {1, 1}, {1, 0} };
			int result = isRectangle(lines);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(isRectangle_Test2) {
			Point lines[4] = { {2, 4}, {3, 3}, {1, 1}, {0, 2} };
			int result = isRectangle(lines);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(isRectangle_Test3) {
			Point lines[4] = { { -10, 10 }, { 10, 10 }, { 10, -10 }, { -10, -10 } };
			int result = isRectangle(lines);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(isRectangle_Test4) {
			Point lines[4] = { {1, 4}, {4, 4}, {4, 2}, {1, 2} };
			int result = isRectangle(lines);
			Assert::IsTrue(1 == result);
		}
		TEST_METHOD(isRectangle_Test5) {
			Point lines[4] = { {0, 0}, {-7, 0}, {-7, -4}, {0, -4} };
			int result = isRectangle(lines);
			Assert::AreEqual(1, result);
		}


		//testing the functionality calculateDistance
		TEST_METHOD(Distance_Test1)
		{
			Point p1 = { 0, 0 };
			Point p2 = { 3, 4 };
			double result = calculateDistance(p1, p2);
			Assert::AreEqual(result, 5.0);
		}
		TEST_METHOD(Distance_Test2)
		{
			Point p1 = { -2, 3 };
			Point p2 = { 4,-5 };
			double result = calculateDistance(p1, p2);
			Assert::AreEqual(result, 10.0);
		}
		TEST_METHOD(Distance_Test4)
		{
			Point p1 = { 2, -3 };
			Point p2 = { 5, 1 };
			double result = calculateDistance(p1, p2);
			Assert::AreEqual(result, 5.0);
		}
		TEST_METHOD(Distance_Test5)
		{
			Point p1 = { 0, 0 };
			Point p2 = { 36, 15 };
			double result = calculateDistance(p1, p2);
			Assert::AreEqual(result, 39.0);
		}
		//testing the functionality calculatePerimeter
		TEST_METHOD(Perimeter_Test1) {
			Point lines[4] = { {12, 5}, {12, 0}, {0, 0}, {0, 5} };
			double perimeter = calculatePerimeter(lines);
			Assert::IsTrue(34.0 == perimeter);
		}
		TEST_METHOD(Perimeter_Test2) {
			Point lines[4] = { {0, 0}, {-7, 0}, {-7, -4}, {0, -4} };
			double perimeter = calculatePerimeter(lines);
			Assert::AreEqual(22.0, perimeter);
		}
		TEST_METHOD(Perimeter_Test3) {
			Point lines[4] = { {-10, 10}, {10, 10}, {10, -10}, {-10, -10} };
			double perimeter = calculatePerimeter(lines);
			Assert::AreEqual(80.00, perimeter);
		}
		TEST_METHOD(Perimeter_Test4) {
			Point lines[4] = { {-2, 2}, {5, 2}, {5, -1}, {-2, -1} };
			double perimeter = calculatePerimeter(lines);
			Assert::AreEqual(20.0, perimeter);
		}
		TEST_METHOD(Perimeter_Test5) {
			Point lines[4] = { {1, 4}, {4, 4}, {4, 2}, {1, 2} };
			double perimeter = calculatePerimeter(lines);
			Assert::AreEqual(10.0, perimeter);
		}


		//testing the functionality calculateArea
		TEST_METHOD(Area_Test1) {
			Point lines[4] = { {0, 0}, {6, 0}, {6, 5}, {0, 5} };
			double Area = calculateArea(lines);
			Assert::AreEqual(30.0, Area);
		}
		TEST_METHOD(Area_Test2) {
			Point lines[4] = { {-2, 2}, {5, 2}, {-2, -1}, {5,-1} };
			double Area = calculateArea(lines);
			Assert::AreNotEqual(21.0, Area);
		}

		TEST_METHOD(Area_Test3) {
			Point lines[4] = { {12, 5}, {12, 0}, {0, 0}, {0, 5} };
			double Area = calculateArea(lines);
			Assert::IsTrue(60.0 == Area);
		}
		TEST_METHOD(Area_Test4) {
			Point lines[4] = { {0, 4}, {5, 4}, {2, 0}, {-3,0 } };
			double Area = calculateArea(lines);
			Assert::AreEqual(25.0, Area);
		}	
		TEST_METHOD(Area_Test5) {
			Point lines[4] = { {0, 4}, {5, 4}, {2, 0}, {-3,0 } };
			double Area = calculateArea(lines);
			Assert::AreEqual(25.0, Area);
		}
		//testing the functionality connect corners
	  		TEST_METHOD(Connect_Corners_Test1) {
			Point points[4] = { {1, 2}, {3, 4}, {5, 6}, {7, 8} };
			Point expectedCorners[4] = { {1, 2}, {3, 4}, {7, 8}, {5, 6} };

			connectCorners(points, expectedCorners);

			for (int i = 0; i < 4; ++i) {
				Assert::IsFalse(points == expectedCorners);
				
			}
		}
			TEST_METHOD(Connect_Corners_Test2) {
				Point points[4] = { {0, 0}, {0, 1}, {1, 1}, {1, 0} };
				Point expectedCorners[4] = { {0, 0}, {1, 1}, {1,0}, {1, 1} };

				connectCorners(points, expectedCorners);

				for (int i = 0; i < 4; ++i) {
					Assert::IsFalse(points == expectedCorners);

				}
			}
			TEST_METHOD(Connect_Corners_Test3) {
				Point points[4] = { {1, 4}, {4, 4}, {4, 2}, {1, 2} };
				Point expectedCorners[4] = { {1, 4}, {4, 4}, {1, 2}, {4, 2} };

				connectCorners(points, expectedCorners);

				for (int i = 0; i < 4; ++i) {
					Assert::IsFalse(points == expectedCorners);

				}
			}
			TEST_METHOD(Connect_Corners_Test4) {
				Point points[4] = { {0, 0}, {-7, 0}, {-7, -4}, {0, -4} };
				Point expectedCorners[4] = { {0, 0}, {-7,0}, {0, -4}, {-7, -4} };

				connectCorners(points, expectedCorners);

				for (int i = 0; i < 4; ++i) {
					Assert::IsFalse(points == expectedCorners);

				}
			}
			TEST_METHOD(Connect_Corners_Test5) {
				Point points[4] = { {0, 4}, {5, 4}, {2, 0}, {-3,0 } };
				Point expectedCorners[4] = { {0, 4}, {5, 4}, {-3, 0}, {2, 0} };

				connectCorners(points, expectedCorners);

				for (int i = 0; i < 4; ++i) {
					Assert::IsFalse(points == expectedCorners);

				}
			}
		
		};
		TEST_CLASS(TriangleValidation) //this class is testing the validity of the triangles function
		{
		public:
			TEST_METHOD(InvaildTriangle)
			{
				char* result = isTriangle(100, 1, 12);
				Assert::AreEqual("The three sides do not make a valid triangle", result);

			}
			TEST_METHOD(InvaildTriangle2)
			{
				char* result = isTriangle(13, 1, 1000);
				Assert::AreEqual("The three sides do not make a valid triangle", result);

			}
			TEST_METHOD(InvaildTriangle3)
			{
				char* result = isTriangle(1000, 0, 0);
				Assert::AreEqual("The three sides do not make a valid triangle", result);

			}
			TEST_METHOD(InvaildTriangle4)
			{
				char* result = isTriangle(0, 0, 0);
				Assert::AreEqual("The three sides do not make a valid triangle", result);

			}
			TEST_METHOD(InvaildTriangle5)
			{
				char* result = isTriangle(1, 0, 1);
				Assert::AreEqual("The three sides do not make a valid triangle", result);

			}
			TEST_METHOD(VaildTriangle)
			{
				char* result = isTriangle(1, 1, 1);
				Assert::AreEqual("The three sides make a valid triangle", result);

			}
			TEST_METHOD(VaildTriangle2)
			{
				char* result = isTriangle(1, 1, 1);
				Assert::AreEqual("The three sides make a valid triangle", result);

			}
			TEST_METHOD(VaildTriangle3)
			{
				char* result = isTriangle(4, 5, 3);
				Assert::AreEqual("The three sides make a valid triangle", result);

			}
			TEST_METHOD(VaildTriangle4)
			{
				char* result = isTriangle(2, 2, 3);
				Assert::AreEqual("The three sides make a valid triangle", result);

			}
			TEST_METHOD(VaildTriangle5)
			{
				char* result = isTriangle(200, 200, 200);
				Assert::AreEqual("The three sides make a valid triangle", result);

			}
			
		};
		TEST_CLASS(TypeOfTriangle) { //this class is testing the type of triangle function
		public:
			TEST_METHOD(EquilateralTest1)
			{
				char* result1 = analyzeTriangle(4, 4, 4);
				Assert::AreEqual("Type: Equilateral triangle", result1);
			}
			TEST_METHOD(EquilateralTest2)
			{
				char* result1 = analyzeTriangle(10000, 10000, 10000);
				Assert::AreEqual("Type: Equilateral triangle", result1);
			}
			TEST_METHOD(EquilateralTest3)
			{
				char* result1 = analyzeTriangle(90, 90, 90);
				Assert::AreEqual("Type: Equilateral triangle", result1);
			}
			TEST_METHOD(IsoscelesTest1)
			{
				char* result1 = analyzeTriangle(2, 2, 3);
				Assert::AreEqual("Type: Isosceles triangle", result1);
			}
			TEST_METHOD(IsoscelesTest2)
			{
				char* result1 = analyzeTriangle(2, 3, 2);
				Assert::AreEqual("Type: Isosceles triangle", result1);
			}
			TEST_METHOD(IsoscelesTest3)
			{
				char* result1 = analyzeTriangle(3, 2, 2);
				Assert::AreEqual("Type: Isosceles triangle", result1);
			}
			TEST_METHOD(ScaleneTest1)
			{
				char* result1 = analyzeTriangle(5, 3, 4);
				Assert::AreEqual("Type: Scalene triangle", result1);
			}
			TEST_METHOD(ScaleneTest2)
			{
				char* result1 = analyzeTriangle(5, 4, 3);
				Assert::AreEqual("Type: Scalene triangle", result1);
			}
			TEST_METHOD(ScaleneTest3)
			{
				char* result1 = analyzeTriangle(3, 4, 5);
				Assert::AreEqual("Type: Scalene triangle", result1);
			}
			TEST_METHOD(NegativeSideLengths1)
			{
				char* result1 = analyzeTriangle(-900, -90, -9);
				Assert::AreEqual("Not a triangle", result1);
			}
			TEST_METHOD(NegativeSideLengths2)
			{
				char* result1 = analyzeTriangle(0, 0, 0);
				Assert::AreEqual("Not a triangle", result1);
			}
			TEST_METHOD(NegativeSideLengths3)
			{
				char* result1 = analyzeTriangle(-1, 0, 1);
				Assert::AreEqual("Not a triangle", result1);
			}
		};
		TEST_CLASS(TriangleAngles) //this class is testing the angles of triangle function
		{
		public:
			TEST_METHOD(Triangleanglestest001)
			{
				char* result = calculateTriangleAngles(6, 6, 6, "The three sides make a valid triangle");
				Assert::AreEqual("These side lengths form a triangle with angles: 60.00, 60.00, 60.00 (degrees)", result);
			}

			TEST_METHOD(Triangleanglestest002)
			{
				char* result = calculateTriangleAngles(3, 3, 3, "The three sides make a valid triangle");
				Assert::AreEqual("These side lengths form a triangle with angles: 60.00, 60.00, 60.00 (degrees)", result);
			}

			TEST_METHOD(Triangleanglestest003)
			{
				char* result = calculateTriangleAngles(4, 6, 5, "The three sides make a valid triangle");
				Assert::AreEqual("These side lengths form a triangle with angles: 41.41, 82.82, 55.77 (degrees)", result);
			}
			TEST_METHOD(Triangleanglestest004)
			{
				char* result = calculateTriangleAngles(6, 8, 10, "The three sides make a valid triangle");
				Assert::AreEqual("These side lengths form a triangle with angles: 36.87, 53.13, 90.00 (degrees)", result);
			}
			TEST_METHOD(Triangleanglestest005)
			{
				char* result = calculateTriangleAngles(3, 5, 7, "The three sides make a valid triangle");
				Assert::AreEqual("These side lengths form a triangle with angles: 21.79, 38.21, 120.00 (degrees)", result);
			}
			TEST_METHOD(Triangleanglestest006)
			{
				char* result = calculateTriangleAngles(6, 8, 10, "The three sides make a valid triangle");
				Assert::AreEqual("These side lengths form a triangle with angles: 36.87, 53.13, 90.00 (degrees)", result);
			}
			TEST_METHOD(Triangleanglestest007)
			{
				char* triangle = "The three sides do not make a valid triangle\nCould not form angles from a non-existent triangle.";
				char* result = calculateTriangleAngles(6, 5, 14, triangle);
				Assert::AreEqual("The three sides do not make a valid triangle\nCould not form angles from a non-existent triangle.", result);
			}
		};
	}
	