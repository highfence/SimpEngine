#include "stdafx.h"
#include "ConfigParamParser.h"
#include "EngineConfig.h"

namespace SimpEngine
{
	ConfigParamParser::ConfigParamParser()
	{
		RegistParsingFunctions();
	}

	ConfigParamParser::~ConfigParamParser()
	{
	}

	void ConfigParamParser::ParseParam(EngineConfig * config, std::wstring& param)
	{
		if (config == nullptr)
			return;

		const int equalSignIdx = param.find(TEXT("="));
		std::wstring paramNameString = param.substr(0, equalSignIdx);
		std::wstring paramValue = param.substr(equalSignIdx + 1);

		ConfigParamName paramName = GetConfigNameFromString(paramNameString);

		if (m_ParseFunctions.find(paramName) != m_ParseFunctions.end())
		{
			ParseConfigFunction func = m_ParseFunctions[paramName];
			func(config, paramValue);
		}
	}

	void ConfigParamParser::RegistParsingFunctions()
	{
		m_ParseFunctions.emplace(ConfigParamName::ConfigFilePath, std::bind(&ConfigParamParser::ParseConfigFilePath, this, std::placeholders::_1, std::placeholders::_2));
		m_ParseFunctions.emplace(ConfigParamName::LogFilePath, std::bind(&ConfigParamParser::ParseLogFilePath, this, std::placeholders::_1, std::placeholders::_2));
	}

	void ConfigParamParser::ParseConfigFilePath(EngineConfig* config, std::wstring& paramValue)
	{
		if (config == nullptr)
			return;

		config->m_ConfigPath = paramValue;
	}

	void ConfigParamParser::ParseLogFilePath(EngineConfig* config, std::wstring& paramValue)
	{
		if (config == nullptr)
			return;

		config->m_LogPath = paramValue;
	}

	ConfigParamName ConfigParamParser::GetConfigNameFromString(std::wstring& paramString)
	{
		for (INT i = static_cast<int>(ConfigParamName::None); i < static_cast<int>(ConfigParamName::ConfigParamCount); ++i)
		{
			std::wstring typeString = GetConfigNameToString(static_cast<ConfigParamName>(i));
			if (paramString.compare(typeString) == 0)
				return static_cast<ConfigParamName>(i);
		}

		return ConfigParamName::None;
	}

	std::wstring ConfigParamParser::GetConfigNameToString(ConfigParamName configType)
	{
		switch (configType)
		{
		case ConfigParamName::ConfigFilePath :
			return std::wstring(TEXT("ConfigFilePath"));

		case ConfigParamName::LogFilePath:
			return std::wstring(TEXT("LogFilePath"));

		case ConfigParamName::None :
		default :
			return std::wstring(TEXT("None"));
		}
	}
}
