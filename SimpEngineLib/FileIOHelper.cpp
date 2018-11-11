#include "stdafx.h"
#include "FileIOHelper.h"

namespace SimpEngine
{
	std::wstring FileIOHelper::GetFileBuffer(std::wstring& filePath)
	{
		wchar_t* buffer;
		std::wifstream fileStream(filePath);

		if (fileStream.is_open() == false)
			return buffer;

		fileStream.seekg(0, std::ios::end);
		auto fileLength = fileStream.tellg();
		buffer = new wchar_t(fileLength);
		fileStream.seekg(0);
		fileStream.read(buffer, fileLength);

		return std::wstring(buffer);
	}
}
