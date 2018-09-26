#include "stdafx.h"
#include "SimpEngine.h"

namespace SimpEngineLib
{
	SimpEngine::SimpEngine()
	{
	}


	SimpEngine::~SimpEngine()
	{
	}

	SimpResult SimpEngine::InitEngine(HINSTANCE hInstance, int cmdShow)
	{
		DebugHelper::CheckResult((SimpResult)1);

		m_WinInstance = hInstance;
		m_CmdShow = cmdShow;

		m_Timer = std::make_unique<Timer>();
		m_Timer->InitTimer();

		m_EngineWindow = std::make_unique<EngineWindow>();

		return SimpResult::None;
	}

	void SimpEngine::Run()
	{
	}
}
