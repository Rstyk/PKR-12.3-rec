#include "pch.h"
#include "CppUnitTest.h"
#include "../PKR_lab_12.3.rec/PKR_lab_12.3.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Node* head = nullptr;
			Node* tail = nullptr;


			head = new Node{ 1 };
			head->next = new Node{ 2 };
			head->next->next = new Node{ 2 }; // Pair
			head->next->next->next = new Node{ 3 };
			tail = head->next->next->next;


			Pairs(head);

		}
	};
}
