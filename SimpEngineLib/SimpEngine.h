#pragma once

#include <memory>
#include "Result.h"

namespace SimpEngine
{
	class Timer;
	class EngineWindow;
	class EngineConfig;
	__interface ISimpRenderer;

	class SimpEngine
	{
	public:

		SimpEngine() = delete;
		SimpEngine(HINSTANCE hInstance, int cmdSHow);
		~SimpEngine();

		SimpResult InitEngine();

		void Run();

	private:

		SimpResult InitEngineWindow();
		SimpResult InitRenderer();

		HINSTANCE m_WinInstance = NULL;
		int m_CmdShow;

		std::unique_ptr<Timer> m_Timer;
		std::unique_ptr<EngineWindow> m_EngineWindow;
		std::unique_ptr<ISimpRenderer> m_Renderer;
		std::unique_ptr<EngineConfig> m_Config;
	};
}
