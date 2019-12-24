#include "pch.h"
#include "CppUnitTest.h"
#include <vector.h>
#include <vertex.h>
#include <object_spec.h>

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

		TEST_METHOD(Ref_Class_Test)
		{
			class p :public object_spec<float, true>
			{
				REGISTER_REF_CONSTRUCTOR_BEGIN(p,float a, int b)

			};

		}

	};

	
}
