#include "pch.h"
#include "CppUnitTest.h"
#include <sstream>
#include <cstring>
#include "../8,1rec/8.1rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsRecursive
{
    string ChangeToString(const char* s)
    {
        char* dest = new char[strlen(s) + Count(s, 0) + 1];
        dest[0] = '\0';
        string result(Change(dest, s, dest, 0));
        delete[] dest;
        return result;
    }

    TEST_CLASS(IsPairTests)
    {
    public:

        
        TEST_METHOD(IsPair_EndOfString)
        {
            Assert::IsFalse(IsPair('S', '\0'));
        }
    };

    TEST_CLASS(CountTests)
    {
    public:

       

        TEST_METHOD(Count_SQ)
        {
            Assert::AreEqual(1, Count("ASQB", 0));
        }

        TEST_METHOD(Count_QS)
        {
            Assert::AreEqual(1, Count("AQSB", 0));
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

        TEST_METHOD(Change_NoPairs)
        {
            Assert::AreEqual(string("ABC"), ChangeToString("ABC"));
        }

       

        TEST_METHOD(Change_OnlyPair_SQ)
        {
            Assert::AreEqual(string("***"), ChangeToString("SQ"));
        }

        
        

        TEST_METHOD(Change_DoesNotModifySource)
        {
            char str[] = "ASQB";
            char* dest = new char[strlen(str) + Count(str, 0) + 1];
            dest[0] = '\0';
            Change(dest, str, dest, 0);
            delete[] dest;
            Assert::AreEqual(string("ASQB"), string(str));
        }
    };

    
}