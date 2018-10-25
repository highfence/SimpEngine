#include "stdafx.h"
#include "EngineWindow.h"

namespace SimpEngineLib
{
	
	EngineWindow::EngineWindow()
	{
	}


	EngineWindow::~EngineWindow()
	{
	}

	SimpResult EngineWindow::InitWindow(HINSTANCE windowInstance, int cmdShow)
	{
		m_WindowInst = windowInstance;
		m_CmdShow = cmdShow;

		return SimpResult::None;
	}

	SimpResult EngineWindow::ShowWindow(const int width, const int height)
	{
		return SimpResult::None;
	}

	void EngineWindow::Update(const float dt)
	{

	}
}
