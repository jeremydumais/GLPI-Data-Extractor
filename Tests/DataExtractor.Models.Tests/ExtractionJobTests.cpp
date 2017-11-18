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

		TEST_METHOD(CopyConstructorTest1)
		{
			ExtractionJob job("Job1");
			job.addTicketId(123);
			ExtractionJob job2(job);
			//Change/remove first job values
			job.setName("test");
			job.clearTickets();

			Assert::AreEqual("test", job.getName().c_str());
			Assert::AreEqual(static_cast<size_t>(0), job.getTicketsCount());
			Assert::AreEqual("Job1", job2.getName().c_str());
			Assert::AreEqual(static_cast<size_t>(1), job2.getTicketsCount());
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

		TEST_METHOD(GetTicketCountZero)
		{
			ExtractionJob job("Job");
			Assert::AreEqual(static_cast<size_t>(0), job.getTicketsCount());
		}

		TEST_METHOD(AddOneTicketToJob)
		{
			ExtractionJob job("Job");
			job.addTicketId(12345);
			Assert::AreEqual(static_cast<size_t>(1), job.getTicketsCount());
		}

		TEST_METHOD(AddTwoTicketsToJob)
		{
			ExtractionJob job("Job");
			job.addTicketId(12344);
			Assert::AreEqual(static_cast<size_t>(1), job.getTicketsCount()); 
			job.addTicketId(12345);
			Assert::AreEqual(static_cast<size_t>(2), job.getTicketsCount());
		}

		TEST_METHOD(AddDuplicateTicketToJob)
		{
			ExtractionJob* job = new ExtractionJob("Job");
			job->addTicketId(12345);
			function<void()> f1 = [job] { job->addTicketId(12345); };
			Assert::ExpectException<invalid_argument>(f1);
		}

		TEST_METHOD(RemoveValidTicketFromAList)
		{
			ExtractionJob job("Job");
			job.addTicketId(12344);
			job.addTicketId(12345);
			job.removeTicketId(12344);
			Assert::AreEqual(static_cast<size_t>(1), job.getTicketsCount());
		}

		TEST_METHOD(RemoveInvalidTicketFromAList)
		{
			ExtractionJob* job = new ExtractionJob("Job");
			job->addTicketId(12345);
			function<void()> f1 = [job] { job->removeTicketId(12346); };
			Assert::ExpectException<invalid_argument>(f1);
		}
		
		TEST_METHOD(ClearEmptyList)
		{
			ExtractionJob job("Job");
			job.clearTickets();
			Assert::AreEqual(static_cast<size_t>(0), job.getTicketsCount());
		}

		TEST_METHOD(Clear2TicketList)
		{
			ExtractionJob job("Job");
			job.addTicketId(12344);
			job.addTicketId(12345);
			job.clearTickets();
			Assert::AreEqual(static_cast<size_t>(0), job.getTicketsCount());
		}
	};
}