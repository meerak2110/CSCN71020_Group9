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
extern "C" void connectCorners(Point corners[4], Point lines[4]);

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
		


		};
	}
	