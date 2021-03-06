#pragma once

namespace SimpEngine
{
	class EngineWindow
	{
	public:
		EngineWindow();
		~EngineWindow();

		SimpResult InitWindow(HINSTANCE windowInstance, int cmdShow);
		SimpResult ShowWindow(const int width, const int height);

		void Update(const float dt);

	private :

		HINSTANCE m_WindowInst;
		int m_CmdShow;

	};
}