#pragma once

namespace SimpEngineLib
{
	class DebugHelper
	{
	public:

		static std::wstring GetResultName(SimpResult result);
		static void CheckResult(SimpResult result);
	};
}
