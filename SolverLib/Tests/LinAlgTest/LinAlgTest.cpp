#include "pch.h"
#include "CppUnitTest.h"
#include <vector.h>
#include <vertex.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinAlgTests
{
	TEST_CLASS(Base_Objects_Tests)
	{
	public:
		
		TEST_METHOD(VectorTest)
		{
			vector<double> v(1.0,0.0,0.0);
			Assert::AreEqual(v.length(), 1.0);

		}

		TEST_METHOD(VertexTest)
		{
			vertex<double> v(1.0, 0.0, 0.0);
			Assert::AreEqual(v.z, 0.0);

		}
	};

	TEST_CLASS(Base_Objects_Tests_2)
	{
	public:

		TEST_METHOD(VectorTest)
		{
			vector<double> v(1.0, 0.0, 0.0);
			Assert::AreEqual(v.length(), 1.0);

		}

		TEST_METHOD(VertexTest)
		{
			vertex<double> v(1.0, 0.0, 0.0);
			Assert::AreEqual(v.z, 0.0);

		}
	};
}
