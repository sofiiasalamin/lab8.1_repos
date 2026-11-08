#include "pch.h"
#include "CppUnitTest.h"
#include <sstream>
#include "../8,1it/8.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsIterative
{
    
    string ChangeToString(const char* s)
    {
        char* res = Change(s);
        string result(res);
        delete[] res;
        return result;
    }

    TEST_CLASS(CountPairsTests)
    {
    public:

        TEST_METHOD(CountPairs_LowerCaseIgnored)
        {
            Assert::AreEqual(0, CountPairs("sqqs"));
        }
    };

    TEST_CLASS(HasPairTests)
    {
    public:

        TEST_METHOD(HasPair_True_SQ)
        {
            Assert::IsTrue(HasPair("ASQB"));
        }
              
        TEST_METHOD(HasPair_False_EmptyString)
        {
            Assert::IsFalse(HasPair(""));
        }
    };

    TEST_CLASS(ChangeTests)
    {
    public:

        
        TEST_METHOD(Change_LowerCaseIgnored)
        {
            Assert::AreEqual(string("sqqs"), ChangeToString("sqqs"));
        }

        TEST_METHOD(Change_DoesNotModifySource)
        {
            char str[] = "ASQB";
            char* res = Change(str);
            delete[] res;
            Assert::AreEqual(string("ASQB"), string(str));
        }
    };
}