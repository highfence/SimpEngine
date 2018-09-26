#pragma once

namespace SimpEngineLib
{
	class EngineWindow
	{
	public:
		EngineWindow();
		~EngineWindow();

		SimpResult InitWindow(HINSTANCE windowInstance, int cmdShow);
		SimpResult ShowWindow(const int width, const int height);

	private :

		HINSTANCE m_WindowInst;
		int m_CmdShow;

	};
}