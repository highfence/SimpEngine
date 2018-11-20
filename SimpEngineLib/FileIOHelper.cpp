#include "stdafx.h"
#include "FileIOHelper.h"

namespace SimpEngine
{
	std::wstring FileIOHelper::GetFileBuffer(const std::wstring& filePath)
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
