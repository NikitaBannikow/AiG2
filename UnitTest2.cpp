#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../Aistrd2LabBannikov/Header.h"
#include "\Users\Никита\source\repos\Aistrd2LabBannikov\Aistrd2LabBannikov\functions.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		int arrl;

		TEST_METHOD_INITIALIZE(setUp)
		{
			arrl = 10;
		}

		TEST_METHOD_CLEANUP(cleanUP)
		{

		}

		TEST_METHOD(quick_sort)
		{
			Array test(arrl);
			int test_fill[10] = { 1,2,3,4,5,6,7,8,9,10 };

			Array arr(arrl);
			int test_arr[10] = { 1,3,2,7,5,6,4,8,9,10 };

			arr.quicksorting(0, 9);

			for (int i = 0; i < arrl; i++)
			{
				Assert::AreEqual(arr.getelem(i), test.getelem(i));
			}

		}

		TEST_METHOD(bubble_sort)
		{
			Array test(arrl);
			int test_fill[10] = { 1,2,3,4,5,6,7,8,9,10 };
			Array arr(arrl);
			int test_arr[10] = { 1,3,2,7,5,6,4,8,9,10 };

			arr.bubblesorting();

			for (int i = 0; i < arrl; i++)
			{
				Assert::AreEqual(arr.getelem(i), test.getelem(i));
			}

		}

		TEST_METHOD(bogo_sort)
		{
			Array test(arrl);
			int test_fill[10] = { 1,2,3,4,5,6,7,8,9,10 };

			Array arr(arrl);
			int test_arr[10] = { 1,3,2,7,5,6,4,8,9,10 };

			arr.bogosorting();

			for (int i = 0; i < arrl; i++)
			{
				Assert::AreEqual(arr.getelem(i), test.getelem(i));
			}

		}

		TEST_METHOD(counting_sort)
		{
			Char_Array test(arrl);
			int test_fill[10] = { 1,2,3,4,5,6,7,8,9,10 };

			Char_Array arr(arrl);
			int test_arr[10] = { 1,3,2,7,5,6,4,8,9,10 };

			arr.countingsorting();

			for (int i = 0; i < arrl; i++)
			{
				Assert::AreEqual(arr.getelem(i), test.getelem(i));
			}

		}

	};
}

