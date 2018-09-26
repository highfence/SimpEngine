#pragma once

#include <memory>
#include "Result.h"

namespace SimpEngineLib
{
	class Timer;
	class EngineWindow;

	class SimpEngine
	{
	public:

		SimpEngine();
		~SimpEngine();

		SimpResult InitEngine(HINSTANCE hInstance, int cmdShow);

		void Run();

	private:

		HINSTANCE m_WinInstance = NULL;
		int m_CmdShow;

		std::unique_ptr<Timer> m_Timer;
		std::unique_ptr<EngineWindow> m_EngineWindow;

	};
}
