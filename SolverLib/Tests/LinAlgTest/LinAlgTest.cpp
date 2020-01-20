#include "pch.h"
#include "CppUnitTest.h"
#include <vector.h>
#include <vertex.h>
#include <object_spec.h>
#include <polygon.h>

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

		TEST_METHOD(Polygon_test)
		{
			auto poly = polygon<double>::create_polygon({ {0.0,0.0,0.0},{1.0,0.0,0.0},{0.0,1.0,0.0} });

			
		}

	};

	
}
