#include "stdafx.h"
#include <shellapi.h>
#include "EngineConfig.h"
#include "SimpEngine.h"

namespace SimpEngine
{
	SimpEngine::SimpEngine(HINSTANCE hInstance, int cmdShow)
		: m_WinInstance(hInstance), m_CmdShow(cmdShow)
	{
	}

	SimpEngine::~SimpEngine()
	{
	}

	SimpResult SimpEngine::InitEngine()
	{
		auto configInitResult = InitEngineConfig();
		DebugHelper::CheckResult(configInitResult);

		auto windowInitResult = InitEngineWindow();
		DebugHelper::CheckResult(windowInitResult);

		auto rendererInitResult = InitRenderer();
		DebugHelper::CheckResult(rendererInitResult);

		m_Timer = std::make_unique<Timer>();
		m_Timer->InitTimer();

		return SimpResult::None;
	}

	constexpr float timePerFrame = 1.f / 60.f;
	void SimpEngine::Run()
	{
		static float accTime = 0.f;

		m_Timer->ProcessTime();
		MSG msg;

		while (true)
		{
			accTime += m_Timer->GetElapsedTime();
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT)
					break;

				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				if (accTime >= timePerFrame)
				{
					m_EngineWindow->Update(accTime);
					accTime = 0.f;
				}
			}
		}
	}

	SimpResult SimpEngine::InitEngineConfig()
	{
		LPWSTR* argList;
		int argCount;

		argList = CommandLineToArgvW(GetCommandLine(), &argCount);

		std::vector<std::wstring> args;
		for (int i = 0; i < argCount; ++i)
		{
			if (argList[i] == nullptr)
				continue;

			args.push_back(argList[i]);
		}

		m_Config = std::make_unique<EngineConfig>();
		return m_Config->LoadConfig(args);
	}

	SimpResult SimpEngine::InitEngineWindow()
	{
		m_EngineWindow = std::make_unique<EngineWindow>();

		return m_EngineWindow->InitWindow(m_WinInstance, m_CmdShow);
	}

	SimpResult SimpEngine::InitRenderer()
	{


		return SimpResult::None;
	}
}
