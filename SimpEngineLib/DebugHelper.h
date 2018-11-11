#pragma once

namespace SimpEngine
{
	class DebugHelper
	{
	public:

		static std::wstring GetResultName(SimpResult result);
		static void CheckResult(SimpResult result);
	};
}
