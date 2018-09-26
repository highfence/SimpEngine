#include <Windows.h>
#include "../SimpEngineLib/SimpEngine.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	using namespace SimpEngineLib;

	SimpEngine a;
	a.InitEngine(hInstance, nCmdShow);

	return 0;
}