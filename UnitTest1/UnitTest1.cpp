#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab 1.4\records.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			records p;
			p.Init("Козак Василь", "Водій", 5);
			Assert::AreEqual(p.getPosition(), string("Водій"));
		}
	};
}
