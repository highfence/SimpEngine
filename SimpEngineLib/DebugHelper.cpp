#include "stdafx.h"
#include "DebugHelper.h"
#include <intrin.h>

namespace SimpEngineLib
{
	std::wstring DebugHelper::GetResultName(SimpResult result)
	{
		switch (result)
		{
		case SimpResult::None :
			return std::wstring(TEXT("None"));

		default :
			return std::wstring(TEXT("Undefined result enum"));
		}
	}

	void DebugHelper::CheckResult(SimpResult result)
	{
		if (result != SimpResult::None)
		{
			std::wstring resultName = GetResultName(result);
			std::wstring boxText = TEXT("Error! Result : ");
			boxText.append(resultName);

			const TCHAR* errorMsg = boxText.c_str();
			const TCHAR* caption = TEXT("Error!");

			MessageBox(NULL, errorMsg, caption, MB_OK);

			__debugbreak();
		}
	}
}
