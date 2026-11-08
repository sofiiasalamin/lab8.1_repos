#include "pch.h"
#include "CppUnitTest.h"
#include "../8.1char/8.1char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81char
{
	TEST_CLASS(UnitTest81char)
	{
	public:

		
		TEST_METHOD(FindPair_PairAtStart)
		{
			char s[] = "SQabc";
			Assert::IsTrue(FindPair(s) == s);
		}
											
		TEST_METHOD(Change_AdjacentPairs)
		{
			char s[50] = "SQQS";
			char* t = Change(s);
			Assert::AreEqual("******", s);
			Assert::AreEqual("******", t);
			delete[] t;
		}
				
		TEST_METHOD(Change_ParamAndResultAreEqual)
		{
			char s[50] = "xSQyQSz";
			char* t = Change(s);
			Assert::AreEqual(0, strcmp(s, t));
			delete[] t;
		}
	};
}