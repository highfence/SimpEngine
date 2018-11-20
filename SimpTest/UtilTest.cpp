#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SimpEngineLib/FileIOHelper.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SimpTest
{		
	TEST_CLASS(SimpFileIOTest)
	{
	public:
		
		const std::wstring successFilePath = TEXT("../SimpTest/TestDatas/Test.json");
		const std::wstring failFilePath = TEXT("./TestDatas/dontExist.data");
		
		TEST_METHOD(FileOpenFailTest)
		{
			std::wstring fileBuf = SimpEngine::FileIOHelper::GetFileBuffer(failFilePath);
			int fileLength = fileBuf.length();
			
			Assert::AreEqual(fileLength, 0);
		}

		TEST_METHOD(FileOpenSuccessTest)
		{
			std::wstring fileBuf = SimpEngine::FileIOHelper::GetFileBuffer(successFilePath);
			int fileLength = fileBuf.length();

			Assert::AreNotEqual(fileLength, 0);
		}
	};
}