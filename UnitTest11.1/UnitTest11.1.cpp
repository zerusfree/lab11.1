#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest111
{
	TEST_CLASS(UnitTest111)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			ofstream tempFile("temp.bin", ios::binary);
			string testData = "askod2doaed3";
			tempFile.write(testData.c_str(), testData.size());
			tempFile.close();

			// Викликаємо функцію, що ми тестуємо
			ProcessBIN1("temp.bin", "result.bin");

			// Перевіряємо результат
			ifstream resultFile("result.bin", ios::binary);
			string expectedResult = "dd";
			string actualResult;
			char c;
			while (resultFile.read(&c, sizeof(c)))
			{
				actualResult += c;
			}
			Assert::AreEqual(expectedResult, actualResult);
			resultFile.close();

		}
	};
}
