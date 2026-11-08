#include "pch.h"
#include "CppUnitTest.h"
#include "../8.1string/8.1string.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81string
{
	TEST_CLASS(UnitTest81string)
	{
	public:

		

		TEST_METHOD(Change_SQReplaced)
		{
			string s = "ASQB";
			string t = Change(s);
			Assert::AreEqual(string("A***B"), s);
			Assert::AreEqual(string("A***B"), t);
		}
				
		TEST_METHOD(Change_SeveralPairs)
		{
			string s = "SQxQSySQ";
			string t = Change(s);
			Assert::AreEqual(string("***x***y***"), s);
			Assert::AreEqual(string("***x***y***"), t);
		}

		

		TEST_METHOD(Change_ParamAndResultAreEqual)
		{
			string s = "xSQyQSz";
			string t = Change(s);
			Assert::AreEqual(s, t);
		}
	};
}