#include "CppUnitTest.h"
#include "CSVParser.h"
#include <list>
#include <functional>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace DataExtractorUtilsTests
{		
	TEST_CLASS(CSVParserTests)
	{
	public:
		
		TEST_METHOD(ParseUIntList_ParseEmptyString)
		{
			CSVParser csv;
			list<unsigned int> list1;
			Assert::IsTrue(csv.ParseUIntList("", list1));
			Assert::AreEqual(static_cast<size_t>(0), list1.size());
		}

		TEST_METHOD(ParseUIntList_ParseOneValidNumber)
		{
			CSVParser csv;
			list<unsigned int> list1;
			Assert::IsTrue(csv.ParseUIntList("123", list1));
			Assert::AreEqual(static_cast<size_t>(1), list1.size());
			Assert::AreEqual(123u, list1.front());
		}
		
		TEST_METHOD(ParseUIntList_ParseOneValidNumberAndWithComma)
		{
			CSVParser csv;
			list<unsigned int> list1;
			Assert::IsTrue(csv.ParseUIntList("123,", list1));
			Assert::AreEqual(static_cast<size_t>(1), list1.size());
			Assert::AreEqual(123u, list1.front());
		}

		TEST_METHOD(ParseUIntList_ParseOneValidNumberAndWithCommaStartWithSpaces)
		{
			CSVParser csv;
			list<unsigned int> list1;
			Assert::IsTrue(csv.ParseUIntList("  123,", list1));
			Assert::AreEqual(static_cast<size_t>(1), list1.size());
			Assert::AreEqual(123u, list1.front());
		}

		TEST_METHOD(ParseUIntList_ParseOneValidNumberAndWithCommaStartAndEndWithSpaces)
		{
			CSVParser csv;
			list<unsigned int> list1;
			Assert::IsTrue(csv.ParseUIntList("  123  ,  ", list1));
			Assert::AreEqual(static_cast<size_t>(1), list1.size());
			Assert::AreEqual(123u, list1.front());
		}
		
		TEST_METHOD(ParseUIntList_ParsTwoValidNumber)
		{
			CSVParser csv;
			list<unsigned int> list1;
			Assert::IsTrue(csv.ParseUIntList("123, 456", list1));
			Assert::AreEqual(static_cast<size_t>(2), list1.size());
			Assert::AreEqual(123u, list1.front()); 
			Assert::AreEqual(456u, list1.back());
		}

		TEST_METHOD(ParseUIntList_ParsOneInvalidNumber)
		{
			CSVParser csv;
			list<unsigned int> list1;  
			Assert::IsFalse(csv.ParseUIntList("123, 4a5", list1));
		}
	};
}