#include "pch.h"
#include "CppUnitTest.h"
#include "../7.3(it)/7.3(it).cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int S, K, number = 1;
			int** a = new int* [3];
			for (int i = 0; i < 3; i++)
			{
				a[i] = new int[3];
			}
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					a[i][j] = number++;
				}
			}
			int maxSum = INT_MIN;
			findMaxDiagonalSum(a, 3, 3, maxSum);
			Assert::AreEqual(maxSum, 15);

			for (int i = 0; i < 3; i++)
			{
				delete[] a[i];
			}
			delete[] a;
		}
	};
}
