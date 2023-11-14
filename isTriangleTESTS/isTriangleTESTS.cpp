#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* calculateTriangleAngles(int side1, int side2, int side3, char* triangle);
extern "C" char* isTriangle(int side1, int side2, int side3);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace isTriangleTESTS
{
	TEST_CLASS(isTriangleTESTS)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char* result = isTriangle(100,1,12);
			Assert::AreEqual("The three sides do not make a valid triangle", result, "Test Pass!");
			
		}
	};
}
