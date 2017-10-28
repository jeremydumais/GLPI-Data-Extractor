#include "CppUnitTest.h"
#include "ExtractionJob.h"
#include <stdexcept>
#include <functional>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace DataExtractorModelsTests
{		
	TEST_CLASS(ExtractionJobTests)
	{
	public:
		
		TEST_METHOD(ConstructorJobNameValid)
		{
			ExtractionJob job("Job1");
			Assert::AreEqual("Job1", job.getName().c_str());
			Assert::AreEqual(static_cast<size_t>(0), job.getTicketsCount());
		}

		TEST_METHOD(ConstructorJobNameEmpty)
		{
			try
			{
				ExtractionJob* job = new ExtractionJob("");
				Assert::Fail(L"Constructor should have fail");
			}
			catch (...) {}
		}

		TEST_METHOD(SetNameValid)
		{
			ExtractionJob job("Job");
			job.setName("Job1");
			Assert::AreEqual("Job1", job.getName().c_str());
			Assert::AreEqual(static_cast<size_t>(0), job.getTicketsCount());
		}

		TEST_METHOD(SetNameEmpty)
		{
			ExtractionJob* job = new ExtractionJob("Job");
			function<void()> f1 = [job] { job->setName(""); };
			Assert::ExpectException<invalid_argument>(f1);
		}

	};
}