#include "stdafx.h"
#include "FileIOHelper.h"

namespace SimpEngine
{
	// Todo : 잘 작동하나 테스트 해보자. 너무 오랜만에 wchar_t를 썼다. 메모리 해제가 잘 되는지?
	std::wstring FileIOHelper::GetFileBuffer(std::wstring& filePath)
	{
		std::wifstream fileStream(filePath);

		if (fileStream.is_open() == false)
			return std::wstring(TEXT(""));

		fileStream.seekg(0, std::ios::end);
		auto fileLength = fileStream.tellg();
		wchar_t* buffer = new wchar_t(fileLength);
		fileStream.seekg(0);
		fileStream.read(buffer, fileLength);
		
		std::wstring stringBuffer = std::wstring(buffer);
		delete[] buffer;

		return stringBuffer;
	}
}
