#include <Windows.h>
#include "../SimpEngineLib/SimpEngine.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	using namespace SimpEngineLib;

	SimpEngine engineInstance(hInstance, nCmdShow);
	engineInstance.InitEngine();

	return 0;
}