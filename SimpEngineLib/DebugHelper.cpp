#include "stdafx.h"
#include "DebugHelper.h"
#include <intrin.h>

namespace SimpEngine
{
	std::wstring DebugHelper::GetResultName(SimpResult result)
	{
		switch (result)
		{
		case SimpResult::None :
			return std::wstring(TEXT("None"));

		case SimpResult::ConfigFileOpenFailed :
			return std::wstring(TEXT("Can't open config file."));

		default :
			return std::wstring(TEXT("Undefined result enum"));
		}
	}

	void DebugHelper::CheckResult(SimpResult result)
	{
		if (result == SimpResult::None)
			return;

		std::wstring resultName = GetResultName(result);
		std::wstring boxText = TEXT("Error! Result : ");
		boxText.append(resultName);

		const TCHAR* errorMsg = boxText.c_str();
		const TCHAR* caption = TEXT("Error!");

		MessageBox(NULL, errorMsg, caption, MB_OK);

		__debugbreak();
	}
}
